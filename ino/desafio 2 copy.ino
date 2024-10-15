// Script extraído de https://cursos.mcielectronics.cl/2022/12/26/interfaz-del-sensor-de-color-tcs230-tcs3200-con-arduino/
// Modificado por @matias-saavedra-g
// En 2024.10.15

// SCRIPT DE ARDUINO

// Este script es para un mecanismo
// para clasificar dos dulces
// masticables en dos compartimientos
// distintos. Se van a usar sensores de
// color, servomotores, la placa Arduino
// UNO/Nano y diversos materiales de
// escritorio.

// Se va a usar un sensor de color TCS3200
// para detectar el color de los dulces.

// Se va a usar un motor DC para mover
// los dulces a los compartimientos
// con una placa L298N.

// Define color sensor pins
#define S0 2
#define S1 3
#define S2 4
#define S3 5
#define sensorOut 8

// Define motor driver pins
#define in1 12
#define in2 13

// Variables for Color Pulse Width Measurements
int redPW = 0;
int greenPW = 0;
int bluePW = 0;

// Variable for iter
int iter = 0;

void setup() {
	// Set S0 - S3 as outputs
	pinMode(S0, OUTPUT);
	pinMode(S1, OUTPUT);
	pinMode(S2, OUTPUT);
	pinMode(S3, OUTPUT);

    // Define pins
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);  

	// Set Pulse Width scaling to 20%
	digitalWrite(S0,HIGH);
	digitalWrite(S1,LOW);

	// Set Sensor output as input
	pinMode(sensorOut, INPUT);

	// Setup Serial Monitor
	Serial.begin(9600);
}

void loop() {
	// Read Red Pulse Width
	redPW = getRedPW();
	// Delay to stabilize sensor
	delay(200);

	// Read Green Pulse Width
	greenPW = getGreenPW();
	// Delay to stabilize sensor
	delay(200);

	// Read Blue Pulse Width
	bluePW = getBluePW();
	// Delay to stabilize sensor
	delay(200);

    iter = iter + 1;

    if (iter == 5 && bluePW < redPW && greenPW < redPW) {
        // Move DC Motor to the right
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        delay(1000);
        // Stop DC Motor
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        Serial.println("Green detected!");
        delay(1000);
        iter = 0;
    }
    else if (iter == 5 && bluePW < redPW && bluePW < greenPW) {
        // Move DC Motor to the left
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        delay(1000);
        // Stop DC Motor
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        Serial.println("Pink detected!");
        delay(1000);
        iter = 0;
    }

	// Print output to Serial Monitor
	Serial.print("Red PW = ");
	Serial.print(redPW);
	Serial.print(" - Green PW = ");
	Serial.print(greenPW);
	Serial.print(" - Blue PW = ");
	Serial.println(bluePW);
}


// Function to read Red Pulse Widths
int getRedPW() {
	// Set sensor to read Red only
	digitalWrite(S2,LOW);
	digitalWrite(S3,LOW);
	// Define integer to represent Pulse Width
	int PW;
	// Read the output Pulse Width
	PW = pulseIn(sensorOut, LOW);
	// Return the value
	return PW;
}

// Function to read Green Pulse Widths
int getGreenPW() {
	// Set sensor to read Green only
	digitalWrite(S2,HIGH);
	digitalWrite(S3,HIGH);
	// Define integer to represent Pulse Width
	int PW;
	// Read the output Pulse Width
	PW = pulseIn(sensorOut, LOW);
	// Return the value
	return PW;
}

// Function to read Blue Pulse Widths
int getBluePW() {
	// Set sensor to read Blue only
	digitalWrite(S2,LOW);
	digitalWrite(S3,HIGH);
	// Define integer to represent Pulse Width
	int PW;
	// Read the output Pulse Width
	PW = pulseIn(sensorOut, LOW);
	// Return the value
	return PW;
}