/*
====================================================
 Title   : Smart Bluetooth Display
 Author  : Sudhanshu Shukla
 GitHub  : https://github.com/ErSudhanshuShukla
 License : Released under the MIT License
====================================================
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>

// HC-05 Bluetooth module connected via SoftwareSerial
SoftwareSerial bt(10, 11);   // RX, TX (Arduino 10 <- HC-05 TX, Arduino 11 -> HC-05 RX)

// I2C LCD (16x2) display
LiquidCrystal_I2C lcd(0x27, 16, 2);

String notice = "";     // Stores the final notice message
String buffer = "";     // Temporary buffer while receiving message

unsigned long lastScrollTime = 0;  // For non-blocking scroll timing
int scrollIndex = 0;               // Current scroll position
const int scrollDelay = 1500;      // Scroll speed (ms) – slow & readable

void setup() {
  bt.begin(9600);        // Start Bluetooth communication (HC-05 default baud rate)

  lcd.init();            // Initialize LCD
  lcd.backlight();      // Turn ON LCD backlight

  // Welcome message
  lcd.setCursor(0, 0);
  lcd.print("SMART DISPLAY   ");
  lcd.setCursor(0, 1);
  lcd.print("SEND NOTICE     ");
}

void loop() {

  // 🔹 READ BLUETOOTH MESSAGE CHARACTER BY CHARACTER
  while (bt.available()) {
    char ch = bt.read();

    if (ch == '\n') {                 // ENTER key = message complete
      notice = buffer;               // Replace old notice with new message
      buffer = "";                   // Clear buffer for next message
      scrollIndex = 0;               // Reset scrolling index

      lcd.setCursor(0, 0);
      lcd.print("NOTICE:         ");

      // IF NOTICE <= 16 CHARACTERS → DISPLAY WITHOUT SCROLLING
      if (notice.length() <= 16) {
        lcd.setCursor(0, 1);
        lcd.print("                ");
        lcd.setCursor(0, 1);
        lcd.print(notice);
      }
      else {
        // Add spaces at the end to create smooth scrolling effect
        notice += "                ";
      }
    }
    else if (ch != '\r') {            // Ignore carriage return
      buffer += ch;                  // Keep building the message
    }
  }

  // 🔹 SCROLL ONLY IF NOTICE LENGTH > 16 CHARACTERS
  if (notice.length() > 16) {
    unsigned long now = millis();

    if (now - lastScrollTime >= scrollDelay) {
      lastScrollTime = now;

      lcd.setCursor(0, 0);
      lcd.print("NOTICE:         ");

      // Display a 16-character window of the notice string
      lcd.setCursor(0, 1);
      lcd.print(notice.substring(scrollIndex, scrollIndex + 16));

      scrollIndex++;   // Move window forward

      // Restart scrolling when end is reached
      if (scrollIndex > notice.length() - 16) {
        scrollIndex = 0;
      }
    }
  }
}
