/*
====================================================
 Title   : Smart Radar System
 Author  : Sudhanshu Shukla
 GitHub  : https://github.com/ErSudhanshuShukla
 License : Released under the MIT License
====================================================
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

// Pin Definitions
#define TRIG 9
#define ECHO 10
#define SERVO_PIN 8
#define BUZZER 11

#define ALERT_DISTANCE 20   // Alert distance in cm

// Object Initialization
Servo radarServo;                     // Servo object
LiquidCrystal_I2C lcd(0x27, 16, 2);    // I2C LCD (16x2, address 0x27)

// Function: Get Distance
long getDistance() {

  // Send trigger pulse (10 microseconds)
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  // Measure echo time (timeout 30ms)
  long duration = pulseIn(ECHO, HIGH, 30000);

  // If no echo received
  if (duration == 0) return -1;

  // Calculate distance (Speed of sound = 0.034 cm/µs)
  return duration * 0.034 / 2;
}

void setup() {

  // Configure pin modes
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(BUZZER, OUTPUT);

  // Attach servo to defined pin
  radarServo.attach(SERVO_PIN);

  // Initialize LCD
  lcd.init();
  lcd.backlight();

  // Startup message
  lcd.setCursor(0, 0);
  lcd.print("Ultrasonic Radar");
  lcd.setCursor(0, 1);
  lcd.print("Starting...");
  delay(1500);
  lcd.clear();
}

void loop() {

  // Sweep Left to Right
  for (int angle = 0; angle <= 180; angle += 3) {
    scan(angle);
  }

  // Sweep Right to Left
  for (int angle = 180; angle >= 0; angle -= 3) {
    scan(angle);
  }
}

// Function: Scan at Given Angle
void scan(int angle) {

  // Rotate servo to given angle
  radarServo.write(angle);
  delay(30);   // Small delay for stable reading

  // Measure distance
  long distance = getDistance();

  // Clear LCD before updating
  lcd.clear();

  // Display current angle
  lcd.setCursor(0, 0);
  lcd.print("Angle: ");
  lcd.print(angle);

  lcd.setCursor(0, 1);

  // If no object detected
  if (distance < 0) {
    lcd.print("Out of range");
    noTone(BUZZER);   // Turn buzzer OFF
  } 
  else {
    // Display distance
    lcd.print("Dist: ");
    lcd.print(distance);
    lcd.print(" cm");

    // Trigger alert if object within defined distance
    if (distance <= ALERT_DISTANCE) {
      tone(BUZZER, 1000);   // 1kHz alert tone
    } 
    else {
      noTone(BUZZER);       // Stop buzzer
    }
  }
}
