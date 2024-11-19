#include<Servo.h>
#include <HCSR04.h>
// Asignaciones pins
Servo servo;
const int pin_servo = 3;
const int triggerPin = 11;
const int echoPin = 8;

// Constantes Balancines 
double Kp=5, Ki=0.002, Kd=185; //fix here

HCSR04 hc(11,8);
// variables externas del controlador
double Input, Output, Setpoint;
int pos;
// variables internas del controlador
unsigned long currentTime, previousTime;
double elapsedTime;
double error, lastError, cumError, rateError;
int Output1;
void setup(){
  pinMode(echoPin,INPUT);
  servo.attach(pin_servo);
  Serial.begin(9600);
}

void loop(){
  Setpoint = 19; //Fix Here
  Input = readPosition();
  // leer una entrada del controlador
  Output = computePID(Input);
  // Limitación rango superior
  if(Output > 140){ // FIX HERE
  Output = 140; //FIX HERE 
  }
  // Limitación rango inferior
  if(Output < 10){ 
  Output = 10;  
  }

  servo.write(Output); // calcular el controlador
  delay(100);
  //Serial.print("Setpoint: ");
  //Serial.println(Setpoint);
  Serial.println("Input: ");
  Serial.println(Input);
  Serial.println("Output: ");
  Serial.println(Output); // escribir la salida del controlador
}

double computePID(double inp){
  currentTime = millis(); // obtener el tiempo actual
  elapsedTime = (double)(currentTime - previousTime); // calcular el tiempo transcurrido

  error = Setpoint - Input; // determinar el error entre la consigna y la adición
  cumError += error * elapsedTime; // calcular la integral del error
  rateError = (error - lastError) / elapsedTime; // calcular la derivada del error

  double output = Kp*error + Ki*cumError + Kd*rateError;
  //Serial.println("output: ");
  //Serial.println(output); // calcular la salida del PID

  // CAMBIAR LÍMITES SERVOMOTOR DE ACUERDO A RANGO MÍNIMO Y MÁXIMO
  output = map(output,-160,160,140,10); //Fix here too  // Valores del error transformados al ángulo de movimiento del servomotor.
  if(output<0){output=0;}
  if(output>140){output=140;}
  lastError = error; // almacenar error anterior
  previousTime = currentTime; // almacenar el tiempo anterior

  return output;
}
float readPosition(){
  delay(100); //Don’t set too low or echos will run into chother.
  long cm;
  cm = hc.dist();
  if(cm > 41) // 41 cm es la máxima posición de la rueda.
  {cm=41;}
  if(cm < 2) // 2 cm es la mínima posición de la rueda.
  {cm=2;}
  return cm; // Retorna el valor de la distancia
}
