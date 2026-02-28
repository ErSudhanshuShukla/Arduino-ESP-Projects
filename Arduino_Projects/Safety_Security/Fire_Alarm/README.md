# 🔥 Fire Alarm

This project demonstrates a simple **fire detection and alarm system** using an **Arduino**, a **flame sensor module**, and a **buzzer**.  
When a flame is detected, the system immediately activates a **buzzer alarm** to alert users.

## 🧩 Required Components
- 1 x Arduino UNO  
- 1 x Flame Sensor Module  
- 1 x Buzzer  
- Breadboard & Jumper Wires  
- USB Cable / Power Supply  
- 3D Model (Reference): [**Thingiverse**](https://www.thingiverse.com)

## 🔌 Connections

<table>
  <thead>
    <tr>
      <th align="center">Component</th>
      <th align="center">Component Pin</th>
      <th align="center">Arduino Pin</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td rowspan="3" align="center"><b>Flame Sensor Module</b></td>
      <td align="center">VCC</td>
      <td align="center">5V</td>
    </tr>
    <tr>
      <td align="center">GND</td>
      <td align="center">GND</td>
    </tr>
    <tr>
      <td align="center">DO (Digital Out)</td>
      <td align="center">Pin 2</td>
    </tr>
    <!-- Buzzer -->
    <tr>
      <td rowspan="2" align="center"><b>Buzzer</b></td>
      <td align="center">+ (Signal)</td>
      <td align="center">Pin 11</td>
    </tr>
    <tr>
      <td align="center">– (GND)</td>
      <td align="center">GND</td>
    </tr>
  </tbody>
</table>

> ⚠️ **Important:**  
> - Most flame sensor modules are **Active LOW** (LOW = flame detected).  
> - Adjust sensitivity using the onboard potentiometer.  
> - This is a basic prototype and not a certified fire safety device.

## 💻 Software Used
- [**Arduino IDE**](https://www.arduino.cc/en/software/)

## 📁 Project Files
- 💻 [**Source Code**](./code/Fire_Alarm.ino)  
- 📸 [**Project Photo**](./photos/Fire_Alarm.jpg)

## 📸 Demo
<p align="left">
  <img src="./photos/Fire_Alarm.jpg" width="300" alt="Fire Alarm Prototype"/>
</p>

## ⚙️ Working
- The flame sensor continuously monitors infrared light emitted by fire.  
- If a flame is detected:
  - The sensor output becomes **LOW**.
  - The buzzer turns **ON**.
- If no flame is detected:
  - The buzzer remains **OFF**.

## 🚀 Future Improvements
- Add **LED indicator** for visual alert.  
- Add **LCD display** for status message.  
- Add **GSM module** for SMS fire alerts.  
- Add **ESP8266/ESP32** for IoT-based fire monitoring.  
- Add **automatic water sprinkler system** using relay.

