# SimpleParkingSensor

A simple Arduino-based parking assistant that uses an HC-SR04 ultrasonic sensor to detect the distance of nearby obstacles. The measured distance is displayed on a 16x2 I2C LCD, and a buzzer gives audible alerts based on proximity.

---

## Features

- Ultrasonic distance measurement using HC-SR04
- Real-time display of distance on 16x2 I2C LCD
- Audible warning with buzzer (fast beeps for close objects)
- Low cost and easy to build

---

## Hardware Used

- Arduino Uno
- HC-SR04 ultrasonic sensor
- 16x2 LCD with I2C backpack
- Buzzer
- Jumper wires & breadboard

---

## Connections

| Component     | Arduino Pin |
|---------------|-------------|
| HC-SR04 TRIG  | D9          |
| HC-SR04 ECHO  | D8          |
| LCD SDA       | A4 (Uno)    |
| LCD SCL       | A5 (Uno)    |
| Buzzer +      | D7          |
| Buzzer -      | GND         |
| LCD VCC/GND   | 5V / GND    |
| HC-SR04 VCC/GND | 5V / GND  |

---

## Distance Behavior

| Distance       | Behavior         |
|----------------|------------------|
| < 20 cm        | Fast beep        |
| 20–40 cm       | Slow beep        |
| > 40 cm        | Silent           |

---

## Circuit Diagram

![SimpleParkingSensor_CircuitDiagram](https://github.com/user-attachments/assets/0a15f7ae-ae99-46a9-8991-6a1070ba9fd5)


---

## Author

Ahmet Gürkan Özçelik – [@ahmetgozcelik](https://github.com/ahmetgozcelik)
