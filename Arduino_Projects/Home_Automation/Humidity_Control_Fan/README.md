# 💨 Humidity & Temperature Based Fan Control (Arduino)

This project automatically controls a fan using a relay module based on real-time humidity and temperature values measured by a DHT11 sensor. The system helps maintain comfortable environmental conditions by turning the fan ON/OFF based on predefined thresholds.

---

## 🧩 Required Components
- Arduino UNO  
- DHT11 Temperature & Humidity Sensor (Module)  
- 1-Channel Relay Module (Active LOW)  
- DC Fan / AC Fan (via relay)  
- Jumper Wires  
- Breadboard  

---

## 🔌 Connections
- **DHT11 VCC** → Arduino **5V**  
- **DHT11 GND** → Arduino **GND**  
- **DHT11 DATA** → Arduino **Pin 2**  

- **Relay IN** → Arduino **Pin 3**  
- **Relay VCC** → **5V**  
- **Relay GND** → **GND**  

- **Fan** → Connected via relay **NO** & **COM** terminals  

> ⚠️ **Safety Note:** If you are controlling an AC fan, ensure proper insulation and safety precautions. Use a relay module with opto-isolation and avoid touching live terminals.

---

## ⚙️ Working
- The DHT11 sensor measures **humidity (%)** and **temperature (°C)**.  
- Arduino reads sensor values every **2 seconds**.  
- If **humidity > 60%** and **temperature > 20°C**, the relay activates and the fan turns **ON**.  
- Otherwise, the fan remains **OFF**.  
- Live readings and fan status are displayed on the **Serial Monitor** for monitoring and debugging.

---

## 🌍 Real-world Use Cases
- Automatic ventilation in rooms and laboratories  
- Humidity-based exhaust fan control  
- Smart environment control systems  
- Educational automation and IoT prototypes  

---

## 💻 Software Used
- Arduino IDE  

---

## 📚 Dependencies
- [Adafruit DHT Sensor Library](https://github.com/adafruit/DHT-sensor-library)  
- [Adafruit Unified Sensor](https://github.com/adafruit/Adafruit_Sensor)

---

## 📁 Project Files
- 💻 **Source Code:** [Humidity_Control_Fan.ino](./code/Humidity_Control_Fan.ino)  
- 📸 **Project Photo:** [Humidity_Control_Fan.jpg](./photos/Humidity_Control_Fan.jpg)

---

## 📸 Demo
![Humidity Control Fan](./photos/Humidity_Control_Fan.jpg)

---

## 🚀 Future Improvements
- Add LCD/OLED display for live readings  
- Add IoT connectivity for remote monitoring  
- Add adjustable thresholds using potentiometer or buttons  
- Implement hysteresis to prevent frequent ON/OFF switching  

---
## 📄 License
This project is shared for educational purposes. You may use and modify it for personal and academic projects.
