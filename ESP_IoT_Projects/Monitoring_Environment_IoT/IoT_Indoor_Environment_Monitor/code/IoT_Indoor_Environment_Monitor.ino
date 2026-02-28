/*
====================================================
 Title   : IoT_Indoor_Environment_Monitor
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
#include <DHT.h>

// -------- Pin Definitions --------
#define DHTPIN  D4      // DHT sensor connected to digital pin D4
#define DHTTYPE DHT11   // Sensor type (DHT11 or DHT22)

// -------- Blynk Virtual Pins --------
#define VP_TEMP V2      // Temperature data sent to V2
#define VP_HUM  V3      // Humidity data sent to V3

// -------- WiFi Credentials (Replace Before Upload) --------
char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

// -------- Objects --------
DHT dht(DHTPIN, DHTTYPE);   // Create DHT sensor object
BlynkTimer timer;           // Timer for periodic updates

// Function: Read DHT Sensor & Send Data to Blynk
void sendDHTData() {

  float temp = dht.readTemperature();  // Read temperature in °C
  float hum  = dht.readHumidity();     // Read humidity in %

  // Check if reading failed
  if (isnan(temp) || isnan(hum)) {
    Serial.println("DHT Sensor Error!");
    return;
  }

  // Print values to Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print(" °C | Humidity: ");
  Serial.print(hum);
  Serial.println(" %");

  // Send data to Blynk dashboard
  Blynk.virtualWrite(VP_TEMP, temp);
  Blynk.virtualWrite(VP_HUM, hum);
}

// Setup Function
void setup() {

  Serial.begin(115200);   // Start Serial communication
  dht.begin();            // Initialize DHT sensor

  // Connect to WiFi & Blynk Cloud
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  // Read sensor every 5 seconds
  timer.setInterval(5000L, sendDHTData);
}

// Main Loop
void loop() {
  Blynk.run();   // Handle Blynk communication
  timer.run();   // Execute scheduled tasks
}
