# 💡 Automatic Street Light

This project demonstrates a simple **LDR (Light Dependent Resistor) based automatic light system** using Arduino.  
The LED automatically turns **ON in darkness** and **OFF in bright light**, based on readings from the LDR sensor module.

## 🧩 Required Components
- 1 x Arduino UNO  
- 1 x LDR Sensor Module  
- 1 x White LED  
- 1 x 220Ω Resistor (current limiting for LED)  
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
      <td rowspan="3" align="center"><b>LDR Sensor Module</b></td>
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
    <tr>
      <td rowspan="2" align="center"><b>LED</b></td>
      <td align="center">Anode (+) via 220Ω Resistor</td>
      <td align="center">Pin 10</td>
    </tr>
    <tr>
      <td align="center">Cathode (-)</td>
      <td align="center">GND</td>
    </tr>
  </tbody>
</table>

> ⚠️ **Important:**  
> - Always connect a **220Ω resistor in series with the LED** to limit current and prevent LED damage.
> - Adjust the LDR module potentiometer to set sensitivity.

## 💻 Software Used
- [**Arduino IDE**](https://www.arduino.cc/en/software/)
    
## 📁 Project Files
- 💻 [**Source Code**](./code/Automatic_Street_Light.ino)  
- 📸 [**Project Photo**](./photos/Automatic_Street_Light.jpg)

## 📸 Demo
<p align="left">
  <img src="./photos/Automatic_Street_Light.jpg" width="300" alt="LDR Automatic Light Prototype"/>
</p>

## ⚙️ Working
- The LDR module senses ambient light level.  
- In **dark conditions**, the sensor output becomes **HIGH**.  
- Arduino reads the sensor output and turns the **LED ON**.  
- In **bright conditions**, the output becomes **LOW** and the **LED turns OFF**.  
- Live sensor status is displayed on the **Serial Monitor**.

## 🚀 Future Improvements
- Provide user-configurable light sensitivity calibration.  
- Introduce adaptive brightness control based on ambient light levels. 
- Support high-power lighting through isolated relay control. 
- Extend the system with IoT connectivity for remote monitoring and analytics.
