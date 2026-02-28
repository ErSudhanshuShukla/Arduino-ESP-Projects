# 💧 IoT Water Level Monitor

This project implements an IoT-based water level monitoring system using an ESP8266 (NodeMCU) and an ultrasonic sensor. The system continuously measures the water level inside a tank and sends the percentage value to the **Blynk mobile application** for real-time monitoring. It also provides **visual LED indication** for low and high water levels.

## 🧩 Required Components
- 1 x ESP8266 (NodeMCU)  
- 1 x Ultrasonic Sensor (HC-SR04)  
- 1 x Red LED  
- 1 x Green LED  
- 2 x 220Ω Resistors (for LEDs) 
- Breadboard & Jumper Wires  
- USB Cable / Power Supply  
- 3D Model (Reference): [**Thingiverse**](https://www.thingiverse.com)

## 🔌 Connections

<table>
  <thead>
    <tr>
      <th align="center">Component</th>
      <th align="center">Pin</th>
      <th align="center">ESP8266 Pin</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td rowspan="4" align="center"><b>Ultrasonic Sensor (HC-SR04)</b></td>
      <td align="center">VCC</td>
      <td align="center">5V / VIN</td>
    </tr>
    <tr>
      <td align="center">GND</td>
      <td align="center">GND</td>
    </tr>
    <tr>
      <td align="center">TRIG</td>
      <td align="center">D5</td>
    </tr>
    <tr>
      <td align="center">ECHO</td>
      <td align="center">D6</td>
    </tr>
    <tr>
      <td rowspan="4" align="center"><b>LED Indicators</b></td>
      <td align="center">Red LED (+)</td>
      <td align="center">D7 (via 220Ω resistor)</td>
    </tr>
    <tr>
      <td align="center">Red LED (–)</td>
      <td align="center">GND</td>
    </tr>
    <tr>
      <td align="center">Green LED (+)</td>
      <td align="center">D8 (via 220Ω resistor)</td>
    </tr>
    <tr>
      <td align="center">Green LED (–)</td>
      <td align="center">GND</td>
    </tr>
  </tbody>
</table>

> ⚠️ **Important:**  
> - HC-SR04 ECHO pin outputs 5V. Use a voltage divider (e.g., 1kΩ + 2kΩ) to safely interface with ESP8266 (3.3V logic).  
> - Always use 220Ω resistors in series with LEDs.  
> - Mount the ultrasonic sensor securely above the tank for accurate readings.

## 💻 Software Used
- [Arduino IDE](https://www.arduino.cc/en/software)  
- [Blynk IoT Platform](https://blynk.io/)

## 📚 Dependencies
Install the following libraries from **Arduino Library Manager**:

- [ESP8266WiFi](https://github.com/esp8266/Arduino)  
- [Blynk Library](https://github.com/blynkkk/blynk-library)  

> ℹ️ **Make sure you have installed the ESP8266 Board Package from:**
>
> Arduino IDE → Preferences → Additional Boards Manager URLs  
>
> ```
> http://arduino.esp8266.com/stable/package_esp8266com_index.json
> ```

## 📱 Blynk Configuration

🔗 [**Blynk Setup Guide**](../../BLYNK_SETUP.md)

- **Required Virtual Pins**  
  - V7 → Water Level Percentage  

- **Datastream Type**  
  - V7 → Integer (0 – 100) %  

- **Widget Configuration**  
  - Gauge / Display Widget → V7 (% Unit)  

- **Update Interval**  
  - 1 second (`timer.setInterval(1000L, sendWaterLevel);`)

## 📁 Project Files
- 💻 [Source Code](./code/IoT_Water_Level_Monitor.ino)  
- 📸 [Project Image](./photos/IoT_Water_Level_Monitor.jpg)

## 📸 Demo
<p align="left">
  <img src="./photos/IoT_Water_Level_Monitor.jpg" width="300" alt="IoT Water Level Monitor"/>
</p>

## ⚙️ Working
- The ultrasonic sensor measures the distance between the sensor and the water surface.  
- The measured distance is converted into **water height** based on tank height.  
- Water height is mapped into **percentage (0–100%)**.  
- The percentage value is sent to **Virtual Pin V7** every second.  
- LED Indicators:
  - 🔴 Red LED → Water level below 20% (Low Level)  
  - 🟢 Green LED → Water level above 80% (Tank Full)  
  - Both OFF → Medium water level  
- Live water level can be monitored on both the **Blynk App** and the **Serial Monitor**.
<details>
<summary><b>🎯 Calibration (Click to Expand)</b></summary>

<br>

To ensure accurate water level measurement, follow these calibration steps:

- Measure the **total height of the tank (in cm)** from the ultrasonic sensor position to the bottom of the tank.
- Update the value in the code:

```cpp
int tankHeightCm = 30;   // Replace 30 with your tank height
```

- Mount the ultrasonic sensor:
  - Perpendicular to the water surface  
  - Firmly fixed (no vibration)  
  - Free from obstructions  

📏 Fine Tuning

- If percentage reading is slightly inaccurate:
  - Adjust `tankHeightCm` by ±1–2 cm.
  - Check for echo reflection issues inside the tank.

⚠️ Important

- HC-SR04 minimum measurable distance ≈ 2 cm.
- Test readings at:
  - Empty tank (0%)
  - Half-filled tank (~50%)
  - Full tank (~100%)

</details>

## 🚀 Future Improvements
- Add automatic motor control for tank filling.  
- Add push notification when tank is full/empty.  
- Add buzzer alert for low water level.  
- Add OLED display for local monitoring.  
- Add cloud data logging.

