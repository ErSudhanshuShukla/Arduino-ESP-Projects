# 📱 Bluetooth Home Automation

This project demonstrates a simple **Bluetooth-based home automation system** using Arduino and an **HC-05 Bluetooth module**.  
A relay-controlled appliance can be turned **ON/OFF wirelessly** from a smartphone using a **Bluetooth Terminal app**.

## 🧩 Required Components
- 1 x Arduino UNO  
- 1 x HC-05 Bluetooth Module  
- 1 x Single Channel Relay Module (Active LOW)  
- 1 x Load (DC bulb / AC appliance via relay)  
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
      <td rowspan="4" align="center"><b>HC-05 BT Module</b></td>
      <td align="center">VCC</td>
      <td align="center">5V</td>
    </tr>
    <tr>
      <td align="center">GND</td>
      <td align="center">GND</td>
    </tr>
    <tr>
      <td align="center">TXD</td>
      <td align="center">Pin 2 (Arduino RX)</td>
    </tr>
    <tr>
      <td align="center">RXD</td>
      <td align="center">Pin 3 (Arduino TX)</td>
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

> ⚠️ **HC-05 Wiring Notes:**  
> - Use a **voltage divider (1kΩ + 2kΩ)** to step down Arduino TX (5V) to ~3.3V for **HC-05 RX**.  
> - HC-05 uses **3.3V logic** on RX; direct 5V may damage the module.

> ℹ️ **Relay Note:**  
> - This project is configured for an **Active LOW relay module**.  
> - If you are using an **Active HIGH relay**, you may need to invert the relay logic in the code.

*2. Appliance Connection (AC / High Power Side)*  
<table>
  <thead>
    <tr>
      <th align="center">Appliance Wire</th>
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

> ⚠️ **Safety:**  
> - Connect the appliance through a relay module, not directly to Arduino.  
> - Be careful while working with AC loads.

## 💻 Software Used
- [**Arduino IDE**](https://www.arduino.cc/en/software/)  
- [**Serial Bluetooth Terminal (Android)**](https://play.google.com/store/apps/details?id=de.kai_morich.serial_bluetooth_terminal&pcampaignid=web_share)

> 📲 **Commands:**  
> - Send **`1`** → Relay ON  
> - Send **`0`** → Relay OFF

## 📁 Project Files
- 💻 [**Source Code**](./code/Bluetooth_Home_Automation.ino)  
- 📸 [**Project Photo**](./photos/Bluetooth_Home_Automation.jpg)

## 📸 Demo
<p align="left">
  <img src="./photos/Bluetooth_Home_Automation.jpg" width="300" alt="Bluetooth Home Automation Prototype"/>
</p>

## ⚙️ Working
- The HC-05 module pairs with the smartphone via Bluetooth.  
- User sends commands from a **Bluetooth Terminal app**.  
- Arduino reads incoming characters via **SoftwareSerial (Pins 2 & 3)**:
  - `1` → Relay turns **ON**  
  - `0` → Relay turns **OFF**  
- The relay switches the connected appliance accordingly.  
- Serial Monitor displays received commands and relay status.

## 🚀 Future Improvements
- Control multiple devices (multi-relay board).  
- Create a custom Android app UI.  
- Add password/PIN for security.  
- Add Wi-Fi (ESP8266/ESP32) for internet control.

