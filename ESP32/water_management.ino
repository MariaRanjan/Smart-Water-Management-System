#include <ESP8266WiFi.h>//ESP8266 instead of esp32
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecure.h>


const char* ssid = "POCO M2 Pro";
const char* password = "12345678";

const char* host = "water-management-79ad2-default-rtdb.asia-southeast1.firebasedatabase.app";

#define PUMP D1
#define INLET D2
#define OUTLET D3
#define BUZZER D4


int tankLevel = 0;
int sumpLevel = 0;
float flowRate = 0;
int dryRun = 0;
int overflow = 0;
int alert = 0;

int fbGet(String path)
{
  WiFiClientSecure client;
  client.setInsecure();

  HTTPClient https;

  String url = String("https://") + host + path + ".json";

  https.begin(client, url);

  int httpCode = https.GET();
  int value = 0;

  if (httpCode > 0)
  {
    String payload = https.getString();
    payload.trim();

    Serial.print(path);
    Serial.print(" = ");
    Serial.println(payload);

    if (payload == "1") value = 1;
    else if (payload == "0") value = 0;
    else value = payload.toInt();
  }
  else
  {
    Serial.print("HTTP ERROR: ");
    Serial.println(path);
  }

  https.end();
  return value;
}

void fbSet(String path, String value)
{
  WiFiClientSecure client;
  client.setInsecure();

  HTTPClient https;

  String url = String("https://") + host + path + ".json";

  https.begin(client, url);
  https.addHeader("Content-Type", "application/json");

  https.PUT(value);

  https.end();
}

void setup()
{
  Serial.begin(9600);

  pinMode(PUMP, OUTPUT);
  pinMode(INLET, OUTPUT);
  pinMode(OUTLET, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  digitalWrite(PUMP, LOW);
  digitalWrite(INLET, LOW);
  digitalWrite(OUTLET, LOW);
  digitalWrite(BUZZER, LOW);

  WiFi.begin(ssid, password);

  Serial.print("Connecting WiFi");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi Connected");
}


void loop()
{

  if (Serial.available())
  {
    String data = Serial.readStringUntil('\n');
    Serial.println("STM32 RAW: " + data);
  }
  else
  {
    // imaginary fallback values
    tankLevel = 55;
    sumpLevel = 35;
    flowRate = 1.5;
    dryRun = 0;
    overflow = 0;
    alert = 0;
  }

  Serial.println("\n===== SYSTEM STATUS =====");
  Serial.print("Tank: "); Serial.println(tankLevel);
  Serial.print("Sump: "); Serial.println(sumpLevel);
  Serial.print("Flow: "); Serial.println(flowRate);
  Serial.print("Dry: "); Serial.println(dryRun);
  Serial.print("Overflow: "); Serial.println(overflow);


  digitalWrite(PUMP,   fbGet("/COMMAND/pump"));
  digitalWrite(INLET,  fbGet("/COMMAND/inletValve"));
  digitalWrite(OUTLET, fbGet("/COMMAND/outletValve"));
  digitalWrite(BUZZER, fbGet("/COMMAND/buzzer"));

  
  fbSet("/SENSORS/tankLevel", String(tankLevel));
  fbSet("/SENSORS/sumpLevel", String(sumpLevel));
  fbSet("/SENSORS/flowRate", String(flowRate));
  fbSet("/SENSORS/dryRun", String(dryRun));
  fbSet("/SENSORS/overflow", String(overflow));
  fbSet("/SENSORS/alert", String(alert));

  delay(500);
}
