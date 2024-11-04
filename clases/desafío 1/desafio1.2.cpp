// Motor control pins
const int motorPin1 = 3;

// Motor control pins
const int motorPin2 = 5;
#include <Servo.h>

// Servo control pin
const int servoPin = 9;

// Servo object
Servo myServo;

void setup() {
    // Initialize motor control pins as outputs
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    
    // Attach servo to the servo pin
    myServo.attach(servoPin);
}
// Function to stop the motor
void detener() {
    // Set motor control pins to stop the motor
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
}
// Function to move the motor forward
void avanzar(int powerPercentage) {
    // Convert power percentage to a value between 0 and 255
    int powerValue = map(powerPercentage, 0, 100, 0, 255);
    
    // Set motor control pins to move the motor forward
    analogWrite(motorPin1, powerValue);
    digitalWrite(motorPin2, LOW);
}

// Function to center the servo
void centrarServo() {
    // Set the servo angle to the center position
    myServo.write(90);
}
// Function to rotate the servo to the right
void girarDerecha(int angle) {
    // Set the servo angle to rotate to the right
    myServo.write(angle);
}

// Function to rotate the servo to the left
void girarIzquierda(int angle) {
    // Set the servo angle to rotate to the left
    myServo.write(180 - angle);
  
}



void loop() {
   avanzar(100);
   delay(3000);
    avanzar(0);
    delay(1500);
    girarDerecha(45);
    delay(1500);
    avanzar(100);
    delay(2000);
    avanzar(0);
    delay(1500);
    centrar();
    delay(1500);
    avanzar(100);
    delay(2000);
    avanzar(0);
    delay(1500);
    girarIzquierda(45);
    delay(1500);
    avanzar(100);
    delay(2000);
    avanzar(0);
    delay(1500);
    centrar();
    delay(1500);
    avanzar(100);
    delay(4000);
}