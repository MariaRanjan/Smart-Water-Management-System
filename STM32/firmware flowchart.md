                ┌──────────────┐
                │    START     │
                └──────┬───────┘
                       │
                       ▼
        ┌────────────────────────────┐
        │ Initialize STM32 & ESP32   │
        │ - GPIO Setup               │
        │ - UART Init               │
        │ - WiFi Connection         │
        │ - Firebase Init           │
        └────────────┬──────────────┘
                     │
                     ▼
        ┌────────────────────────────┐
        │ Read Sensors (STM32)       │
        │ - Tank Level              │
        │ - Sump Level              │
        │ - Flow Rate               │
        │ - Pump Feedback           │
        │ - Dry Run Status          │
        │ - Overflow Status         │
        └────────────┬──────────────┘
                     │
                     ▼
        ┌────────────────────────────┐
        │ Send Data via UART         │
        │ STM32 → ESP32             │
        └────────────┬──────────────┘
                     │
                     ▼
        ┌────────────────────────────┐
        │ ESP32 Receives Data        │
        │ Parse Sensor Values        │
        └────────────┬──────────────┘
                     │
                     ▼
        ┌────────────────────────────┐
        │ Upload Data to Firebase    │
        │ - tankLevel              │
        │ - sumpLevel              │
        │ - flowRate               │
        │ - pumpFeedback           │
        │ - fault status           │
        └────────────┬──────────────┘
                     │
                     ▼
        ┌────────────────────────────┐
        │ Read Firebase Commands     │
        │ - pumpCommand            │
        │ - inletValveCommand      │
        │ - outletValveCommand     │
        │ - buzzerCommand          │
        │ - resetFaultCommand      │
        └────────────┬──────────────┘
                     │
                     ▼
        ┌────────────────────────────┐
        │ Control Outputs (ESP32)    │
        │ - Pump LED               │
        │ - Inlet Valve LED        │
        │ - Outlet Valve LED       │
        │ - Buzzer LED             │
        │ - Fault LED              │
        └────────────┬──────────────┘
                     │
                     ▼
        ┌────────────────────────────┐
        │ Decision Logic (STM32)     │
        │ IF DryRun OR Overflow      │
        │ → Stop Pump               │
        │ → Trigger Alarm           │
        └────────────┬──────────────┘
                     │
                     ▼
                ┌──────────────┐
                │    LOOP      │
                └──────────────┘
