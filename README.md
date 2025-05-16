# Arduino-Water-System-Alert

An Arduino-based water level monitoring and alert system designed for water tanks. This system helps people easily track water levels in real-time and receive alerts when the tank is low or full — improving efficiency and reducing manual work.

##  Project Summary

This project uses an **ultrasonic sensor** to measure the water level inside a tank and displays the percentage on a **16x2 LCD display**. Visual indicators (LEDs) and an active buzzer are used to notify the farmer of the current status:

- ✅ Green LED – Low
- ⚠️ Yellow LED – Medium
- 🔴 Red LED + Buzzer – Full

## 📌 Features

- Real-time water level measurement (%)
- Status display on LCD
- Color-coded LED alerts
- Buzzer sound for low water warning
- Easy to install, low-cost, and farmer-friendly

## 📄 How It Works

1. The ultrasonic sensor detects the distance from the top of the tank to the water surface.
2. The distance is converted into a percentage based on tank height.
3. The system displays
4. LEDs and buzzer and I2C LCD alert.

## Hardware Components
- Arduino UNO**
- Ultrasonic Sensor (HC-SR04)**  
- 16x2 LCD Display with I2C**  
- Active Buzzer**  
- Red, Yellow, Green LEDs
- Wires
  
## Program Use For Coding
 - Arduino IDE

## Programming Language Used
 - Arduino (C/C++)
 - 
## This project was developed as part of the course:

Microcontrollers and Applications (CSS332-1)

Sirindhorn International Institute of Technology (SIIT)
Thammasat University
   
