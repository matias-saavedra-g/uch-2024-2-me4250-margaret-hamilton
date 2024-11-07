// This is an Arduino UNO code

// This will allow me to test the voltage received by a conductor when a current is applied to it, and it will have a resistance in the middle of the circuit, so I will be able to map different states given the different resistances between the conductor.

// The circuit will be as follows:

// 5V ----> X Ohm resistor ----> Conductor ----> X Ohm resistor ----> GND

// With X the value in Ohm of the resistor.

// The voltage will be measured in the middle of the circuit, where the conductor is.

// The voltage will be measured using the analogRead() function, and the voltage will be calculated using the formula:

// The resistance will be printed in the Serial Monitor

int analogPin = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(analogPin);
  float voltage = sensorValue * (5.0 / 1023.0);
  float resistance = (5.0 - voltage) / voltage;
  Serial.println(resistance);
  delay(1000);
}