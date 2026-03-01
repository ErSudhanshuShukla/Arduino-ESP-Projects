/*
====================================================
 Title   : IoT_Security_Alarm
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
#define TRIG   D5   // Ultrasonic Trigger pin
#define ECHO   D6   // Ultrasonic Echo pin
#define BUZZER D7   // Alarm buzzer
#define LED    D8   // Visual indicator LED

WiFiClientSecure client;

// -------- Intruder Control Variable --------
bool intruderSent = false;   // Prevent repeated alerts

// -------- Distance Measurement Function --------
int measureDistance() {

  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  long duration = pulseIn(ECHO, HIGH, 30000);

  if (duration == 0) return 999;  // No object detected

  return duration * 0.034 / 2;    // Convert to cm
}

// -------- Send Telegram Message --------
void sendTelegram(String msg) {

  if (WiFi.status() != WL_CONNECTED) return;

  client.setInsecure();

  if (!client.connect("api.telegram.org", 443)) return;

  String url = "/bot" + BOT_TOKEN +
               "/sendMessage?chat_id=" + CHAT_ID +
               "&text=" + msg;

  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: api.telegram.org\r\n" +
               "Connection: close\r\n\r\n");

  delay(200);
  client.stop();
}

// -------- Setup --------
void setup() {

  Serial.begin(115200);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(LED, OUTPUT);

  digitalWrite(BUZZER, LOW);
  digitalWrite(LED, LOW);

  // Connect to WiFi
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  Serial.println("Security Alarm System Ready");
}

// -------- Main Loop --------
void loop() {

  int dist = measureDistance();
  Serial.println(dist);

  // -------- INTRUDER DETECTED --------
  if (dist < 10 && !intruderSent) {

    sendTelegram("🚨 Someone is Nearby 🦹");

    // Activate buzzer + LED for 5 seconds
    digitalWrite(BUZZER, HIGH);
    digitalWrite(LED, HIGH);
    delay(5000);
    digitalWrite(BUZZER, LOW);
    digitalWrite(LED, LOW);

    intruderSent = true;
  }

  // -------- AREA CLEAR --------
  if (intruderSent && dist > 10) {

    sendTelegram("✅ Area Clear.");
    intruderSent = false;
  }

  delay(300);   // Small polling delay
}
