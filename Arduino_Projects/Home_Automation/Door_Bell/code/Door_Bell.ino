/**************************************************
 *  Title   : Door Bell
 *  Author  : Sudhanshu Shukla
 *  GitHub  : https://github.com/ErSudhanshuShukla
 *  License : Released under MIT License
 **************************************************/

int button = 9;      // Push button connected to digital pin 9
int buzzer = 11;    // Buzzer connected to digital pin 11

bool lastState = HIGH;   // Store previous state of button (HIGH = not pressed because of INPUT_PULLUP)

int melody[] = {523, 659, 784};   // Doorbell notes (frequencies in Hz)
int duration[] = {200, 200, 400}; // Duration of each note in milliseconds

void setup() {
  pinMode(button, INPUT_PULLUP);  // Button uses internal pull-up resistor (default HIGH)
  pinMode(buzzer, OUTPUT);        // Buzzer is an output device
}

void loop() {
  bool currentState = digitalRead(button);  // Read current button state

  // Detect HIGH → LOW transition (button press)
  // This avoids multiple triggers when button is held down
  if (lastState == HIGH && currentState == LOW) {
    playDoorbell();   // Play doorbell sound when button is pressed
  }

  lastState = currentState;  // Update last button state
}

void playDoorbell() {
  // Loop through each note in the melody
  for (int i = 0; i < 3; i++) {
    tone(buzzer, melody[i], duration[i]);   // Play note on buzzer
    delay(duration[i] + 50);                // Small gap between notes
  }
  noTone(buzzer);   // Stop buzzer sound
}
