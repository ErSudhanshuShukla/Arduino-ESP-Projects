/*
====================================================
 Title   : Piano
 Author  : Sudhanshu Shukla
 GitHub  : https://github.com/ErSudhanshuShukla
 License : Released under the MIT License
====================================================
*/

#include "pitches.h"   // Note frequency definitions

#define SPEAKER_PIN 13   // Buzzer / speaker connected to pin 13

// Push button pins for piano keys (Active LOW using INPUT_PULLUP)
const uint8_t buttonPins[] = { 5, 6, 7, 8, 9, 10, 11, 12 };

// Corresponding musical notes for each button
const int buttonTones[] = {
  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4,
  NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5
};

const int numTones = sizeof(buttonPins) / sizeof(buttonPins[0]);  // Total number of keys

void setup() {
  // Configure all button pins as INPUT_PULLUP (Active LOW)
  for (uint8_t i = 0; i < numTones; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }

  pinMode(SPEAKER_PIN, OUTPUT);   // Set speaker pin as OUTPUT
}

void loop() {
  int pitch = 0;   // Stores currently pressed note

  // Check each button
  for (uint8_t i = 0; i < numTones; i++) {
    if (digitalRead(buttonPins[i]) == LOW) {   // Button pressed
      pitch = buttonTones[i];                  // Select corresponding note
    }
  }

  // Play selected note if any button is pressed
  if (pitch) {
    tone(SPEAKER_PIN, pitch);   // Play tone on speaker
  } else {
    noTone(SPEAKER_PIN);        // Stop sound if no button is pressed
  }
}
