# ✨ LED Chaser

This project demonstrates a **multi-effect LED chaser system** using **Arduino** and **9 LEDs**.  
The LEDs run through **multiple lighting patterns** like forward chase, reverse chase, ping-pong, breathing, Knight Rider, sparkle, and meteor tail effects.

## 🧩 Required Components
- 1 x Arduino UNO  
- 9 x LEDs  
- 9 x 220Ω Resistors (for LEDs)  
- Breadboard & Jumper Wires  
- USB Cable / Power Supply  
- 3D Model (Reference): [**Thingiverse**](https://www.thingiverse.com)

## 🔌 Connections

<table>
  <thead>
    <tr>
      <th align="center">Component</th>
      <th align="center">LED / Pin Name</th>
      <th align="center">Arduino Pin</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td rowspan="9" align="center"><b>LEDs</b></td>
      <td align="center">LED 1</td>
      <td align="center">Pin 2</td>
    </tr>
    <tr>
      <td align="center">LED 2</td>
      <td align="center">Pin 3</td>
    </tr>
    <tr>
      <td align="center">LED 3</td>
      <td align="center">Pin 4</td>
    </tr>
    <tr>
      <td align="center">LED 4</td>
      <td align="center">Pin 5</td>
    </tr>
    <tr>
      <td align="center">LED 5</td>
      <td align="center">Pin 6</td>
    </tr>
    <tr>
      <td align="center">LED 6</td>
      <td align="center">Pin 7</td>
    </tr>
    <tr>
      <td align="center">LED 7</td>
      <td align="center">Pin 8</td>
    </tr>
    <tr>
      <td align="center">LED 8</td>
      <td align="center">Pin 9</td>
    </tr>
    <tr>
      <td align="center">LED 9</td>
      <td align="center">Pin 10</td>
    </tr>
    <tr>
      <td colspan="3" align="center">
        All LED cathodes (–) → GND (each LED in series with 220Ω resistor)
      </td>
    </tr>
  </tbody>
</table>

> ⚠️ **Important:**  
> - Always use **220Ω resistors** with each LED to prevent damage.  
> - PWM pins (3, 5, 6, 9, 10) allow smooth fading effects.

## 💻 Software Used
- [**Arduino IDE**](https://www.arduino.cc/en/software/)

## 📁 Project Files
- 💻 [**Source Code**](./code/LED_Chaser.ino)  
- 📸 [**Project Photo**](./photos/LED_Chaser.jpg)

## 📸 Demo
<p align="left">
  <img src="./photos/LED_Chaser.jpg" width="250" alt="LED Chaser Prototype"/>
</p>

## ⚙️ Working
- The system controls **9 LEDs** connected to Arduino digital pins.  
- Multiple lighting patterns run **automatically in sequence**:
  - Forward chase  
  - Reverse chase  
  - Ping-pong  
  - Double-side wave  
  - Breathing (fade in/out)  
  - Knight Rider effect  
  - Random sparkle  
  - Meteor tail  
- PWM pins are used to create **smooth brightness fading**, while non-PWM pins simulate ON/OFF effects.  

## 🚀 Future Improvements
- Add **mode button** to change effects manually.  
- Add **Bluetooth control** to switch patterns from mobile.  
- Add **potentiometer** to control speed in real-time.
