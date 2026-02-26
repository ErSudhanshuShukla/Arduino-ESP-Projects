/*
====================================================
 Title   : Air Quality Monitor
 Author  : Sudhanshu Shukla
 GitHub  : https://github.com/ErSudhanshuShukla
 License : Released under the MIT License
====================================================
*/

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);   // 16x2 I2C LCD (Address: 0x27)

int airPin = A0;   // MQ-135 air quality sensor connected to analog pin A0

void setup() {
  lcd.init();        // Initialize LCD
  lcd.backlight();  // Turn ON LCD backlight
}

void loop() {
  int sensorValue = analogRead(airPin);   // Read raw sensor value (0–1023)

  // Convert MQ135 reading to AQI (approximate mapping for demo purpose)
  int aqi = map(sensorValue, 0, 1023, 0, 500);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("AQI: ");
  lcd.print(aqi);

  lcd.setCursor(0, 1);

  // Display air quality category based on AQI value
  if (aqi <= 50) {
    lcd.print("GOOD");
  }
  else if (aqi <= 100) {
    lcd.print("SATISFACTORY");
  }
  else if (aqi <= 200) {
    lcd.print("MODERATE");
  }
  else if (aqi <= 300) {
    lcd.print("POOR");
  }
  else if (aqi <= 400) {
    lcd.print("VERY POOR");
  }
  else {
    lcd.print("SEVERE");
  }

  delay(1500);   // Refresh display every 1.5 seconds
}
