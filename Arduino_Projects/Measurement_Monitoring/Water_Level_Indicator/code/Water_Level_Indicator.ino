/*
====================================================
 Title   : Water Level Indicator
 Author  : Sudhanshu Shukla
 GitHub  : https://github.com/ErSudhanshuShukla
 License : Released under the MIT License
====================================================
*/

// =============================
// Pin Definitions
// =============================
int sensor = A2;          // Water level sensor connected to Analog Pin A2
int led1 = 11;            // Low Level Indicator
int led2 = 12;            // Medium Level Indicator
int led3 = 13;            // High / Full Level Indicator

void setup() {

  // Configure LED pins as OUTPUT
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  // Start Serial Monitor for debugging
  Serial.begin(9600);
}

void loop() {

  // =============================
  // Read Water Level Sensor
  // =============================
  int val = analogRead(sensor);   // Read analog value (0–1023)
  Serial.println(val);            // Print value for monitoring

  // =============================
  // Water Level Conditions
  // =============================

  if (val < 200) {                
    // Very Low Water Level
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }

  else if (val < 400) {           
    // Medium Water Level
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }

  else if (val < 600) {           
    // High Water Level
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
  }

  else {                          
    // Tank Full
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
  }

  delay(300);   // Small delay for stable reading
}
