# 🔔 Arduino Door Bell

This project demonstrates a simple **Arduino-based doorbell system** using a **push button and buzzer**.  
When the button is pressed, a short doorbell melody is played.

## 🧩 Required Components
- Arduino UNO  
- Push Button  
- Buzzer  
- Jumper Wires  
- Custom prototyping baseplate with 3D-printed mounts  
- USB Cable / Power Supply  

## 🔌 Connections

### Push Button
| Button Pin | Arduino Pin |
|------------|-------------|
| One side   | Pin 9       |
| Other side | GND         |

> ℹ️ Using `INPUT_PULLUP`, so the button is **Active LOW**  
> - Not pressed → HIGH  
> - Pressed → LOW  

### Buzzer
| Buzzer Pin | Arduino Pin |
|------------|-------------|
| + (Signal) | Pin 11      |
| - (GND)    | GND         |

## 💻 Software Used
- Arduino IDE  

## 📁 Project Files
- 💻 **Source Code:** [Door_Bell.ino](./code/Door_Bell.ino)  
- 📸 **Project Photo:** [Door_Bell.jpg](./photos/Door_Bell.jpg)  

## ⚙️ Working

- The push button is connected using the **internal pull-up resistor**.  
- Arduino continuously monitors the button state.  
- On a **valid button press (HIGH → LOW transition)**:
  - A doorbell melody is played using the buzzer.  
- This logic prevents repeated triggering when the button is held down.  
- The melody is generated using different sound frequencies.

## 📸 Demo

*Hardware prototype featuring an Arduino UNO mounted on a cardboard base with a push button and buzzer.*

<p align="center">
  <img src="./photos/Door_Bell.jpg" width="400" alt="Arduino Door Bell Prototype"/>
</p>

## 🌍 Real-world Use Cases
- Residential doorbell system prototype  
- Office or lab calling bell  
- Electronics exhibition demonstration  
- Basic human–machine interface (HMI) example  

## 🚀 Future Improvements
- Add LED/LCD status indicator  
- Support multiple selectable ringtones  
- Wireless trigger using RF/Bluetooth/Wi-Fi  
- Enclosure for safe, permanent installation  
