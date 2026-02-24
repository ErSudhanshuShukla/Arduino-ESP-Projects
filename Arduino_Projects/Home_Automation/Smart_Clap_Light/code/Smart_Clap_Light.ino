/*
====================================================
 Title   : Smart Clap Light
 Author  : Sudhanshu Shukla
 GitHub  : https://github.com/ErSudhanshuShukla
 License : Released under the MIT License
====================================================
*/

int relay = 9;        // Relay control pin connected to Arduino pin 9
int sensor = 8;       // Sound sensor digital output connected to Arduino pin 8
bool state = false;  // Stores current relay state (false = OFF, true = ON)

void setup() {
  pinMode(relay, OUTPUT);         // Set relay pin as OUTPUT
  pinMode(sensor, INPUT_PULLUP); // Enable internal pull-up resistor for sound sensor
}

void loop() {
  if (digitalRead(sensor) == LOW) {   // Clap detected (LOW because of pull-up)
    state = !state;                   // Toggle relay state
    digitalWrite(relay, state);       // Turn relay ON/OFF
    delay(300);                       // Simple debounce to avoid multiple toggles
  }
}
