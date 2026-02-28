/*
====================================================
 Title   : Smart Object Counter
 Author  : Sudhanshu Shukla
 GitHub  : https://github.com/ErSudhanshuShukla
 License : Released under the MIT License
====================================================
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize I2C LCD (Address: 0x27, 16x2 Display)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Define Pin Connections
#define TRIG 8
#define ECHO 9
#define BUZZER 11

long duration;              // Stores echo pulse duration
int distance;               // Calculated distance (cm)
int count = 0;              // Object count
bool objectDetected = false; // Flag to avoid multiple counts

void setup() {

  lcd.init();          // Initialize LCD
  lcd.backlight();     // Turn ON backlight

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(BUZZER, OUTPUT);

  // Welcome Message
  lcd.setCursor(0,0);
  lcd.print("Object Counter");
  delay(1000);
  lcd.clear();

  // Initial Screen
  lcd.setCursor(0,0);
  lcd.print("No Object");
  lcd.setCursor(0,1);
  lcd.print("Count: 0");
}

void loop() {

  // Send Ultrasonic Trigger Pulse
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  // Read Echo with Timeout
  duration = pulseIn(ECHO, HIGH, 25000); // 25ms timeout

  if (duration == 0) {
    distance = 999;   // No object detected
  } 
  else {
    distance = duration * 0.034 / 2;  // Distance formula
  }

  // Object Detection Logic
  // If object is very close (< 3 cm) and not already counted
  if (distance < 3 && !objectDetected) {

    objectDetected = true;  // Prevent double counting
    count++;                // Increase object count

    // Buzzer Alert
    digitalWrite(BUZZER, HIGH);
    delay(200);
    digitalWrite(BUZZER, LOW);

    // Display Detection
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Object Detected");

    lcd.setCursor(0,1);
    lcd.print("Count: ");
    lcd.print(count);

    delay(2000);
  }

  // Reset When Object Leaves
  if (distance > 6 && objectDetected) {

    objectDetected = false;  // Ready for next object

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("No Object");

    lcd.setCursor(0,1);
    lcd.print("Count: ");
    lcd.print(count);
  }
}
