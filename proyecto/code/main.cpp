// Esta es la rutina principal del programa para la ruleta automática del casino Ruléticas S.A.

// La rutina contempla un puente H L298N, que controla un motor DC encargado de potenciar el giro del elevador de la pelota, y controla un motor DC encargado de mover la ruleta en base al input de un sensor infrarrojo. También contempla un motor servo que controla la posición de la compuerta que libera la pelota en la ruleta ya habiendo caído en algún número. También contempla el encender dos LEDS, rojos en paralelo y blancos en paralelo. Y contempla mostrar en un voltímetro DC los números del 1 al 5, que representan el lugar dónde cayó la pelota de acuerdo con sensores fotorresistivos.

// Mapeo de pines

// Pin 3: Voltímetro LED
// Pin 9: IN3 (Elevador)
// Pin 10: IN1 (Ruleta)
// Pin 12: IN2 (Ruleta)
// Pin 11: Servo motor
// Pin 13: ENA (Ruleta)
// Pin 7: LEDs blancos
// Pin 4: LEDs rojos

// Incluimos las librerías necesarias
#include <Servo.h>

// Definimos los pines
#define IN1 10
#define IN2 12
#define IN3 9
#define ENA 13
#define SERVO 11
#define LEDS_BLANCOS 7
#define LEDS_ROJOS 4
#define VOLTIMETRO 3

// Definimos los objetos
Servo servo;
int pos = 0;

// Definimos las funciones
void abrirCompuerta();
void cerrarCompuerta();
void girarRuleta();
void girarElevador();
void encenderLeds();
void apagarLeds();
void mostrarNumero(int numero);

// Definimos el setup
void setup() {
  // Configuramos los pines
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(SERVO, OUTPUT);
  pinMode(LEDS_BLANCOS, OUTPUT);
  pinMode(LEDS_ROJOS, OUTPUT);
  pinMode(VOLTIMETRO, OUTPUT);

  // Configuramos el servo
  servo.attach(SERVO);

  // Apagamos los LEDs
  apagarLeds();
}

// Definimos el loop
void loop() {
  // Encendemos los LEDs
    encenderLeds();

  // Abrimos la compuerta
  cerrarCompuerta();

  // Giramos la ruleta
  girarRuleta();

  // Cerramos la compuerta
  abrirCompuerta();

  // Giramos el elevador
  girarElevador();

  // Mostramos un número en el voltímetro
  mostrarNumero(1);
}

// Definimos la función para abrir la compuerta
void abrirCompuerta() {
  servo.write(0);
  delay(1000);
}

// Definimos la función para cerrar la compuerta
void cerrarCompuerta() {
  servo.write(90);
  delay(1000);
}

// Definimos la función para girar la ruleta
void girarRuleta() {
  // Encendemos el motor
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(ENA, HIGH);

  // Giramos la ruleta
  delay(5000);

  // Apagamos el motor
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(ENA, LOW);
}

// Definimos la función para girar el elevador
void girarElevador() {
  // Encendemos el motor
  digitalWrite(IN3, HIGH);
}

// Definimos la función para encender los LEDs
void encenderLeds() {
  digitalWrite(LEDS_BLANCOS, HIGH);
  digitalWrite(LEDS_ROJOS, HIGH);
}

// Definimos la función para apagar los LEDs
void apagarLeds() {
  digitalWrite(LEDS_BLANCOS, LOW);
  digitalWrite(LEDS_ROJOS, LOW);
}

// Definimos la función para mostrar un número en el voltímetro
void mostrarNumero(int numero) {
  int voltaje = numero; // El voltaje es igual al número
  analogWrite(VOLTIMETRO, voltaje * (255 / 5)); // Configura el voltaje de salida

  // Mantener el voltaje durante un tiempo para que sea visible
  delay(1000);

  // Apagar el voltímetro
  analogWrite(VOLTIMETRO, 0);
}

// Fin del código