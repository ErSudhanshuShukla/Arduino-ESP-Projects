/**************************************************
 *  Title   : Humidity Control Fan
 *  Author  : Sudhanshu Shukla
 *  GitHub  : https://github.com/ErSudhanshuShukla
 *  License : Released under MIT License
 **************************************************/

#include <DHT.h>   // Library for DHT temperature & humidity sensor

#define DHTPIN 2        // Digital pin where DHT11 data pin is connected
#define DHTTYPE DHT11   // Type of DHT sensor (DHT11)

DHT dht(DHTPIN, DHTTYPE);   // Create DHT sensor object

int relay = 3;   // Relay pin (Active LOW relay module)

// -------------------- SETUP --------------------
void setup() {
  Serial.begin(9600);   // Start serial communication for debugging
  dht.begin();          // Initialize DHT sensor

  pinMode(relay, OUTPUT);       // Set relay pin as output
  digitalWrite(relay, HIGH);    // Turn OFF fan at start (Active LOW relay)

  // Print welcome message on Serial Monitor
  Serial.println("Humidity & Temperature Based Fan Control");
  Serial.println("---------------------------------------");
}

// -------------------- LOOP --------------------
void loop() {

  // Read humidity value from DHT11 sensor
  float humidity = dht.readHumidity();

  // Read temperature value from DHT11 sensor (in Celsius)
  float temperature = dht.readTemperature();

  // Check if sensor reading failed
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    delay(2000);   // Wait before trying again
    return;        // Exit loop and retry
  }

  // Print humidity value
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" %  |  ");

  // Print temperature value
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  // ---------------- FAN CONTROL LOGIC ----------------
  // Turn ON fan only if:
  // 1. Humidity is greater than 60%
  // 2. Temperature is above 25°C
  if (humidity > 60 && temperature > 25) {
    digitalWrite(relay, LOW);   // Relay ON (Fan ON)
    Serial.println("Fan: ON");
  } else {
    digitalWrite(relay, HIGH);  // Relay OFF (Fan OFF)
    Serial.println("Fan: OFF");
  }

  Serial.println("---------------------------------------");

  delay(2000);   // Wait 2 seconds before next reading
}
