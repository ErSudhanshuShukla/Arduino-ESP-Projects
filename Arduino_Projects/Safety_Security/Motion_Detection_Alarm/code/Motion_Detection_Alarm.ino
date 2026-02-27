/*
====================================================
 Title   : Motion Detection Alarm
 Author  : Sudhanshu Shukla
 GitHub  : https://github.com/ErSudhanshuShukla
 License : Released under the MIT License
====================================================
*/

// =============================
// Pin Definitions
// =============================
int pirPin = 2;      // PIR OUT → Digital Pin 2
int buzzer = 11;     // Buzzer → Pin 11
int led = 13;        // LED → Pin 13

// =============================
// System Configuration
// =============================
unsigned long alarmDuration = 5000UL;  // Alarm ON time (5 seconds)
unsigned long resetLowSecs = 2UL;      // PIR must stay LOW for 2 seconds before reset

// =============================
// State Variables
// =============================
bool alarmActive = false;
unsigned long alarmStart = 0;

bool waitingForLow = false;
unsigned long lowStart = 0;

void setup() {

  Serial.begin(9600);

  pinMode(pirPin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);

  digitalWrite(buzzer, LOW);
  digitalWrite(led, LOW);

  Serial.println("PIR Robust Motion Detection System Started");
}

void loop() {

  int v = digitalRead(pirPin);   // Read PIR state (HIGH / LOW)
  unsigned long now = millis();

  // =========================================
  // If Alarm is Active → Check Timeout
  // =========================================
  if (alarmActive) {

    if (now - alarmStart >= alarmDuration) {

      // Stop alarm after duration
      alarmActive = false;
      digitalWrite(buzzer, LOW);
      digitalWrite(led, LOW);

      // Enter reset phase
      waitingForLow = true;
      lowStart = 0;

      Serial.println("Alarm OFF (timeout). Waiting for PIR LOW reset...");
    } 
    else {
      // Alarm still active
      delay(20);
      return;
    }
  }

  // =========================================
  // Waiting for PIR to stay LOW for reset
  // =========================================
  if (waitingForLow) {

    if (v == LOW) {

      if (lowStart == 0) lowStart = now;

      unsigned long lowDur = now - lowStart;

      if (lowDur >= resetLowSecs * 1000UL) {
        waitingForLow = false;
        Serial.println("Reset complete. Ready for next trigger.");
      }
    } 
    else {
      // PIR went HIGH again → restart timer
      lowStart = 0;
    }

    delay(200);
    return;
  }

  // =========================================
  // Normal Motion Detection
  // =========================================
  if (v == HIGH) {

    Serial.println("Motion Detected → Alarm ON");

    alarmActive = true;
    alarmStart = now;

    digitalWrite(buzzer, HIGH);
    digitalWrite(led, HIGH);
  } 
  else {
    Serial.println("No Motion");
  }

  delay(200);
}
