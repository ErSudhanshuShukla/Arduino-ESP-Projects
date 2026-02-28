/*
====================================================
 Title   : IoT_Street_Light
 Author  : Sudhanshu Shukla
 GitHub  : https://github.com/ErSudhanshuShukla
 License : Released under the MIT License
====================================================
*/

// -------- Blynk Configuration (Keep Credentials Private) --------
#define BLYNK_TEMPLATE_ID   "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "YOUR_TEMPLATE_NAME"
#define BLYNK_AUTH_TOKEN    "YOUR_AUTH_TOKEN"

#define BLYNK_PRINT Serial

// -------- Libraries --------
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// -------- WiFi Credentials (Replace Before Upload) --------
char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

// -------- Pin Definitions --------
const int LDR_PIN   = A0;   // LDR connected to analog pin
const int RELAY_PIN = D5;   // Relay controlling street light

// -------- Relay Logic (Active LOW) --------
const int RELAY_ON  = LOW;
const int RELAY_OFF = HIGH;

// -------- Control Variables --------
bool manualMode = false;     // false = AUTO (LDR), true = MANUAL (Blynk)
int ldrThreshold = 400;      // Adjust based on light conditions

// Setup Function
void setup() {

  Serial.begin(9600);

  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, RELAY_OFF);  // Ensure light OFF initially

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

// Main Loop
void loop() {

  Blynk.run();

  // -------- AUTO MODE (LDR Based Control) --------
  if (!manualMode) {

    int ldrValue = analogRead(LDR_PIN);

    Serial.print("LDR Value = ");
    Serial.println(ldrValue);

    if (ldrValue > ldrThreshold) {
      digitalWrite(RELAY_PIN, RELAY_ON);     // Dark → Light ON
      Blynk.virtualWrite(V1, 1);             // Sync app
    } else {
      digitalWrite(RELAY_PIN, RELAY_OFF);    // Bright → Light OFF
      Blynk.virtualWrite(V1, 0);             // Sync app
    }
  }
}



// Mode Control (Virtual Pin V0)
// 0 = AUTO MODE
// 1 = MANUAL MODE
BLYNK_WRITE(V0) {

  int mode = param.asInt();

  if (mode == 1) {
    manualMode = true;
    Serial.println("MODE: MANUAL");
  } else {
    manualMode = false;
    Serial.println("MODE: AUTO");
  }
}

// Relay Control (Virtual Pin V1)
// Works only in MANUAL MODE
BLYNK_WRITE(V1) {

  int relayState = param.asInt();

  if (manualMode) {

    if (relayState == 1) {
      digitalWrite(RELAY_PIN, RELAY_ON);
      Serial.println("Relay ON (Manual)");
    } else {
      digitalWrite(RELAY_PIN, RELAY_OFF);
      Serial.println("Relay OFF (Manual)");
    }

  } else {
    // Prevent manual override in AUTO mode
    Blynk.virtualWrite(V1, digitalRead(RELAY_PIN) == RELAY_ON ? 1 : 0);
  }
}
