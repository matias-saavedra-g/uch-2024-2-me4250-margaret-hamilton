/*
Proyecto Ruléticas S.A.
Iteración 1 - Control de motor y elevador
Última modificación: 2024.11.04
Modificado por: Matías Ignacio
Descripción:
- Servo Motor: Controla el elevador de la pelota.
- Motor DC: Controlado mediante un puente H, con pines de dirección y PWM para la velocidad.
- Sensores de Contacto: Detectan la posición de la pelota en los depósitos.
- Apagado de Emergencia: Implementado con un botón de emergencia que detiene todo el sistema cuando se activa.
*/

// Incluir librería de Servo
#include <Servo.h>

// ------------------------------------------ //

// Definición de pines
const int servoPin = 9;
const int motorPin1 = 5; // Pin de control para el H-Bridge (dirección)
const int motorPin2 = 6; // Pin de control para el H-Bridge (dirección)
const int pwmPin = 3;    // Pin PWM para la velocidad del motor DC
const int sensorPin1 = 2; // Sensor de contacto 1
const int sensorPin2 = 4; // Sensor de contacto 2
const int emergencyStopPin = 8; // Pin para apagado de emergencia

// ------------------------------------------ //

// Variables
Servo elevador;
bool emergencyStop = false;

// ------------------------------------------ //

void setup() {
    // Configuración de pines
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(pwmPin, OUTPUT);
    pinMode(sensorPin1, INPUT);
    pinMode(sensorPin2, INPUT);
    pinMode(emergencyStopPin, INPUT_PULLUP); // Botón de emergencia con pull-up interno

    // Iniciar el servo
    elevador.attach(servoPin);
    elevador.write(0); // Posición inicial

    // Configuración serie para monitoreo
    Serial.begin(9600);
}

void loop() {
    // Verificar botón de emergencia
    if (digitalRead(emergencyStopPin) == LOW) {
        emergencyStop = true;
        detenerSistema();
    }

    if (!emergencyStop) {
        // Verificar sensores de contacto
        if (digitalRead(sensorPin1) == HIGH || digitalRead(sensorPin2) == HIGH) {
            Serial.println("Pelota detectada en el depósito");
            controlarElevador();
        } else {
            controlarMotorDC();
        }
    }
}

// ------------------------------------------ //

// Función para controlar el elevador
void controlarElevador() {
    elevador.write(90); // Levanta el elevador
    delay(1000);        // Esperar 1 segundo
    elevador.write(0);  // Baja el elevador
    delay(1000);
}

// Función para controlar el motor DC
void controlarMotorDC() {
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    analogWrite(pwmPin, 150); // Velocidad moderada
    delay(2000);              // Girar por 2 segundos

    detenerMotorDC();
}

// Función para detener el motor DC
void detenerMotorDC() {
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    analogWrite(pwmPin, 0);
}

// Función para detener todo el sistema en caso de emergencia
void detenerSistema() {
    Serial.println("¡Apagado de emergencia activado!");
    detenerMotorDC();
    elevador.write(0); // Posición de reposo
    while (true); // Detener el loop para garantizar la seguridad
}
