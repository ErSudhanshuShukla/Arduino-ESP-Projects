
# 🌱 IoT Plant Irrigation System

This project implements an automated plant irrigation system using soil moisture sensing and IoT-based control logic. The system continuously monitors soil moisture levels and activates a water pump when the soil becomes dry. It also allows remote monitoring and manual control through the Blynk mobile application.

## 🧩 Required Components
- 1 x ESP8266 (NodeMCU)  
- 1 x Soil Moisture Sensor Module  
- 1 x Single Channel Relay Module (Active LOW)  
- 1 x DC Mini Water Pump  
- 2 x 18650 Li-ion Cells with Holder  
- Pipes / Tubes for liquid flow  
- Breadboard & Jumper Wires  
- USB Cable / Power Supply  
- 3D Model (Reference): [**Thingiverse**](https://www.thingiverse.com) 

## 🔌 Connections

*1. Control Circuit (ESP8266 & Modules)*  

<table>
  <thead>
    <tr>
      <th align="center">Component</th>
      <th align="center">Component Pin</th>
      <th align="center">ESP8266 Pin</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td rowspan="3" align="center"><b>Soil Moisture Sensor Module</b></td>
      <td align="center">VCC</td>
      <td align="center">3.3V</td>
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
      <td align="center">D5</td>
    </tr>
    <tr>
      <td align="center">VCC</td>
      <td align="center">VIN (5V)</td>
    </tr>
    <tr>
      <td align="center">GND</td>
      <td align="center">GND</td>
    </tr>
  </tbody>
</table>

> ℹ️ **Relay Note:**  
> - This project is configured for an **Active LOW relay module**.  
> - If you are using an **Active HIGH relay**, invert the relay logic in the code.

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
> - Do **not** power the DC mini water pump from ESP8266.  
> - Use **2 × 18650 Li-ion cells** with a proper holder.  
> - If required, connect **ESP8266 GND and battery negative (–)** together (common ground).  
> - Be careful while working with liquids and electronics together.

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

### 📱 Blynk Configuration

- 🔗 [**Blynk Setup Guide**](../../BLYNK_SETUP.md)
  
- **Required Virtual Pins**  
  - V1 → Relay Control (Manual + Auto Sync)  
  - V4 → Soil Moisture Percentage  

- **Datastream Type**  
  - V1 → Integer (0 – 1)  
  - V4 → Double (0 – 100) %  

- **Widget Configuration**  
  - Button Widget → V1 (Switch Mode)  
  - Gauge / Display Widget → V4 (% Unit)  

- **Update Interval**  
  - 5 seconds (Configured using `timer.setInterval(5000L, sendSoilData);`)  

- **Important Note**  
  - V1 allows manual ON/OFF control.  
  - Automatic irrigation logic may override manual control based on moisture threshold.  
  - Relay state is automatically synced back to V1 to keep the button status updated. 

## 📁 Project Files
- 💻 [Source Code](./code/IoT_Plant_Irrigation_System.ino)  
- 📸 [Project Photo](./photos/IoT_Plant_Irrigation_System.jpg) 

## 📸 Demo
<p align="left">
  <img src="./photos/IoT_Plant_Irrigation_System.jpg" width="300" alt="IoT Plant Irrigation System Prototype"/>
</p>

## ⚙️ Working
- ESP8266 reads the soil moisture sensor value from **A0** and converts it into percentage (0–100%).
- If moisture falls below the threshold → Pump ON.
- If moisture is above the threshold → Pump OFF.
- Manual control is available via Virtual Pin V1.
- Relay state is synced back to V1 automatically.
- Moisture data is sent to V4 every 5 seconds.

## 🚀 Future Improvements
- Add DHT11/DHT22 for temperature & humidity monitoring.  
- Add water level sensor for tank empty protection.
- Add OLED display for local monitoring.  
- Add cloud data logging.  
- Add solar power integration.






