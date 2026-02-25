/*
====================================================
 Title   : Smart Stair Light
 Author  : Sudhanshu Shukla
 GitHub  : https://github.com/ErSudhanshuShukla
 License : Released under the MIT License
====================================================
*/

// IR sensors toggle the LED strip ON/OFF
// IR Top Sensor  -> Pin 3
// IR Bottom Sensor -> Pin 2
// LED Strip (4 segments) -> Pins 8, 9, 10, 11

const int irTop = 3;          // Top IR sensor digital output pin
const int irBottom = 2;       // Bottom IR sensor digital output pin
const int leds[4] = {8, 9, 10, 11};  // LED strip segment pins

bool lightsOn = false;        // Stores current light state

void setup() {
  pinMode(irTop, INPUT);      // Configure top IR sensor pin as input
  pinMode(irBottom, INPUT);   // Configure bottom IR sensor pin as input

  // Configure LED pins as output and turn OFF initially
  for (int i = 0; i < 4; i++) {
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], LOW);
  }
}

void loop() {

  // IR sensor outputs LOW when an object/person is detected
  if (digitalRead(irTop) == LOW) {
    toggleLights();           // Toggle stair lights
    delay(500);               // Debounce delay to avoid multiple triggers
  }

  if (digitalRead(irBottom) == LOW) {
    toggleLights();           // Toggle stair lights
    delay(500);               // Debounce delay to avoid multiple triggers
  }
}

void toggleLights() {
  lightsOn = !lightsOn;       // Toggle current light state

  // Turn all LED segments ON or OFF based on lightsOn state
  for (int i = 0; i < 4; i++) {
    digitalWrite(leds[i], lightsOn ? HIGH : LOW);
  }
}
