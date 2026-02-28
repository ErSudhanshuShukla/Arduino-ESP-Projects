/*
====================================================
 Title   : Speed Measurement System
 Author  : Sudhanshu Shukla
 GitHub  : https://github.com/ErSudhanshuShukla
 License : Released under the MIT License
====================================================
*/

#include <Wire.h>                  // I2C communication
#include <LiquidCrystal_I2C.h>     // I2C LCD library

// Initialize I2C LCD (Address 0x27, 16 columns, 2 rows)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Time & Speed Variables
unsigned long timer1;   // Time when first sensor triggers
unsigned long timer2;   // Time when second sensor triggers

float Time;             // Time difference (seconds)
float distance = 5.0;   // Distance between sensors (meters)
float speed;            // Calculated speed (km/h)

// Sensor Flags
int flag1 = 0;          // Sensor 1 triggered flag
int flag2 = 0;          // Sensor 2 triggered flag

// Pin Definitions
int ir_s1 = A0;         // IR Sensor 1
int ir_s2 = A1;         // IR Sensor 2
int buzzer = 11;        // Buzzer pin

// Setup Function
void setup() {

  pinMode(ir_s1, INPUT);       // IR sensor 1 input
  pinMode(ir_s2, INPUT);       // IR sensor 2 input
  pinMode(buzzer, OUTPUT);     // Buzzer output

  lcd.init();                  // Initialize LCD
  lcd.backlight();             // Turn on backlight

  // Display welcome message
  lcd.setCursor(0, 0);
  lcd.print("     Speed     ");
  lcd.setCursor(0, 1);
  lcd.print("    Detector    ");
  delay(2000);
  lcd.clear();
}

// Main Loop
void loop() {

  // When first IR sensor detects vehicle
  if (digitalRead(ir_s1) == LOW && flag1 == 0) {
    timer1 = millis();     // Store current time
    flag1 = 1;             // Mark sensor 1 triggered
  }

  // When second IR sensor detects vehicle
  if (digitalRead(ir_s2) == LOW && flag2 == 0) {
    timer2 = millis();     // Store current time
    flag2 = 1;             // Mark sensor 2 triggered
  }

  // If both sensors are triggered
  if (flag1 == 1 && flag2 == 1) {

    // Calculate time difference
    if (timer1 > timer2)
      Time = timer1 - timer2;
    else
      Time = timer2 - timer1;

    Time = Time / 1000.0;      // Convert milliseconds to seconds

    // Calculate speed
    speed = distance / Time;   // m/s
    speed = speed * 3.6;       // Convert to km/h
  }

  // LCD Display Logic

  // If speed not calculated yet
  if (speed == 0) {
    lcd.setCursor(0, 1);
    if (flag1 == 0 && flag2 == 0)
      lcd.print("No car detected ");
    else
      lcd.print("Searching...    ");
  }
  else {
    lcd.clear();

    // Display speed
    lcd.setCursor(0, 0);
    lcd.print("Speed: ");
    lcd.print(speed, 1);
    lcd.print(" Km/H");

    lcd.setCursor(0, 1);

    // Overspeed alert
    if (speed > 60) {
      lcd.print("Over Speeding!");
      digitalWrite(buzzer, HIGH);   // Activate buzzer
    } 
    else {
      lcd.print("Normal Speed  ");
    }

    delay(3000);   // Show result for 3 seconds

    // Reset values for next measurement
    digitalWrite(buzzer, LOW);
    speed = 0;
    flag1 = 0;
    flag2 = 0;
    lcd.clear();
  }
}
