/*
====================================================
 Title   : IoT Plant Irrigation System 
 Author  : Sudhanshu Shukla
 GitHub  : https://github.com/ErSudhanshuShukla
 License : Released under the MIT License
====================================================
*/

// -------- Blynk Configuration (Keep Credentials Private) --------
#define BLYNK_TEMPLATE_ID   "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "YOUR_TEMPLATE_NAME"
#define BLYNK_AUTH_TOKEN    "YOUR_AUTH_TOKEN"

#define BLYNK_PRINT Serial   // Enable Blynk debug messages

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// -------- Pin Definitions --------
#define SOIL_PIN  A0   // Soil moisture sensor analog output
#define RELAY_PIN D5   // Relay control pin (Water Pump)

// -------- Blynk Virtual Pins --------
#define VP_RELAY V1    // Relay control from Blynk app
#define VP_SOIL  V4    // Soil moisture percentage display

// -------- WiFi Credentials (Replace Before Upload) --------
char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

// -------- Calibration & Settings --------
int soilWet = 425;           // Sensor value when soil is fully wet
int soilDry = 900;           // Sensor value when soil is completely dry
float moistureThreshold = 40.0;  // Moisture % below which pump turns ON
bool RELAY_ACTIVE_LOW = true;    // Set true for Active LOW relay

bool relayState = false;     // Stores current relay state
BlynkTimer timer;            // Timer for periodic updates


// Convert raw soil value (0–1023) into percentage (0–100%)
float soilPercent() {
  int raw = analogRead(SOIL_PIN);
  float pct = (soilDry - raw) * 100.0 / (soilDry - soilWet);
  return constrain(pct, 0, 100);
}

// Relay Control Function
void setRelay(bool on) {
  relayState = on;
  digitalWrite(RELAY_PIN, (RELAY_ACTIVE_LOW ? !on : on));
}

// Manual Relay Control from Blynk App (V1)
BLYNK_WRITE(VP_RELAY) {
  setRelay(param.asInt());
}

// Send Soil Data & Automatic Irrigation Logic
void sendSoilData() {

  float moisture = soilPercent();

  Serial.print("Soil Moisture: ");
  Serial.print(moisture);
  Serial.println("%");

  // Send values to Blynk dashboard
  Blynk.virtualWrite(VP_SOIL, moisture);
  Blynk.virtualWrite(VP_RELAY, relayState);

  // Automatic pump control
  if (moisture < moistureThreshold)
    setRelay(true);     // Dry soil → Pump ON
  else
    setRelay(false);    // Wet soil → Pump OFF
}

// Setup Function
void setup() {

  Serial.begin(115200);

  pinMode(RELAY_PIN, OUTPUT);
  setRelay(false);   // Ensure pump OFF at startup

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  // Run soil monitoring every 5 seconds
  timer.setInterval(5000L, sendSoilData);
}

// Loop Function
void loop() {
  Blynk.run();
  timer.run();
}
