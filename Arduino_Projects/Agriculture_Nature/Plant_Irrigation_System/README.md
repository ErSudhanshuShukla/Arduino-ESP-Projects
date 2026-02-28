# 🌱 Plant Irrigation System

This project implements an automated plant irrigation system using soil moisture sensing and threshold-based control logic.  
The system continuously monitors soil moisture levels and activates a water pump when the soil becomes dry.  
It helps optimize water usage, reduce manual effort, and improve plant health through automated irrigation management.

## 🧩 Required Components
- 1 x Arduino UNO  
- 1 x Soil Moisture Sensor Module  
- 1 x Single Channel Relay Module (Active LOW)  
- 1 x DC Mini Water Pump  
- 2 x 18650 Li-ion Cells with Holder  
- Pipes / Tubes for liquid flow  
- Breadboard & Jumper Wires  
- USB Cable / Power Supply  
- 3D Model (Reference): [**Thingiverse**](https://www.thingiverse.com)

## 🔌 Connections

*1. Control Circuit (Arduino & Modules)*  
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
      <td rowspan="3" align="center"><b>Soil Moisture Sensor Module</b></td>
      <td align="center">VCC</td>
      <td align="center">5V</td>
    </tr>
    <tr>
      <td align="center">GND</td>
      <td align="center">GND</td>
    </tr>
    <tr>
      <td align="center">AO (Analog Out)</td>
      <td align="center">A0</td>
    </tr>
    <tr>
      <td rowspan="3" align="center"><b>Relay Module</b></td>
      <td align="center">IN</td>
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

> ℹ️ **Relay Note:**  
> - This project is configured for an **Active LOW relay module**.  
> - If you are using an **Active HIGH relay**, you may need to invert the relay logic in the code.

*2. Pump Connection (DC Mini Pump via Relay)*  
<table>
  <thead>
    <tr>
      <th align="center">Component</th>
      <th align="center">Wire</th>
      <th align="center">Connects To</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td align="center"><b>Battery Pack (2 × 18650)</b></td>
      <td align="center">Positive (+)</td>
      <td align="center">Relay COM</td>
    </tr>
    <tr>
      <td rowspan="2" align="center"><b>DC Mini Water Pump</b></td>
      <td align="center">Positive (+)</td>
      <td align="center">Relay NO</td>
    </tr>
    <tr>
      <td align="center">Negative (-)</td>
      <td align="center">Battery Pack Negative (-)</td>
    </tr>
  </tbody>
</table>

> ⚠️ **Safety & Power Notes:**  
> - Do **not** power the DC mini water pump from Arduino 5V.  
> - Use **2 × 18650 Li-ion cells** with a proper holder.  
> - If required by your relay module, connect **Arduino GND and battery negative (–)** together (common ground).  
> - Be careful while working with liquids and electronics together.

## 💻 Software Used
- [**Arduino IDE**](https://www.arduino.cc/en/software/)

## 📁 Project Files
- 💻 [**Source Code**](./code/Plant_Irrigation_System.ino)  
- 📸 [**Project Photo**](./photos/Plant_Irrigation_System.jpg)

## 📸 Demo
<p align="left">
  <img src="./photos/Plant_Irrigation_System.jpg" width="300" alt="Plant Irrigation System Prototype"/>
</p>

## ⚙️ Working
- The soil moisture sensor outputs an **analog value (0–1023)** based on soil condition.  
- Arduino continuously reads the sensor value from **A0**.  
- When the soil is **dry** (value below a set threshold):  
  - Relay goes **LOW** → Pump **ON** (Active LOW).  
- When the soil is **wet**:  
  - Relay goes **HIGH** → Pump **OFF**.  
- Live sensor values can be monitored on the **Serial Monitor** for calibration.

## 🚀 Future Improvements
- Add **DHT11/DHT22** to consider temperature & humidity.  
- Add **LCD/OLED** to display soil moisture and pump status.  
- Add **manual override button** for pump control.  
- Integrate **ESP8266/ESP32** for IoT monitoring & alerts.  
- Add **water level sensor** for tank empty protection.  
- Add **timer-based watering schedule**.

