/*
====================================================
 Title   : IoT_Rain_Alarm
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
#define RAIN_PIN D5   // Rain sensor digital output (LOW = Rain)
#define BUZZER   D6   // Buzzer output

WiFiClientSecure client;

// -------- State Tracking Variable --------
int lastState = HIGH;   // HIGH = No rain detected (using pull-up)

// Setup
void setup() {

  Serial.begin(115200);

  pinMode(RAIN_PIN, INPUT_PULLUP);   // Sensor active LOW
  pinMode(BUZZER, OUTPUT);
  digitalWrite(BUZZER, LOW);

  // Connect to WiFi
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  // Skip certificate validation (for simplicity)
  client.setInsecure();

  Serial.println("Rain Alarm System Ready");
}

// Main Loop
void loop() {

  int state = digitalRead(RAIN_PIN);   // LOW = Rain detected

  // -------- Rain Started (Transition HIGH → LOW) --------
  if (state == LOW && lastState == HIGH) {

    digitalWrite(BUZZER, HIGH);      // Activate buzzer
    sendMsg("🌧️ Rain Started!");
    delay(3000);                     // Buzzer ON for 3 seconds
    digitalWrite(BUZZER, LOW);
  }

  // -------- Rain Stopped (Transition LOW → HIGH) --------
  if (state == HIGH && lastState == LOW) {

    sendMsg("☀️ Rain Stopped.");
  }

  lastState = state;
  delay(300);   // Small debounce delay
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
