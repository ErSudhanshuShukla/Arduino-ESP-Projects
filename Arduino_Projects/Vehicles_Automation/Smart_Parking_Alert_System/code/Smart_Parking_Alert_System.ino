/*
====================================================
 Title   : Smart Parking Alert System
 Author  : Sudhanshu Shukla
 GitHub  : https://github.com/ErSudhanshuShukla
 License : Released under the MIT License
====================================================
*/

// Pin Definitions
#define trig 3        // Ultrasonic Trigger Pin
#define echo 2        // Ultrasonic Echo Pin
int buzzer = 11;      // Buzzer Output Pin

// Setup Function
void setup() {

  pinMode(trig, OUTPUT);   // Set trigger as output
  pinMode(echo, INPUT);    // Set echo as input
  pinMode(buzzer, OUTPUT); // Set buzzer as output

  Serial.begin(9600);      // Start Serial Monitor
}

// Main Loop
void loop() {

  // Send 10µs pulse to trigger ultrasonic wave
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);

  digitalWrite(trig, LOW);

  // Measure echo return time
  long duration = pulseIn(echo, HIGH);

  // Convert time to distance in centimeters
  int distance = duration * 0.034 / 2;

  // Print distance to Serial Monitor
  Serial.println(distance);

  // Parking Alert Logic

  // If object is closer than 10 cm
  if (distance < 10) {
    digitalWrite(buzzer, HIGH);   // Turn ON buzzer
  } 
  else {
    digitalWrite(buzzer, LOW);    // Turn OFF buzzer
  }
}
