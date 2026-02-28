/*
====================================================
 Title   : IoT_Home_Automation
 Author  : Sudhanshu Shukla
 GitHub  : https://github.com/ErSudhanshuShukla
 License : Released under the MIT License
====================================================
*/

// -------- Blynk Configuration (Keep Credentials Private) --------
#define BLYNK_TEMPLATE_ID   "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "YOUR_TEMPLATE_NAME"
#define BLYNK_AUTH_TOKEN    "YOUR_AUTH_TOKEN"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// -------- WiFi Credentials (Replace Before Upload) --------
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

// -------- Pin Definition --------
const int RELAY_PIN = D5;   // Relay connected to D5

// -------- Relay Type Configuration --------
// true  -> relay turns ON when pin is LOW  (Active-LOW)
// false -> relay turns ON when pin is HIGH (Active-High)
const bool RELAY_ACTIVE_LOW = true;

// Function: Apply Relay State Based on Relay Type
void applyRelay(bool on) {
  if (RELAY_ACTIVE_LOW)
    digitalWrite(RELAY_PIN, on ? LOW : HIGH);
  else
    digitalWrite(RELAY_PIN, on ? HIGH : LOW);
}

// Setup Function
void setup() {
  Serial.begin(115200);
  delay(200);

  Serial.println();
  Serial.println("Starting NodeMCU Single Relay (Blynk)");

  pinMode(RELAY_PIN, OUTPUT);

  // Safe default: Turn OFF relay on boot
  applyRelay(false);

  // Connect to WiFi & Blynk Cloud
  Blynk.begin(auth, ssid, pass);

  Serial.println("Connected to Blynk");
}

// Blynk Virtual Pin Handler (V1)
BLYNK_WRITE(V1) {
  int val = param.asInt();  // 0 or 1 from Blynk switch
  bool wantOn = (val == 1);

  applyRelay(wantOn);

  Serial.printf(
    "Blynk V1=%d -> Relay set to %s (RELAY_ACTIVE_LOW=%s)\n",
    val,
    wantOn ? "ON" : "OFF",
    RELAY_ACTIVE_LOW ? "true" : "false"
  );
}

// Main Loop
void loop() {
  Blynk.run();   // Handle Blynk communication
}
