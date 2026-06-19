💧 Smart Water Management System using STM32 + ESP32 + Firebase
📌 Project Overview

This project is an IoT-based Smart Water Management System designed using STM32 microcontroller and ESP32 NodeMCU with Firebase Realtime Database integration.
It enables real-time monitoring, automation, and remote control of a water distribution system.

The STM32 handles sensor reading and control logic, while the ESP32 acts as an IoT gateway for cloud communication.

🎯 Features
Real-time water level monitoring (Tank & Sump)
Flow rate measurement
Pump dry-run and overflow protection
Automatic pump and valve control
Firebase cloud integration
Remote control via Firebase commands
LED-based system status simulation
UART communication between STM32 and ESP32
🧠 System Architecture
STM32 (Controller Unit)
Reads sensors
Executes safety logic
Controls pump, valves, buzzer
ESP32 (IoT Gateway)
Receives data from STM32 via UART
Uploads data to Firebase
Reads Firebase commands
Controls LED outputs
Firebase Cloud
Stores sensor data
Sends control commands
Enables remote monitoring
📊 Monitored Parameters
Tank Level
Sump Level
Flow Rate
Pump Feedback
Dry Run Status
Overflow Status
Alert Status
⚙️ Control Parameters
Pump Command
Inlet Valve Command
Outlet Valve Command
Buzzer Command
Reset Fault Command
🔌 Hardware Used
STM32 (Blue Pill / equivalent)
ESP8266 / NodeMCU
Water level sensors
Flow sensor
Relay module
Buzzer
LEDs
Power supply
💻 Software Used
Arduino IDE
Firebase Realtime Database
STM32CubeIDE (optional)
Wokwi / Simulator (optional)
🔁 Working Principle
STM32 reads sensor data from water system
Data is sent to ESP32 via UART
ESP32 uploads data to Firebase
Firebase stores real-time values
User sends commands via Firebase
ESP32 reads commands and controls outputs
System runs continuously in loop
🔥 Firebase Database Structure
tankLevel
sumpLevel
flowRate
pumpFeedback
dryRunStatus
overflowStatus
alertStatus

pumpCommand
inletValveCommand
outletValveCommand
buzzerCommand
resetFaultCommand
📸 Outputs
Firebase Realtime Database Screenshot
Serial Monitor Output
System Working Video
Command Control Screenshots
🚀 Applications
Smart home water automation
Industrial water management
Smart irrigation systems
Building water monitoring systems
📈 Future Improvements
Mobile app integration
AI-based water prediction
Solar-powered system
Advanced sensor integration
Cloud analytics dashboard
