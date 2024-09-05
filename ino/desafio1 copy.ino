// This script will be utilized to control a car using nothing but lines of code.
// The car have a DC motor in the rear to power the rear wheels
// It has a servo motor that allows the car to turn left and right
// The challenge consists in making the car go through a track with a few obstacles

// Include libraries
#include <Servo.h>

// Define the pins for the motors
#define MOTOR_PIN 3 // This is a PWM pin
#define SERVO_PIN 9 // This is a PWM pin

// Define the pins for rear lights (both will be connected in parallel to just 1 pin)
#define REAR_LIGHTS_PIN 13 // This is a digital pin

// Define a few constants
#define SERVO_CENTER 90 // This is the center position for the servo
#define SERVO_LEFT 0 // This is the left position for the servo
#define SERVO_RIGHT 180 // This is the right position for the servo
#define MOTOR_SPEED 255 // This is the maximum speed for the motor
#define MOTOR_STOP 0 // This is the speed to stop the motor
#define WHEEL_DIAMETER 6.5 // This is the diameter of the wheel in cm

// Define the servo and motor objects
Servo servo; // This object will control the servo motor
Servo motor; // This object will control the DC motor

// Define some functions
// This function will make the car go forward a certain distance
void goForward(float distance) {
  // Calculate the time it will take to go forward
  float time = distance / (WHEEL_DIAMETER * PI);
  // Set the motor to go forward
  motor.write(MOTOR_SPEED);
  // Wait for the time it will take to go forward
  delay(time * 1000);
  // Stop the motor
  motor.write(MOTOR_STOP);
}

// This function will make the car turn left while going forward
void turnLeft(float angle) {
  // Calculate the time it will take to turn left
  float time = angle / 90;
  // Set the servo to turn left
  servo.write(SERVO_LEFT);
  // Set the motor to go forward
  motor.write(MOTOR_SPEED);
  // Wait for the time it will take to turn left
  delay(time * 1000);
  // Stop the motor
  motor.write(MOTOR_STOP);
  // Set the servo to the center
  servo.write(SERVO_CENTER);
}

// This function will make the car turn right while going forward
void turnRight(float angle) {
  // Calculate the time it will take to turn right
  float time = angle / 90;
  // Set the servo to turn right
  servo.write(SERVO_RIGHT);
  // Set the motor to go forward
  motor.write(MOTOR_SPEED);
  // Wait for the time it will take to turn right
  delay(time * 1000);
  // Stop the motor
  motor.write(MOTOR_STOP);
  // Set the servo to the center
  servo.write(SERVO_CENTER);
}

// This function will make the car go backward a certain distance
void goBackward(float distance) {
  // Calculate the time it will take to go backward
  float time = distance / (WHEEL_DIAMETER * PI);
  // Set the motor to go backward
  motor.write(-MOTOR_SPEED);
  // Wait for the time it will take to go backward
  delay(time * 1000);
  // Stop the motor
  motor.write(MOTOR_STOP);
}

// This function will make the car turn left while going backward
void turnLeftBackward(float angle) {
  // Calculate the time it will take to turn left
  float time = angle / 90;
  // Set the servo to turn left
  servo.write(SERVO_LEFT);
  // Set the motor to go backward
  motor.write(-MOTOR_SPEED);
  // Wait for the time it will take to turn left
  delay(time * 1000);
  // Stop the motor
  motor.write(MOTOR_STOP);
  // Set the servo to the center
  servo.write(SERVO_CENTER);
}

// This function will make the car turn right while going backward
void turnRightBackward(float angle) {
  // Calculate the time it will take to turn right
  float time = angle / 90;
  // Set the servo to turn right
  servo.write(SERVO_RIGHT);
  // Set the motor to go backward
  motor.write(-MOTOR_SPEED);
  // Wait for the time it will take to turn right
  delay(time * 1000);
  // Stop the motor
  motor.write(MOTOR_STOP);
  // Set the servo to the center
  servo.write(SERVO_CENTER);
}

// This function will make the car stop
void stop() {
  // Turn the rear lights on
  digitalWrite(REAR_LIGHTS_PIN, HIGH);
  // Stop the motor
  motor.write(MOTOR_STOP);
}

// This function will make the rear lights blink
void blink() {
  // Turn the rear lights on
  digitalWrite(REAR_LIGHTS_PIN, HIGH);
  // Wait for 1 second
  delay(1000);
  // Turn the rear lights off
  digitalWrite(REAR_LIGHTS_PIN, LOW);
  // Wait for 1 second
  delay(1000);
}

// Setup
void setup() {
  // Set the motor and servo pins as outputs
  pinMode(MOTOR_PIN, OUTPUT);
  pinMode(SERVO_PIN, OUTPUT);
  pinMode(REAR_LIGHTS_PIN, OUTPUT);
  // Attach the servo and motor objects to the pins
  servo.attach(SERVO_PIN);
  motor.attach(MOTOR_PIN);
  // Set the servo to the center
  servo.write(SERVO_CENTER);
  // Turn the rear lights off
  digitalWrite(REAR_LIGHTS_PIN, LOW);
}

// Loop
void loop() {
    // Go forward 10 cm
    goForward(10);
    // Turn left 90 degrees
    turnLeft(90);
    // Go forward 10 cm
    goForward(10);
    // Turn right 90 degrees
    turnRight(90);
    // Go forward 10 cm
    goForward(10);
    // Turn left 90 degrees
    turnLeft(90);
    // Go forward 10 cm
    goForward(10);
    // Turn right 90 degrees
    turnRight(90);
    // Go forward 10 cm
    goForward(10);
    // Turn left 90 degrees
    turnLeft(90);
    // Go forward 10 cm
    goForward(10);
    // Turn right 90 degrees
    turnRight(90);
    // Go forward 10 cm
    goForward(10);
    // Turn left 90 degrees
    turnLeft(90);
    // Go forward 10 cm
    goForward(10);
    // Turn right 90 degrees
    turnRight(90);
    // Go forward 10 cm
    goForward(10);
    // Turn left 90 degrees
    turnLeft(90);
    // Go forward 10 cm
    goForward(10);
    // Turn right 90 degrees
    turnRight(90);
    // Go forward 10 cm
    goForward(10);
    // Turn left 90 degrees
    turnLeft(90);
    // Go forward 10 cm
    goForward(10);
    // Turn right 90 degrees
    turnRight(90);
    // Go forward 10 cm
    goForward(10);
    // Turn left 90 degrees
    turnLeft(90);
    // Go forward 10 cm
    goForward(10);
    // Turn right 90 degrees
    turnRight(90);
    // Go forward 10 cm
    goForward(10);
    // Turn left 90 degrees
    turnLeft(90);
    // Go forward 10 cm
    goForward(10);
    // Turn right 90 degrees
    turnRight(90);
    // Go forward 10 cm
    goForward(10);
    // Turn left 90 degrees
    turnLeft(90);
    // Go forward 10 cm
    goForward(10);
    // Turn right 90 degrees
}