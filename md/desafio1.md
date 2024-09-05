# Code Documentation

## Libraries

```cpp
#include <Servo.h>
```

This library is used to control servo motors. It provides functions to attach a servo to a pin, write angles to the servo, and detach the servo.

## Pin Definitions
### MOTOR PIN IN3
```cpp
#define MOTOR_PIN_IN3 3
```
Defines digital pin 3 for controlling the motor (H bridge input 3).

### MOTOR PIN IN4
```cpp
#define MOTOR_PIN_IN4 5
```
Defines digital pin 5 for controlling the motor (H bridge input 4).

### SERVO PIN
```cpp
#define SERVO_PIN 9
```
Defines PWM pin 9 for controlling the servo motor.

### REAR LIGHTS PIN
```cpp
#define REAR_LIGHTS_PIN 10
```
Defines digital pin 10 for controlling the rear lights.

## Constants
### SERVO CENTER
```cpp
#define SERVO_CENTER 90
```
Defines the center position for the servo motor (90 degrees).

###  SERVO LEFT
```cpp
#define SERVO_LEFT 135
```
Defines the left position for the servo motor (135 degrees).

### SERVO RIGHT
```cpp
#define SERVO_RIGHT 45
```
Defines the right position for the servo motor (45 degrees).

### WHEEL DIAMETER
```cpp
#define WHEEL_DIAMETER 7.0
```
Defines the diameter of the wheel in centimeters.

## Objects
### Servo
```cpp
Servo servo
```
Creates a Servo object to control the servo motor.

## Functions
### goForward
```cpp
void goForward(float distance)
```
This function makes the car go forward a certain distance.

```cpp
Parameters: distance (float) - The distance to move forward in centimeters.
```

**Steps**:
1. Calculate the time required to move the given distance.
2. Straighten the wheels.
3. Set the motor to move forward using the H bridge.
4. Wait for the calculated time.
5. Stop the motor.

### turnLeft
```cpp
void turnLeft(float angle)
```
This function makes the car turn left while moving forward.

```cpp
Parameters: angle (float) - The angle to turn left in degrees.
```

**Steps**:
1. Calculate the time required to turn the given angle.
2. Set the motor to move forward using the H bridge.
3. Set the servo to turn left.
4. Wait for the calculated time.
5. Stop the motor.
6. Set the servo back to the center position.

### turnRight
```cpp
void turnRight(float angle)
```

This function makes the car turn right while moving forward.
```cpp
Parameters: angle (float) - The angle to turn right in degrees.
```

**Steps**:
1. Calculate the time required to turn the given angle.
2. Set the motor to move forward using the H bridge.
3. Set the servo to turn right.
4. Wait for the calculated time.
5. Stop the motor.
6. Set the servo back to the center position.

### stop
```cpp
void stop()
```
This function makes the car stop.

**Steps**:
1. Turn the rear lights on.
2. Straighten the wheels.
3. Stop the motor.

### blink
```cpp
void blink()
```
This function makes the rear lights blink.

**Steps**:
1. Turn the rear lights on.
2. Wait for 1 second.
3. Turn the rear lights off.
4. Wait for 1 second.

## Setup
```cpp
void setup()
```
This function sets up the initial configuration.

**Steps**:
1. Set the motor and servo pins as outputs.
2. Attach the servo to the defined pin.
3. Set the servo to the center position.
4. Turn the rear lights off.

## Loop
```cpp
void loop()
```
This function contains the main logic that runs repeatedly.

**Steps**:
1. Wait for 5 seconds.
2. Move forward 80 cm.
3. Turn right 135 degrees.
4. Move forward 20 cm.
5. Turn left 135 degrees.
6. Move forward 100 cm.
7. Blink the rear lights 10 times.
8. Wait for 10 seconds.
