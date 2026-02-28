/*
====================================================
 Title   : IoT_Water_Level_Monitor
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

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// -------- WiFi Credentials (Replace Before Upload) --------
char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

// -------- Pin Definitions --------
#define TRIG D5       // Ultrasonic Trigger Pin
#define ECHO D6       // Ultrasonic Echo Pin

#define RED_LED   D7  // Low Water Indicator
#define GREEN_LED D8  // Full Water Indicator

// -------- Tank Settings --------
int tankHeightCm = 30;   // Total tank height in cm

long duration;
int distanceCm;
int waterLevelPercent;

BlynkTimer timer;

// Function: Measure Water Level & Send to Blynk
void sendWaterLevel() {

  // Generate ultrasonic pulse
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  // Measure echo duration (timeout: 30ms)
  duration = pulseIn(ECHO, HIGH, 30000);

  // If no echo received, assume tank empty
  if (duration == 0) {
    distanceCm = tankHeightCm;
  } else {
    distanceCm = (int)(duration * 0.034 / 2.0);
  }

  // Calculate water height
  int waterHeightCm = tankHeightCm - distanceCm;

  // Convert to percentage
  waterLevelPercent = map(waterHeightCm, 0, tankHeightCm, 0, 100);

  // Limit between 0–100%
  if (waterLevelPercent < 0) waterLevelPercent = 0;
  if (waterLevelPercent > 100) waterLevelPercent = 100;

  // Send data to Blynk (Virtual Pin V7)
  Blynk.virtualWrite(V7, waterLevelPercent);

  // -------- LED Indicator Logic --------
  if (waterLevelPercent < 20) {
    digitalWrite(RED_LED, HIGH);     // Low water
    digitalWrite(GREEN_LED, LOW);
  }
  else if (waterLevelPercent > 80) {
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);   // Tank almost full
  }
  else {
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, LOW);    // Medium level
  }

  // Serial Output
  Serial.print("Water Level: ");
  Serial.print(waterLevelPercent);
  Serial.println("%");
}

// Setup Function
void setup() {

  Serial.begin(9600);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, LOW);

  // Connect to WiFi & Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  // Update water level every 1 second
  timer.setInterval(1000L, sendWaterLevel);
}

// Main Loop
void loop() {
  Blynk.run();
  timer.run();
}
