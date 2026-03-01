# 🤖 Telegram Bot Setup Guide (ESP8266 / ESP32)
> *This setup works for all Telegram-based IoT projects in this repository.*

This guide explains how to:
- Create a Telegram Bot  
- Get BOT_TOKEN  
- Get CHAT_ID  
- Add credentials in Arduino code  
---
## 🟢 Step 1: Create Telegram Bot

1. Open Telegram  
2. Search **@BotFather**  
3. Type:

```
/newbot
```

4. Enter:
   - Bot Name (example: IoT Alert Bot)
   - Username (must end with `bot`)
     - Example: iot_alert_bot

5. You will receive:

```
Bot Token: 123456789:ABCxyz.....
```
✅ Copy this token.

---
## 🟢 Step 2: Get Your CHAT ID

1. Open Telegram  
2. Search your new bot  
3. Click **Start**

4. Open in browser:

```
https://api.telegram.org/botYOUR_BOT_TOKEN/getUpdates
```

Replace `YOUR_BOT_TOKEN` with your real token.

5. Find:

```
"chat":{"id":1234567890
```

✅ That number is your **CHAT_ID**

---
## 🟢 Step 3: Add in Arduino Code

Replace in your project:

```cpp
String BOT_TOKEN = "YOUR_BOT_TOKEN";
String CHAT_ID   = "YOUR_CHAT_ID";

const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";
```
---
## 🟢 Step 4: Dependencies

- Install **ESP8266 Board Package**:

  - Arduino IDE → Preferences → Additional Boards Manager URLs

```
http://arduino.esp8266.com/stable/package_esp8266com_index.json
```

- Then install from Boards Manager:

  - Tools → Board → Boards Manager → [ESP8266 by ESP8266 Community](https://github.com/esp8266/Arduino)

---
## 📌 Done

Now your ESP8266 can send messages to your Telegram chat.

Example:

```cpp
sendMsg("Hello from ESP8266!");
```
---
## 🔐 Important

- Never share BOT_TOKEN publicly  
- Revoke token from @BotFather if leaked  
- Keep WiFi credentials private  
