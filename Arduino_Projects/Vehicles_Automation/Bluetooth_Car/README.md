# 🚗 Smart Bluetooth Car

This project demonstrates a smartphone-controlled **Bluetooth 4x4 RC Car** using **Arduino**, an **HC-05 Bluetooth module**, and an **L298N motor driver**.  
The car can move **forward, backward, left, right**, and also control **horn and headlights** via Bluetooth commands.
This version uses a **4x4 chassis (4 DC motors)** for better traction and stability.

## 🧩 Required Components
- 1 x Arduino UNO  
- 1 x L298N Motor Driver Module  
- 1 x HC-05 Bluetooth Module  
- 4 x DC Motors (4x4 chassis)  
- 1 x 4x4 Car Chassis  
- 1 x Buzzer (Horn)  
- 2 x LEDs (Headlights)
- 2 x 220Ω resistor 
- 3 x 18650 Li-ion Cells with Holder  
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
      <td rowspan="6" align="center"><b>L298N Motor Driver</b></td>
      <td align="center">IN1</td>
      <td align="center">Pin 5</td>
    </tr>
    <tr><td align="center">IN2</td><td align="center">Pin 6</td></tr>
    <tr><td align="center">IN3</td><td align="center">Pin 9</td></tr>
    <tr><td align="center">IN4</td><td align="center">Pin 10</td></tr>
    <tr><td align="center">ENA</td><td align="center">Pin 3 (PWM)</td></tr>
    <tr><td align="center">ENB</td><td align="center">Pin 11 (PWM)</td></tr>
    <tr>
      <td rowspan="4" align="center"><b>HC-05 Bluetooth</b></td>
      <td align="center">VCC</td>
      <td align="center">5V</td>
    </tr>
    <tr><td align="center">GND</td><td align="center">GND</td></tr>
    <tr><td align="center">TXD</td><td align="center">Arduino RX</td></tr>
    <tr><td align="center">RXD</td><td align="center">Arduino TX (via voltage divider)</td></tr>
    <tr>
      <td rowspan="2" align="center"><b>Buzzer (Horn)</b></td>
      <td align="center">Signal (+)</td>
      <td align="center">Pin 12</td>
    </tr>
    <tr>
      <td align="center">GND (-)</td>
      <td align="center">Arduino GND</td>
    </tr>
    <tr>
      <td rowspan="4" align="center"><b>Headlights</b></td>
      <td align="center">LED 1 Anode (+)</td>
      <td align="center">Pin 7 (via 220Ω resistor)</td>
    </tr>
    <tr>
      <td align="center">LED 1 Cathode (-)</td>
      <td align="center">GND</td>
    </tr>
    <tr>
      <td align="center">LED 2 Anode (+)</td>
      <td align="center">Pin 8 (via 220Ω resistor)</td>
    </tr>
    <tr>
      <td align="center">LED 2 Cathode (-)</td>
      <td align="center">GND</td>
    </tr>
  </tbody>
</table>

> ⚠️ **HC-05 Wiring Note:**  
> - Use a **voltage divider (1kΩ + 2kΩ)** for Arduino TX → HC-05 RX.  
> - HC-05 RX pin is **not 5V tolerant**.

*2. Motor Connections to L298N*

<table>
  <thead>
    <tr>
      <th align="center">Motor Group</th>
      <th align="center">Connected To</th>
      <th align="center">L298N Outputs</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td align="center"><b>Left Front + Left Rear</b></td>
      <td align="center">Connected in Parallel</td>
      <td align="center">OUT1</td>
    </tr>
    <tr>
      <td align="center"><b>Right Front + Right Rear</b></td>
      <td align="center">Connected in Parallel</td>
      <td align="center">OUT2</td>
    </tr>
  </tbody>
</table>

*3. Power Connections*
<table>
  <thead>
    <tr>
      <th align="center">Component</th>
      <th align="center">Connection</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td align="center"><b>3 × 18650 Battery Pack (+)</b></td>
      <td align="center">L298N 12V</td>
    </tr>
    <tr>
      <td align="center"><b>Battery Pack (-)</b></td>
      <td align="center">L298N GND</td>
    </tr>
    <tr>
      <td align="center"><b>Arduino GND</b></td>
      <td align="center">L298N GND (Common Ground Required)</td>
    </tr>
    <tr>
      <td align="center"><b>Arduino 5V (Option A)</b></td>
      <td align="center">L298N 5V (Jumper ON)</td>
    </tr>
    <tr>
      <td align="center"><b>Arduino VIN (Option B)</b></td>
      <td align="center">Battery Pack (+)</td>
    </tr>
  </tbody>
</table>

> ⚠️ **Important Power Notes:**  
> - Arduino GND and L298N GND must be connected (common ground).  
> - Use 3×18650 battery pack for motors.  
> - **Option A:** If using L298N 5V output → keep 5V jumper ON.  
> - **Option B:** If powering Arduino via VIN → connect battery (+) to VIN (NOT 5V).  
> - Never connect VIN to 5V directly.

## 💻 Software Used
- [**Arduino IDE**](https://www.arduino.cc/en/software/)  
- [**Serial Bluetooth Terminal (Android)**](https://play.google.com/store/apps/details?id=de.kai_morich.serial_bluetooth_terminal)

> 📲 **How to Control:**  
> - Pair phone with **HC-05** (PIN: `1234` or `0000`)  
> - Open Bluetooth Terminal app  
> - Send commands from the app

## 📁 Project Files
- 💻 [**Source Code**](./code/Bluetooth_Car.ino)  
- 📸 [**Project Photo**](./photos/Bluetooth_Car.jpg)

## 📸 Demo
<p align="left">
  <img src="./photos/Bluetooth_Car.jpg" width="300" alt="Smart Bluetooth Car Prototype"/>
</p>

## ⚙️ Working

The car responds to the following Bluetooth commands:

| Command | Action |
|----------|---------|
| F | Forward |
| B | Backward |
| L | Left |
| R | Right |
| S | Stop |
| H | Horn ON |
| 1 | Headlights ON |
| 0 | Headlights OFF |

- Uses PWM for speed control.  
- Includes safety auto-stop timeout.  
- 4x4 configuration provides better traction and stability.

## 🚀 Future Improvements
- Add obstacle avoidance (Ultrasonic sensor).  
- Add camera module (FPV).  
- Add speed control slider.  
- Upgrade to ESP32 for Wi-Fi control.  
- Add rechargeable charging module (TP4056).
