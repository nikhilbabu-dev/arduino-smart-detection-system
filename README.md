# Arduino Smart Detection System

## Description
A simple Arduino-based automation project using ultrasonic sensor,
IR sensor, servo motor, relay module, and I2C LCD.

## Components Used
- Arduino Uno
- HC-SR04 Ultrasonic Sensor
- IR Sensor
- SG90 Servo Motor
- Relay Module
- 16x2 I2C LCD

## Connections
Ultrasonic TRIG -> D9  
Ultrasonic ECHO -> D10  
IR Sensor OUT -> D6  
Servo -> D5  
Relay -> D7  
LCD SDA -> A4  
LCD SCL -> A5  

## Working
The system measures distance and detects presence.
If distance < 20 cm and motion detected,
servo rotates and relay activates.
LCD shows real-time status.

## Learning Outcome
Sensor integration, I2C communication,
and actuator automation.
## Wiring Diagram
![Wiring Diagram](wiri![wiring jpeg](https://github.com/user-attachments/assets/3db60424-451b-4f8b-949c-e89a12972bff)
ng.png)

