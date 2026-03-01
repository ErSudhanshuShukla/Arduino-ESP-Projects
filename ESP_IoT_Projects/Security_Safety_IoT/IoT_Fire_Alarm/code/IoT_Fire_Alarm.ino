/*
====================================================
 Title   : IoT_Fire_Alarm
 Author  : Sudhanshu Shukla
 GitHub  : https://github.com/ErSudhanshuShukla
 License : Released under the MIT License
====================================================
*/

// -------- Libraries --------
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>

// -------- WiFi Credentials (Replace Before Upload) --------
const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";

// -------- Telegram Bot Credentials (Keep Private) --------
String BOT_TOKEN = "YOUR_BOT_TOKEN";
String CHAT_ID   = "YOUR_CHAT_ID";

// -------- Pin Configuration --------
#define FIRE_PIN D5   // Fire sensor digital output (LOW = Fire)
#define BUZZER   D6   // Buzzer output

WiFiClientSecure client;

// -------- Alert Control Variables --------
int lastState = HIGH;                // HIGH = No fire detected
unsigned long lastAlert = 0;
const unsigned long repeatTime = 30000UL;  // 30 seconds

// Setup
void setup() {

  Serial.begin(115200);

  pinMode(FIRE_PIN, INPUT);
  pinMode(BUZZER, OUTPUT);
  digitalWrite(BUZZER, LOW);

  // Connect to WiFi
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  // Skip certificate validation (for simplicity)
  client.setInsecure();

  Serial.println("System Ready");
}

// Main Loop
void loop() {

  int state = digitalRead(FIRE_PIN);   // LOW = Fire detected
  unsigned long now = millis();

  // -------- Fire Detected (Transition HIGH → LOW) --------
  if (state == LOW && lastState == HIGH) {

    digitalWrite(BUZZER, HIGH);   // Continuous alarm
    sendMsg("🔥 Fire Detected!");
    lastAlert = now;
  }

  // -------- Repeat Alert Every 30 Seconds --------
  if (state == LOW && (now - lastAlert >= repeatTime)) {

    sendMsg("🔥 Fire Still Detected!");
    lastAlert = now;
  }

  // -------- Fire Cleared (Transition LOW → HIGH) --------
  if (state == HIGH && lastState == LOW) {

    digitalWrite(BUZZER, LOW);
    sendMsg("✅ Fire Cleared.");
    lastAlert = 0;
  }

  lastState = state;
  delay(200);   // Small debounce delay
}

// Send Telegram Message
void sendMsg(String txt) {

  if (!client.connect("api.telegram.org", 443)) {
    return;
  }

  String url = "/bot" + BOT_TOKEN +
               "/sendMessage?chat_id=" + CHAT_ID +
               "&text=" + txt;

  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: api.telegram.org\r\n" +
               "Connection: close\r\n\r\n");
}
