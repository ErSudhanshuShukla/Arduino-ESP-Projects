/*
====================================================
 Title   : Smart Distance Meter
 Author  : Sudhanshu Shukla
 GitHub  : https://github.com/ErSudhanshuShukla
 License : Released under the MIT License
====================================================
*/

#include <LiquidCrystal_I2C.h>

// Initialize I2C LCD (Address: 0x27, 16 columns, 2 rows)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Define Ultrasonic Sensor Pins
#define trig 2
#define echo 3

void setup() {
  Serial.begin(9600);      // Start Serial Monitor at 9600 baud rate
  
  lcd.init();              // Initialize LCD
  lcd.backlight();         // Turn ON LCD backlight

  pinMode(trig, OUTPUT);   // Set Trigger pin as OUTPUT
  pinMode(echo, INPUT);    // Set Echo pin as INPUT
}

void loop() {

  // ==============================
  // Send Ultrasonic Pulse
  // ==============================

  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);      // Send 10µs pulse
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  // ==============================
  // Measure Echo Duration
  // ==============================

  long duration = pulseIn(echo, HIGH);   // Time taken for echo to return

  // Calculate Distance (Speed of sound = 0.034 cm/µs)
  int distance = duration * 0.034 / 2;

  // ==============================
  // Display on Serial Monitor
  // ==============================

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // ==============================
  // Display on LCD
  // ==============================

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Distance:");
  
  lcd.setCursor(0, 1);
  lcd.print(distance);
  lcd.print(" cm");

  delay(500);   // Small delay for stable readings
}
