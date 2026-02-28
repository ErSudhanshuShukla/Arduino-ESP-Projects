# 📱 Blynk IoT Setup Guide (Common for All Projects)

This guide explains how to configure any ESP8266 / ESP32 based project on the **Blynk IoT Platform**.

Project-specific details (virtual pins, widget types, etc.) should be mentioned inside individual project README files.

---

## 🔹 Step 1: Create Blynk Account

1. Download **Blynk IoT** app from Play Store / App Store  
2. Create an account and login  
3. Open the web dashboard: https://blynk.cloud  

---

## 🔹 Step 2: Create Template

1. Go to **Templates → New Template**
2. Fill the following:
   - Template Name: (Project Name)
   - Hardware: ESP8266 / ESP32
   - Connection Type: WiFi
3. Click **Done**

---

## 🔹 Step 3: Create Datastreams

Go to:

Template → Datastreams → New Datastream → Virtual Pin

Create Virtual Pins according to your project requirements.

For example:

- V0 → LED Control  
- V1 → Relay Control  
- V2 → Sensor Data  

⚠️ Datatype (Integer / Double / String) and range (Min/Max) must match your code.

---

## 🔹 Step 4: Create Device

1. Go to **Devices → New Device**
2. Select **From Template**
3. Choose your created template
4. Copy the generated **Auth Token**
5. Paste it inside your Arduino code

---

## 🔹 Step 5: Update Credentials in Code

Open your `.ino` file and update:

```cpp
// -------- Blynk Credentials --------
#define BLYNK_TEMPLATE_ID "Your_Template_ID"
#define BLYNK_TEMPLATE_NAME "Your_Template_Name"
#define BLYNK_AUTH_TOKEN "Your_Auth_Token"

// -------- WiFi Credentials --------
char ssid[] = "Your_WiFi_Name";
char pass[] = "Your_WiFi_Password";
```

Replace:

- `Your_Template_ID` → From Blynk Template Settings  
- `Your_Template_Name` → Template Name  
- `Your_Auth_Token` → From Device Info  
- `Your_WiFi_Name` → Your WiFi SSID  
- `Your_WiFi_Password` → Your WiFi Password  

⚠️ Never upload real credentials to public repositories.

---

## 🔹 Step 6: Setup Mobile Dashboard

1. Open Blynk IoT mobile app  
2. Open your device dashboard  
3. Add widgets according to your project  
4. Assign correct Virtual Pins to each widget  

Example:

- Button → V1  
- Gauge → V4  
- LCD → V2  

---

## 🔹 Step 7: Upload Code

1. Open Arduino IDE  
2. Select correct Board (ESP8266 / ESP32)  
3. Select correct COM Port  
4. Upload the code  

---

## ✅ Final Checklist

- Device connected to 2.4 GHz WiFi  
- Correct Auth Token entered  
- Virtual Pins match code  
- Serial Monitor baud rate correct  
- Device shows **Online** in Blynk dashboard  

---

## 🛠 Troubleshooting

Device Offline  
→ Check WiFi credentials  
→ Check internet connection  

Values Not Updating  
→ Verify Virtual Pins  
→ Check datastream datatype  

Relay / Output Not Working  
→ Verify wiring  
→ Check Active LOW / HIGH logic  

---

## 📌 Note

Each project README should clearly mention:
- Required Virtual Pins  
- Datastream type  
- Widget configuration  
- Update interval  

This file only covers common Blynk setup steps.

---

Happy Building 🚀
