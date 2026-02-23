int sensor = 2;   // Digital pin 2 connected to LDR module output
int led = 10;     // Digital pin 10 connected to LED

void setup() {
  pinMode(sensor, INPUT);     // Set LDR sensor pin as input
  pinMode(led, OUTPUT);      // Set LED pin as output
  Serial.begin(9600);        // Start Serial Monitor at 9600 baud rate
}

void loop() {
  int status = digitalRead(sensor);   // Read LDR sensor digital output (HIGH/LOW)
  Serial.println(status);             // Print sensor status on Serial Monitor

  // If it is dark, LDR module gives HIGH signal
  if (status == HIGH) {  
    digitalWrite(led, HIGH);   // DARK detected → LED ON
  } 
  // If it is bright, LDR module gives LOW signal
  else {
    digitalWrite(led, LOW);    // LIGHT detected → LED OFF
  }

  delay(200);   // Small delay to stabilize readings (200 ms)
}