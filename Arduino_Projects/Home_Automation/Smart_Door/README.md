# 🚪 Smart Door

This project demonstrates a simple **Smart Door system** using an **ultrasonic sensor** and a **servo motor** with Arduino.  
When a person comes near the door (within a set distance), the door **automatically opens** and then **closes after a few seconds**.

## 🧩 Required Components
- 1 x Arduino UNO  
- 1 x Ultrasonic Sensor (HC-SR04)  
- 1 x Servo Motor (SG90/MG90)  
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
      <td rowspan="4" align="center"><b>Ultrasonic Sensor (HC-SR04)</b></td>
      <td align="center">VCC</td>
      <td align="center">5V</td>
    </tr>
    <tr>
      <td align="center">GND</td>
      <td align="center">GND</td>
    </tr>
    <tr>
      <td align="center">Trig</td>
      <td align="center">Pin 9</td>
    </tr>
    <tr>
      <td align="center">Echo</td>
      <td align="center">Pin 10</td>
    </tr>
    <tr>
      <td rowspan="3" align="center"><b>Servo Motor (SG90)</b></td>
      <td align="center">Signal</td>
      <td align="center">Pin 8</td>
    </tr>
    <tr>
      <td align="center">VCC</td>
      <td align="center">5V</td>
    </tr>
    <tr>
      <td align="center">GND</td>
      <td align="center">GND</td>
    </tr>
  </tbody>
</table>

> ⚠️ **Note:**  
> - If the servo motor jitters, moves unexpectedly, or causes the Arduino to reset, power the servo using an external 5V supply.  
> - Make sure to connect the **ground (GND)** of the external power supply with the **Arduino GND** (common ground).

## 💻 Software Used
- [**Arduino IDE**](https://www.arduino.cc/en/software/)

## 📚 Dependencies
- [**Servo Library**](https://github.com/arduino-libraries/Servo)  
  *(Pre-installed with Arduino IDE)*

## 📁 Project Files
- 💻 [**Source Code**](./code/Smart_Door.ino)  
- 📸 [**Project Photo**](./photos/Smart_Door.jpg)

## 📸 Demo
<p align="left">
  <img src="./photos/Smart_Door.jpg" width="300" alt="Smart Door Prototype"/>
</p>

## ⚙️ Working
- The ultrasonic sensor measures the distance in front of the door.  
- When a person/object is detected within **10 cm**:  
  - The servo rotates to **open the door**.  
  - After **3 seconds**, the servo returns to **close the door**.  
- Live distance values are printed on the **Serial Monitor**.

## 🚀 Future Improvements
- Add PIR sensor for better human detection.  
- Add RFID / keypad for access control.  
- Integrate ESP8266/ESP32 for IoT-based door control.  
- Add buzzer/LED for status indication.

