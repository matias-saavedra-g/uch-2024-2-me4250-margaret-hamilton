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

// Se va a usar un servomotor para mover
// los dulces a los compartimientos.

// Incluimos las librerías necesarias
#include <Servo.h>
#include <TCS3200.h>

// Definimos los pines para el sensor de color
#define S0 2
#define S1 3
#define S2 4
#define S3 5
#define Sout 8

// Definimos los pines para el servo
#define servo1 9

// Configuramos el sensor de color
TCS3200 colorSensor(S0, S1, S2, S3, Sout);

// Configuramos el servo
Servo servo;

// Definimos funciones

// Esta función detecta el color del dulce, que puede ser 1 o 2 (verde o rosado)
int detectColor() {
    // Definimos las variables para almacenar los valores RGB
    int red, green, blue;

    // Definimos el número de iteraciones
    int iter = 10;

    // Inicializamos los valores RGB
    red = 0;
    green = 0;
    blue = 0;

    // Leemos el valor clear para calibrar el sensor
    colorSensor.read_clear();

    // Leemos los valores RGB iter veces y promediamos el resultado
    for (int i = 0; i < iter; i++) {
        red = red + colorSensor.read_red();
        green = green + colorSensor.read_green();
        blue = blue + colorSensor.read_blue();
        Serial.println("Leyendo color...");
        delay(50);
    }  

    // Promediamos los valores RGB
    red /= iter;
    green /= iter;
    blue /= iter;

    Serial.println("Color leído en RGB");

    // Comparamos los valores RGB para determinar el color
    if (red < 100 && green > 100 && blue < 100) {
        Serial.println("Color detectado: Verde");
        return 1; // Verde
    } else if (red > 100 && green < 100 && blue > 100) {
        Serial.println("Color detectado: Rosado");
        return 2; // Rosado
    } else {
        Serial.println("Color detectado en RGB");
        Serial.print("R: ");
        Serial.print(red);
        Serial.print(" G: ");
        Serial.print(green);
        Serial.print(" B: ");
        Serial.println(blue);
        return 0; // Otro color
    }
}

// Esta función mueve el servo a la derecha
void moveServoRight() {
    servo.attach(servo1);
    servo.write(180);
}

// Esta función mueve el servo a la izquierda
void moveServoLeft() {
    servo.attach(servo1);
    servo.write(0);
}

// Esta función mueve el servo a la posición central
void moveServoCenter() {
    servo.attach(servo1);
    servo.write(90);
}

// Esta función mueve el servo de acuerdo al color detectado (1 o 2) hacia la derecha o izquierda
void moveServo(int color) {
    // Inicializamos el servo
    servo.attach(servo1);

    // Movemos el servo a la derecha si es 1
    if (color == 1) {
        moveServoRight();
        delay(1000);
        moveServoCenter();
    }

    // Movemos el servo a la izquierda si es 2
    if (color == 2) {
        moveServoLeft();
        delay(1000);
        moveServoCenter();
    }
    
    // Esperamos un segundo
    delay(1000);
    
    // Detenemos el servo
    servo.detach();
}

//
void setup() {
    // Inicializamos los pines
    pinMode(S0, OUTPUT);
    pinMode(S1, OUTPUT);
    pinMode(S2, OUTPUT);
    pinMode(S3, OUTPUT);
    pinMode(Sout, INPUT);
    pinMode(servo1, OUTPUT);

    // Inicializamos el servo
    servo.attach(servo1);

    // Inicializamos el sensor de color
    colorSensor.begin();

    // Inicializamos la comunicación serial
    Serial.begin(9600);

    // Mostramos un mensaje de inicio
    Serial.println("Sistema de clasificación de dulces iniciado.");
}

// 
void loop() {
    // Detectamos el color del dulce
    int color = detectColor();

    // Movemos el servo hacia el compartimiento correspondiente
    moveServo(color);
}