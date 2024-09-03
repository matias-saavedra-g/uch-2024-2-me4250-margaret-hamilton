// This script will be utilized to control a car using nothing but lines of code.
// The car have a DC motor in the rear to power the rear wheels
// It has a servo motor that allows the car to turn left and right
// The challenge consists in making the car go through a track with a few obstacles
// We will connect the DC motor using a H bridge
// We will connect the servo motor directly to the Arduino
// We will connect the rear lights directly to the Arduino

// Include libraries
#include <Servo.h>

// Define the pins for the motors
#define MOTOR_PIN_IN3 3 // These are digital pins
#define MOTOR_PIN_IN4 5 // These are digital pins
#define SERVO_PIN 9 // This is a PWM pin

// Define the pins for rear lights (both will be connected in parallel to just 1 pin)
#define REAR_LIGHTS_PIN 10 // This is a digital pin

// Define a few constants
#define SERVO_CENTER 90 // This is the center position for the servo
#define SERVO_LEFT 135 // This is the left position for the servo
#define SERVO_RIGHT 45 // This is the right position for the servo
#define WHEEL_DIAMETER 7.0 // This is the diameter of the wheel in cm

// Define the servo and motor objects
Servo servo; // This object will control the servo motor

// Define some functions
// This function will make the car go forward a certain distance
void goForward(float distance) {
  // Calculate the time it will take to go forward
  float time = distance / (WHEEL_DIAMETER * PI);
  // Straighten the wheels
  servo.write(SERVO_CENTER);
  // Set the motor to go forward using H bridge
  digitalWrite(MOTOR_PIN_IN3, HIGH);
  digitalWrite(MOTOR_PIN_IN4, LOW);
  // Wait for the time it will take to go forward
  delay(time * 1000);
  // Stop the motor
  digitalWrite(MOTOR_PIN_IN3, LOW);
  digitalWrite(MOTOR_PIN_IN4, LOW);
}

// This function will make the car turn left while going forward
void turnLeft(float angle) {
  // Calculate the time it will take to turn left
  float time = angle / 90;
  // Set the motor to go forward using H bridge
  digitalWrite(MOTOR_PIN_IN3, HIGH);
  digitalWrite(MOTOR_PIN_IN4, LOW);
  // Set the servo to turn left
  servo.write(SERVO_LEFT);
  // Wait for the time it will take to turn left
  delay(time * 1000);
  // Stop the motor
  digitalWrite(MOTOR_PIN_IN3, LOW);
  digitalWrite(MOTOR_PIN_IN4, LOW);
  // Set the servo to the center
  servo.write(SERVO_CENTER);
}

// This function will make the car turn right while going forward
void turnRight(float angle) {
  // Calculate the time it will take to turn right
  float time = angle / 90;
  // Set the motor to go forward using H bridge
  digitalWrite(MOTOR_PIN_IN3, HIGH);
  digitalWrite(MOTOR_PIN_IN4, LOW);
  // Set the servo to turn right
  servo.write(SERVO_RIGHT);
  // Wait for the time it will take to turn right
  delay(time * 1000);
  // Stop the motor
  digitalWrite(MOTOR_PIN_IN3, LOW);
  digitalWrite(MOTOR_PIN_IN4, LOW);
  // Set the servo to the center
  servo.write(SERVO_CENTER);
}

// This function will make the car stop
void stop() {
  // Turn the rear lights on
  digitalWrite(REAR_LIGHTS_PIN, HIGH);
  // Straighten the wheels
  servo.write(SERVO_CENTER);
  // Stop the motor
  digitalWrite(MOTOR_PIN_IN3, LOW);
  digitalWrite(MOTOR_PIN_IN4, LOW);
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
  pinMode(MOTOR_PIN_IN3, OUTPUT);
  pinMode(MOTOR_PIN_IN4, OUTPUT);
  pinMode(SERVO_PIN, OUTPUT);
  pinMode(REAR_LIGHTS_PIN, OUTPUT);
  // Attach the servo and motor objects to the pins
  servo.attach(SERVO_PIN);
  // Set the servo to the center
  servo.write(SERVO_CENTER);
  // Turn the rear lights off
  digitalWrite(REAR_LIGHTS_PIN, LOW);
}

// Loop
void loop() {
    // Wait 5 seconds
    delay(5000);

    // Go forward 80 cm
    goForward(80);

    // Turn right 135 degrees
    turnRight(135);

    // Go forward 20 cm
    goForward(20);

    // Turn left 135 degrees
    turnLeft(135);

    // Go forward 100 cm
    goForward(100);

    // Blink the rear lights 10 times
    for (int i = 0; i < 10; i++) {
        blink();
    }

    // Delay for 10 seconds
    delay(10000);
}