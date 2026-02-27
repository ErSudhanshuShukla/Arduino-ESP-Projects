/*
====================================================
 Title   : Sound Level Meter
 Author  : Sudhanshu Shukla
 GitHub  : https://github.com/ErSudhanshuShukla
 License : Released under the MIT License
====================================================
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// =============================
// LCD Initialization
// =============================
// I2C Address: 0x27 (change to 0x3F if not working)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// =============================
// Pin Definition
// =============================
int mic = A0;   // Microphone analog output connected to A0

void setup() {

  // Initialize LCD
  lcd.init();
  lcd.backlight();

  // Welcome Message
  lcd.setCursor(0, 0);
  lcd.print("Sound Meter");
  lcd.setCursor(0, 1);
  lcd.print("Initializing");
  delay(1500);

  lcd.clear();
}

void loop() {

  // =============================
  // Read Microphone Value
  // =============================
  int raw = analogRead(mic);   // Read analog signal (0–1023)

  // =============================
  // Convert to Approximate dB
  // =============================
  // Mapping 0–1023 → 30–120 dB (approximation only)
  int dB = map(raw, 0, 1023, 30, 120);

  // =============================
  // Display on LCD
  // =============================
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Sound Level:");

  lcd.setCursor(0, 1);
  lcd.print(dB);
  lcd.print(" dB");

  delay(300);   // Small delay for stable reading
}
