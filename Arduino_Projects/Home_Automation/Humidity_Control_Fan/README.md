# 💨 Humidity & Temperature Based Fan Control

This project automatically controls a fan using a relay module based on real-time humidity and temperature values measured by a DHT11 sensor.

## 🧩 Components Used
- Arduino UNO  
- DHT11 Temperature & Humidity Sensor  
- 1-Channel Relay Module (Active LOW)  
- DC Fan / AC Fan (via relay)  
- Jumper Wires  
- Breadboard  

## 🔌 Connections
- DHT11 Data → Arduino Pin 2  
- Relay IN → Arduino Pin 3  
- Relay VCC → 5V  
- Relay GND → GND  
- Fan → Connected through relay (NO & COM terminals)

## ⚙️ Working
- The DHT11 sensor measures **humidity (%)** and **temperature (°C)**.  
- The Arduino reads values every 2 seconds.  
- If **humidity > 60%** and **temperature > 20°C**, the relay turns the fan **ON**.  
- Otherwise, the fan remains **OFF**.  
- Live values and fan status are shown on the **Serial Monitor**.

## 🌍 Real-world Use Cases
- Automatic ventilation in rooms and labs  
- Humidity-based exhaust fan control  
- Smart environment control systems  
- Educational automation projects  

## 💻 Software Used
- Arduino IDE  

## 📚 Dependencies
- [Adafruit DHT Sensor Library](https://github.com/adafruit/DHT-sensor-library)  
- [Adafruit Unified Sensor](https://github.com/adafruit/Adafruit_Sensor)

## 📸 Demo
![Humidity Control Fan](./photos/Humidity_Control_Fan.jpg)
