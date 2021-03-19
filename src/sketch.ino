// Example sketch for AM2302 humidity - temperature sensor
// Written by cactus.io, with thanks to Adafruit for bits of their library. public domain

#include "cactus_io_AM2302.h"

#define AM2302_PIN 2     // what pin on the arduino is the DHT22 data line connected to

#define powerPin 7

// For details on how to hookup the DHT22 sensor to the Arduino then checkout this page
// http://cactus.io/hookups/sensors/temperature-humidity/am2302/hookup-arduino-to-am2302-temp-humidity-sensor

// Initialize DHT sensor for normal 16mhz Arduino.
AM2302 dht(AM2302_PIN);
// Note: If you are using a board with a faster processor than 16MHz then you need
// to declare an instance of the AM2302 using
// AM2302 dht(AM2302_DATA_PIN, 30);
// The additional parameter, in this case here is 30 is used to increase the number of
// cycles transitioning between bits on the data and clock lines. For the
// Arduino boards that run at 84MHz the value of 30 should be about right.

void setup() {
  Serial.begin(9600);
  Serial.println("AM2302 Humidity - Temperature Sensor");
  Serial.println("RH\t\tTemp (C)\tTemp (F)\tHeat Index (C)\tHeat Index (F)\tPower state");

  pinMode(powerPin, OUTPUT);

  dht.begin();
}

void loop() {
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  dht.readHumidity();
  dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(dht.humidity) || isnan(dht.temperature_C)) {
    Serial.println("DHT sensor read failure!");
    return;
  }

  if (dht.temperature_F > 76){
    digitalWrite(powerPin, LOW);
  }
  if (dht.temperature_F < 74){
    digitalWrite(powerPin, HIGH);
  }

  Serial.print(dht.humidity); Serial.print(" %\t\t");
  Serial.print(dht.temperature_C); Serial.print(" *C\t");
  Serial.print(dht.temperature_F); Serial.print(" *F\t");
  Serial.print(dht.computeHeatIndex_C()); Serial.print(" *C\t");
  Serial.print(dht.computeHeatIndex_F()); Serial.print(" *F\t");
  Serial.println(digitalRead(powerPin));

  // Wait a few seconds between measurements. The AM2302 should not be read at a higher frequency of
  // about once every 2 seconds. So we add a 3 second delay to cover this.
  delay(3000);
}
