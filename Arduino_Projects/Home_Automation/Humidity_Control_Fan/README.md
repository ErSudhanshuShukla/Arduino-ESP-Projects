# 🪭 Humidity & Temperature Based Fan Control

This project automatically controls a fan using a relay module based on real-time humidity and temperature values measured by a DHT11 sensor. The system helps maintain comfortable environmental conditions by turning the fan ON/OFF based on predefined thresholds.

## 🧩 Required Components
- 1 x Arduino UNO  
- 1 x DHT11 (Module)  
- 1 x Single Channel Relay Module (Active LOW) 
- 1 x DC Fan / AC Fan (via relay)  
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
      <td rowspan="3" align="center"><b>DHT11 Module</b></td>
      <td align="center">VCC</td>
      <td align="center">5V</td>
    </tr>
    <tr>
      <td align="center">GND</td>
      <td align="center">GND</td>
    </tr>
    <tr>
      <td align="center">DATA</td>
      <td align="center">Pin 2</td>
    </tr>
    <tr>
      <td rowspan="3" align="center"><b>Relay Module</b></td>
      <td align="center">IN</td>
      <td align="center">Pin 3</td>
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

*2. Appliance Connection (Fan via Relay)*
<table>
  <thead>
    <tr>
      <th align="center">Fan Wire</th>
      <th align="center">Relay Terminal</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td align="center">Live / +</td>
      <td align="center">COM</td>
    </tr>
    <tr>
      <td align="center">Load</td>
      <td align="center">NO</td>
    </tr>
  </tbody>
</table>

> ⚠️ **Safety Note:**
> - Connect the fan through a relay module, not directly to Arduino.
> - Be careful while working with AC loads.

## 💻 Software Used
- [**Arduino IDE**](https://www.arduino.cc/en/software/)

## 📚 Dependencies
Install the following libraries from Arduino Library Manager:

- [**Adafruit DHT Sensor Library**](https://github.com/adafruit/DHT-sensor-library)
- [**Adafruit Unified Sensor**](https://github.com/adafruit/Adafruit_Sensor)  

## 📁 Project Files
- 💻 [**Source Code**](./code/Humidity_Control_Fan.ino)
- 📸 [**Project Photo**](./photos/Humidity_Control_Fan.jpg)

## ⚙️ Working

- The DHT11 sensor measures:
  - **Humidity (%)**
  - **Temperature (°C)**
- Arduino reads sensor values every **2 seconds**.
- The fan turns **ON** when:
  - **Humidity > 60%**
  - **Temperature > 25°C**
- Otherwise, the fan remains **OFF**.
- Live readings and fan status are displayed on the **Serial Monitor**.

> ℹ️ **Relay Logic (Active LOW):**  
> - LOW  → Fan ON  
> - HIGH → Fan OFF  

## 📸 Demo

<p align="left">
  <img src="./photos/Humidity_Control_Fan.jpg" width="400" alt="Humidity Control Fan Prototype"/>
</p>

## 🚀 Future Improvements
- Add LCD/OLED display for real-time readings.  
- Integrate IoT connectivity (ESP8266/ESP32) for remote monitoring.  
- Provide user-configurable thresholds via buttons or potentiometer.  
- Implement data logging for historical analysis.  


