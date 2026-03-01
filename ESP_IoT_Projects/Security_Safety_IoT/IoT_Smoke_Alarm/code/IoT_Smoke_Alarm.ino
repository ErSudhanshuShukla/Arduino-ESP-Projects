/*
====================================================
 Title   : IoT_Smoke_Alarm
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
#define SMOKE_PIN A0    // MQ2 analog output
#define BUZZER    D5    // Buzzer output

// -------- Threshold Settings --------
int threshold  = 400;   // Smoke detected level
int clearLevel = 350;   // Smoke cleared level

// -------- State Variables --------
unsigned long lastAlertTime = 0;
bool smokeWasHigh = false;

WiFiClientSecure client;

// -------- Send Telegram Message --------
void sendTelegram(String msg) {

  client.setInsecure();

  if (!client.connect("api.telegram.org", 443)) {
    Serial.println("❌ Telegram connection failed");
    return;
  }

  String url = "/bot" + BOT_TOKEN +
               "/sendMessage?chat_id=" + CHAT_ID +
               "&text=" + msg;

  client.println("GET " + url + " HTTP/1.1");
  client.println("Host: api.telegram.org");
  client.println("Connection: close");
  client.println();

  Serial.println("📤 Telegram Message Sent: " + msg);
}

// -------- Setup --------
void setup() {

  Serial.begin(9600);
  Serial.println("🔥 MQ2 Smoke Detector + Telegram");

  pinMode(BUZZER, OUTPUT);
  digitalWrite(BUZZER, LOW);

  // Connect to WiFi
  Serial.print("📶 Connecting WiFi");
  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(200);
    Serial.print(".");
  }

  Serial.println("\n✅ WiFi Connected!");
  Serial.println(WiFi.localIP());
}

// -------- Main Loop --------
void loop() {

  int smoke = analogRead(SMOKE_PIN);

  // Always show smoke value
  Serial.print("Smoke Value: ");
  Serial.println(smoke);

  unsigned long now = millis();

  // -------- 🚨 SMOKE DETECTED --------
  if (smoke > threshold && (now - lastAlertTime > 60000)) {

    Serial.println("🚨 Smoke Detected!");
    sendTelegram("🚨 Smoke Detected!");

    Serial.println("🔊 Buzzer ON (10 sec)");
    digitalWrite(BUZZER, HIGH);
    delay(10000);
    digitalWrite(BUZZER, LOW);
    Serial.println("🔇 Buzzer OFF");

    lastAlertTime = now;
    smokeWasHigh = true;
  }

  // -------- ✅ SMOKE CLEARED --------
  if (smokeWasHigh && smoke < clearLevel) {

    Serial.println("✅ Smoke Cleared!");
    sendTelegram("✅ Smoke Cleared!");
    smokeWasHigh = false;
  }

  delay(500);
}
