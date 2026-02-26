/*
====================================================
 Title   : Blind Stick
 Author  : Sudhanshu Shukla
 GitHub  : https://github.com/ErSudhanshuShukla
 License : Released under the MIT License
====================================================
*/

#define trig 3     // Ultrasonic sensor Trigger pin connected to D3
#define echo 2     // Ultrasonic sensor Echo pin connected to D2
int buzzer = 11;   // Buzzer connected to digital pin 11

void setup() {
  pinMode(trig, OUTPUT);   // Set Trigger pin as OUTPUT
  pinMode(echo, INPUT);   // Set Echo pin as INPUT
  pinMode(buzzer, OUTPUT); // Set Buzzer pin as OUTPUT
}

void loop() {
  // 🔊 Send ultrasonic pulse
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  // 📏 Measure echo pulse duration (timeout set to 25ms ~ 4m range)
  long duration = pulseIn(echo, HIGH, 25000);

  // 📐 Convert duration to distance in centimeters
  int distance = duration * 0.034 / 2;

  // 🔔 Beep ONLY when object is very close (within 30 cm)
  if (distance > 0 && distance < 30) {
    digitalWrite(buzzer, HIGH);   // Buzzer ON
    delay(100);
    digitalWrite(buzzer, LOW);    // Buzzer OFF
    delay(100);
  } else {
    digitalWrite(buzzer, LOW);    // Silent when no obstacle nearby
    delay(200);
  }
}
