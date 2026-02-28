/*
====================================================
 Title   : Weather Station
 Author  : Sudhanshu Shukla
 GitHub  : https://github.com/ErSudhanshuShukla
 License : Released under the MIT License
====================================================
*/

#include <DHT.h>
#include <LiquidCrystal_I2C.h>

// Sensor Configuration
#define DHTPIN 13        // DHT11 Data Pin connected to Digital Pin 13
#define DHTTYPE DHT11    // Define sensor type (DHT11)

DHT dht(DHTPIN, DHTTYPE);        // Create DHT object
LiquidCrystal_I2C lcd(0x27, 16, 2);  // I2C LCD (16x2, Address 0x27)

void setup() {

  Serial.begin(9600);   // Start Serial Monitor

  dht.begin();          // Initialize DHT sensor
  lcd.init();           // Initialize LCD
  lcd.backlight();      // Turn ON LCD backlight

  // Welcome Screen
  lcd.setCursor(0, 0);
  lcd.print("Weather Station");
  lcd.setCursor(0, 1);
  lcd.print("Initializing...");
  delay(1500);
  lcd.clear();
}

void loop() {

  // Read Sensor Data
  float h = dht.readHumidity();      // Read Humidity (%)
  float t = dht.readTemperature();   // Read Temperature (°C)

  // Display on LCD
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print(" C");

  lcd.setCursor(0, 1);
  lcd.print("Hum: ");
  lcd.print(h);
  lcd.print(" %");

  // Display on Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" C   Humidity: ");
  Serial.print(h);
  Serial.println(" %");

  delay(2000);   // Update every 2 seconds
}
