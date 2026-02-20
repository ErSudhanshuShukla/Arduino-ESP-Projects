# 💨 Humidity & Temperature Based Fan Control

This project automatically controls a fan using a relay module based on real-time humidity and temperature values measured by a DHT11 sensor. The system helps maintain comfortable environmental conditions by turning the fan ON/OFF based on predefined thresholds.

## 🧩 Required Components
- Arduino UNO  
- DHT11 Temperature & Humidity Sensor (Module)  
- 1-Channel Relay Module (Active LOW)  
- DC Fan / AC Fan (via relay)  
- Jumper Wires  
- Breadboard  
  
## 🔌 Connections
  
### DHT11 Sensor
| DHT11 Pin | Arduino Pin |
|-----------|-------------|
| VCC       | 5V          |
| GND       | GND         |
| DATA      | Pin 2       |

### Relay Module
| Relay Pin | Arduino Pin |
|-----------|-------------|
| IN        | Pin 3       |
| VCC       | 5V          |
| GND       | GND         |

### Fan (via Relay)
| Fan Wire | Relay Terminal |
|----------|----------------|
| Live / + | COM            |
| Load     | NO             |

> ⚠️ **Safety Note:**  
> If you are controlling an AC fan, ensure proper insulation and safety precautions.  
> Use an opto-isolated relay module and avoid touching live terminals.

## 💻 Software Used
- Arduino IDE  

## 📚 Dependencies
Install the following libraries from Arduino Library Manager:

- **Adafruit DHT Sensor Library**  
  https://github.com/adafruit/DHT-sensor-library  

- **Adafruit Unified Sensor**  
  https://github.com/adafruit/Adafruit_Sensor  

## 📁 Project Files
- 💻 **Source Code:** [Humidity_Control_Fan.ino](./code/Humidity_Control_Fan.ino)
- 📸 **Project Photo:** [Humidity_Control_Fan.jpg](./photos/Humidity_Control_Fan.jpg)

## ⚙️ Working

- The DHT11 sensor measures:
  - **Humidity (%)**
  - **Temperature (°C)**
- Arduino reads sensor values every **2 seconds**.
- The fan turns **ON** when:
  - **Humidity > 60%**
  - **Temperature > 20°C**
- Otherwise, the fan remains **OFF**.
- Live readings and fan status are displayed on the **Serial Monitor**.

> ℹ️ **Relay Logic (Active LOW):**  
> - LOW  → Fan ON  
> - HIGH → Fan OFF  

## 📸 Demo
<p align="center">
  <img src="./photos/Humidity_Control_Fan.jpg" width="500" alt="Humidity Control Fan Prototype"/>
  <br/>
  <em>Prototype mounted on cardboard with DHT11 sensor, relay module, and Arduino UNO.</em>
</p>

## 🌍 Real-world Use Cases
- Automatic room ventilation  
- Humidity-based exhaust fan  
- Smart environment control  
- School / college mini projects  
- Smart home automation demos  

## 🚀 Future Improvements
- Add LCD/OLED display for live readings  
- Add IoT connectivity (ESP8266 / ESP32)  
- Add adjustable thresholds (buttons / potentiometer)  
- Add hysteresis to avoid frequent ON/OFF switching  
- Add data logging 

