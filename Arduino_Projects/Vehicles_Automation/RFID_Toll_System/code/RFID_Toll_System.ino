/*
====================================================
 Title   : RFID Toll System
 Author  : Sudhanshu Shukla
 GitHub  : https://github.com/ErSudhanshuShukla
 License : Released under the MIT License
====================================================
*/

#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

// Pin Definitions
#define SS_PIN 10        // RFID SDA / SS
#define RST_PIN 9        // RFID Reset
#define SERVO_PIN 7      // Servo control pin
#define BUZZER 8         // Buzzer pin

// Object Creation
MFRC522 rfid(SS_PIN, RST_PIN);
Servo lockServo;

// Master Tag UID (Authorized Card)
String masterTag = "626d5";  // Replace with your RFID UID

unsigned long lastAction = 0;  // Prevent rapid repeated scans

// Setup Function
void setup() {

  Serial.begin(9600);     // Start Serial Monitor
  SPI.begin();            // Initialize SPI bus
  rfid.PCD_Init();        // Initialize RFID module

  lockServo.attach(SERVO_PIN);
  lockServo.write(0);     // Gate locked position

  pinMode(BUZZER, OUTPUT);

  Serial.println("RFID Ready...");
}

// Main Loop
void loop() {

  // Check if new card is present
  if (!rfid.PICC_IsNewCardPresent()) return;
  if (!rfid.PICC_ReadCardSerial()) return;

  // Read Card UID
  String tagID = "";
  for (byte i = 0; i < rfid.uid.size; i++) {
    tagID += String(rfid.uid.uidByte[i], HEX);
  }

  Serial.print("UID: ");
  Serial.println(tagID);

  // Prevent repeated scans within 1.5 seconds
  if (millis() - lastAction < 1500) return;

  // Access Control Logic

  // Authorized Card
  if (tagID == masterTag) {
    Serial.println("ACCESS GRANTED");
    successBeep();        // Success tone

    lockServo.write(90);  // Open gate
    delay(2000);          // Keep gate open
    lockServo.write(0);   // Close gate
  }

  // Unauthorized Card
  else {
    Serial.println("ACCESS DENIED");
    errorBeep();          // Error tone
  }

  lastAction = millis();
}

// Buzzer Functions

// Success tone
void successBeep() {
  tone(BUZZER, 1000);
  delay(150);
  noTone(BUZZER);
}

// Error tone
void errorBeep() {
  tone(BUZZER, 300);
  delay(700);
  noTone(BUZZER);
}
