# 🔐 Smart Keypad Lock

This project demonstrates a simple **password-based door locking system** using an **Arduino**, a **4x4 keypad**, a **servo motor**, and a **16x2 I2C LCD display**.  
The system unlocks the door when the correct password is entered and locks it again when `#` is pressed.

## 🧩 Required Components
- 1 x Arduino UNO  
- 1 x 4x4 Matrix Keypad  
- 1 x Servo Motor (SG90 or similar)  
- 1 x 16x2 I2C LCD Display (Address: 0x27)  
- External 5V Power Supply (Recommended for Servo)  
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
      <td rowspan="8" align="center"><b>4x4 Keypad</b></td>
      <td align="center">R1</td><td align="center">Pin 9</td>
    </tr>
    <tr><td align="center">R2</td><td align="center">Pin 8</td></tr>
    <tr><td align="center">R3</td><td align="center">Pin 7</td></tr>
    <tr><td align="center">R4</td><td align="center">Pin 6</td></tr>
    <tr><td align="center">C1</td><td align="center">Pin 5</td></tr>
    <tr><td align="center">C2</td><td align="center">Pin 4</td></tr>
    <tr><td align="center">C3</td><td align="center">Pin 3</td></tr>
    <tr><td align="center">C4</td><td align="center">Pin 2</td></tr>
    <tr>
      <td rowspan="3" align="center"><b>Servo Motor</b></td>
      <td align="center">VCC (Red)</td><td align="center">5V</td>
    </tr>
    <tr><td align="center">GND (Brown/Black)</td><td align="center">GND</td></tr>
    <tr><td align="center">Signal (Orange)</td><td align="center">Pin 10</td></tr>
    <tr>
      <td rowspan="4" align="center"><b>I2C LCD</b></td>
      <td align="center">VCC</td><td align="center">5V</td>
    </tr>
    <tr><td align="center">GND</td><td align="center">GND</td></tr>
    <tr><td align="center">SDA</td><td align="center">A4</td></tr>
    <tr><td align="center">SCL</td><td align="center">A5</td></tr>
  </tbody>
</table>

> ⚠️ **Power Note:**  
> - Servo motors may require an external 5V supply.  
> - Connect all GNDs together (common ground).  
> - Avoid powering servo directly from Arduino if unstable.

## 💻 Software Used
- [**Arduino IDE**](https://www.arduino.cc/en/software/)

## 📚 Dependencies

Install from Arduino Library Manager or official sources:

- [**Keypad Library**](https://github.com/Chris--A/Keypad)  
- [**Servo Library**](https://www.arduino.cc/reference/en/libraries/servo/) *(Built-in with Arduino IDE)*  
- [**LiquidCrystal I2C Library**](https://github.com/johnrickman/LiquidCrystal_I2C)  
- [**Wire Library**](https://www.arduino.cc/en/reference/wire) *(Built-in)*  

## 📁 Project Files
- 💻 [**Source Code**](./code/Smart_Keypad_Lock.ino)  
- 📸 [**Project Photo**](./photos/Smart_Keypad_Lock.jpg)

## 📸 Demo
<p align="left">
  <img src="./photos/Smart_Keypad_Lock.jpg" width="300" alt="Smart Keypad Lock Prototype"/>
</p>

## ⚙️ Working
- User enters password using the keypad.
- Entered digits are hidden using `*`.
- When `#` is pressed:
  - If password matches → Servo rotates (Unlock).
  - If incorrect → Access denied.
- Press `#` again while unlocked to lock the system.
- `*` clears the input.

## 🚀 Future Improvements
- Add **EEPROM** to store custom passwords.  
- Add **RFID module** for dual authentication.  
- Add **ESP8266/ESP32** for IoT access logs.  
- Add **buzzer feedback system**.  
- Add **OTP-based authentication system**.
