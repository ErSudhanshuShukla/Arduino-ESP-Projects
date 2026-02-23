# 💡 Automatic Street Light

This project demonstrates a simple **LDR (Light Dependent Resistor) based automatic light system** using Arduino.  
The LED automatically turns **ON in darkness** and **OFF in bright light**, based on readings from the LDR sensor module.

## 🧩 Required Components
- Arduino UNO  
- LDR Sensor Module  
- White LED  
- 220Ω Resistor (current limiting for LED)  
- Jumper Wires  
- USB Cable / Power Supply  

## 🔌 Connections

### LDR Sensor Module
| LDR Pin | Arduino Pin |
|---------|-------------|
| VCC     | 5V          |
| GND     | GND         |
| DO      | Pin 2       |

### LED
| LED Pin | Arduino Pin |
|---------|-------------|
| Anode (+) | Pin 10    |
| Cathode (-) | GND    |

> ⚠️ **Important:**  
> Always connect a **220Ω resistor in series with the LED** to limit current and prevent LED damage.

## 💻 Software Used
- Arduino IDE  

## 📁 Project Files
- 💻 [**Source Code**](./code/Automatic_Street_Light.ino)  
- 📸 [**Project Photo**](./photos/Automatic_Street_Light.jpg)

## ⚙️ Working

- The LDR module senses ambient light level.  
- In **dark conditions**, the sensor output becomes **HIGH**.  
- Arduino reads the sensor output and turns the **LED ON**.  
- In **bright conditions**, the output becomes **LOW** and the **LED turns OFF**.  
- Live sensor status is displayed on the **Serial Monitor**.

## 🌍 Real-world Use Cases
- Automatic street light prototype  
- Night lamp / night indicator  
- Energy-saving lighting system demo  
- Light-based automation example  

## 🚀 Future Improvements
- Add adjustable light threshold (potentiometer)  
- Use analog LDR for brightness control (PWM)  
- Add relay for high-power lamps  
- Add IoT monitoring (ESP8266/ESP32)  
