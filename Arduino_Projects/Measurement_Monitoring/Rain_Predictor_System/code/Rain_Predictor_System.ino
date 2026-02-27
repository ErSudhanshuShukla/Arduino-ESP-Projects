/*
====================================================
 Title   : Weather Forecast System
 Author  : Sudhanshu Shukla
 GitHub  : https://github.com/ErSudhanshuShukla
 License : Released under the MIT License
====================================================
*/

#include <Wire.h>
#include <Adafruit_BMP280.h>
#include <LiquidCrystal_I2C.h>

Adafruit_BMP280 bmp;               // BMP280 pressure sensor (I2C mode)
LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C LCD (Address 0x27, 16x2 display)

float pressureNow;      // Current pressure value (hPa)
float pressureOld;      // Previous pressure value (hPa)
unsigned long lastRead = 0;  // Time tracking for pressure updates
String forecast = "CLEAR";   // Weather forecast result

void setup() {

  lcd.init();           // Initialize LCD
  lcd.backlight();      // Turn on LCD backlight

  // Initialize BMP280 sensor
  if (!bmp.begin(0x76)) {   // Try 0x77 if not detected
    lcd.setCursor(0, 0);
    lcd.print("BMP280 ERROR");
    while (1);  // Stop program if sensor not found
  }

  // Welcome Screen
  lcd.setCursor(1, 0);
  lcd.print("SMART WEATHER");
  lcd.setCursor(2, 1);
  lcd.print("RAIN FORECAST");
  delay(2000);

  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("Loading...");
  delay(1500);

  // Store initial pressure value
  pressureOld = bmp.readPressure() / 100.0; // Convert Pa to hPa

  lcd.clear();
}

void loop() {

  // Read pressure every 30 seconds (demo interval)
  if (millis() - lastRead > 30000) {
    lastRead = millis();

    pressureNow = bmp.readPressure() / 100.0;  // Read pressure in hPa
    float diff = pressureNow - pressureOld;   // Compare with previous reading

    // Simple weather prediction logic based on pressure trend
    if (diff < -2)
      forecast = "RAIN LIKELY";
    else if (diff < -1)
      forecast = "CLOUDY";
    else if (diff > 1)
      forecast = "SUNNY";
    else
      forecast = "CLEAR";

    pressureOld = pressureNow;  // Update old pressure value
  }

  // ============================
  // Screen 1: Pressure Display
  // ============================
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("PRESSURE LEVEL");
  lcd.setCursor(3, 1);
  lcd.print(pressureNow);
  lcd.print(" hPa");
  delay(2000);

  // ============================
  // Screen 2: Weather Status
  // ============================
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("WEATHER STATUS");
  lcd.setCursor(1, 1);
  lcd.print(forecast);
  delay(2000);

  // ============================
  // Screen 3: Alert Message
  // ============================
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("FORECAST:");

  lcd.setCursor(2, 1);

  if (forecast == "RAIN LIKELY") {
    lcd.print("RAIN ALERT!");
  } 
  else if (forecast == "SUNNY") {
    lcd.print("SUNNY DAY");
  } 
  else {
    lcd.print("CLEAR SKY");
  }

  delay(2000);
}
