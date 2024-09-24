// SCRIPT DE ARDUINO

// 1. Implementar un sensor ultrasonido para crear un
// dispositivo de proximidad con leds y un buzzer.
// Debe cumplir lo siguiente:
// Distancia (0cm , 20cm): Buzzer sonando y led
// encendida (color rojo por ej)
// Distancia (20cm , 50cm): Led parpadeando con
// frecuencia rapida
// Distancia (50cm, 100cm): Led parpadeando con
// frecuencia lenta
// Distancia > 100cm: Led apagada

// 2. Reutilizar el código de la actividad anterior y
// aplicar intensidad variable de la led en vez del
// parpadeo. Pruebe a usar varias Leds de colores
// para cada rango e intentar asignar un tono
// diferente para el buzzer en cada rango.

// Incluimos la librería para el buzzer
#include <EasyBuzzer.h>

// Definimos los pines para el sensor ultrasonido, el buzzer y los leds
#define trigPin 6
#define echoPin 3
#define buzzerPin 10
#define redLedPin 2
#define greenLedPin 4
#define yellowLedPin 8
#define blueLedPin 0 // Placeholder
#define whiteLedPin 13

// Definimos las variables para almacenar la distancia y el tiempo
long duration;
int distance;

// Definimos las funciones para cumplir con los objetivos

// Esta función activa el buzzer y la led
void buzzerAndLed(int buzzerTone, int ledPin, int ledIntensity) {
    digitalWrite(buzzerPin, HIGH);
    analogWrite(ledPin, ledIntensity);
}

// Esta función activa el parpadeo rápido de la led
void fastBlink(int ledPin) {
  digitalWrite(ledPin, HIGH);
  delay(100);
  digitalWrite(ledPin, LOW);
  delay(100);
}

// Esta función activa el parpadeo lento de la led
void slowBlink(int ledPin) {
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
  delay(500);
}

// Configuramos los pines
void setup() {
  // Inicializamos los pines
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);
  pinMode(whiteLedPin, OUTPUT);
}

// Realizamos las acciones según la distancia
void loop() {
  // Generamos un pulso de 10us en el pin trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Medimos el tiempo que tarda en llegar el eco
  duration = pulseIn(echoPin, HIGH);

  // Calculamos la distancia en cm
  distance = duration * 0.034 / 2;

  // Realizamos las acciones según la distancia
  if (distance >= 0 && distance <= 20) {
    buzzerAndLed(532, redLedPin, 255);
    // Turn off the other leds
    digitalWrite(greenLedPin, LOW);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(blueLedPin, LOW);
    digitalWrite(whiteLedPin, LOW);

  } else if (distance > 20 && distance <= 50) {
    slowBlink(redLedPin);
    digitalWrite(yellowLedPin, HIGH);
    // Turn off the other leds
    fastBlink(buzzerPin);
    digitalWrite(greenLedPin, LOW);
    digitalWrite(blueLedPin, LOW);
    digitalWrite(whiteLedPin, LOW);

  } else if (distance > 50 && distance <= 100) {
    slowBlink(yellowLedPin);
    digitalWrite(greenLedPin, HIGH);
    // Turn off the other leds
    slowBlink(buzzerPin);
    digitalWrite(redLedPin, LOW);
    digitalWrite(blueLedPin, LOW);
    digitalWrite(whiteLedPin, LOW);

  } else {
    digitalWrite(buzzerPin, LOW);
    analogWrite(redLedPin, 0);
    digitalWrite(greenLedPin, HIGH);
    // Turn off the other leds
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(blueLedPin, LOW);
    digitalWrite(whiteLedPin, HIGH);
  }
}