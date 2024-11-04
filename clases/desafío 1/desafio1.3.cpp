// Definir los pines de control del motor
int pinMotorIzquierdo = 2;
int pinMotorDerecho = 3;

// Función para dirigir el giro a la izquierda en porcentaje
void girarIzquierda(float porcentaje) {
    // Convertir el porcentaje a un valor entre 0 y 255
    int velocidad = map(porcentaje, 0, 100, 0, 255);
    
    // Girar el motor izquierdo hacia adelante
    analogWrite(pinMotorIzquierdo, velocidad);
    
    // Detener el motor derecho
    analogWrite(pinMotorDerecho, 0);
}

// Función para dirigir el giro a la derecha en porcentaje
void girarDerecha(float porcentaje) {
    // Convertir el porcentaje a un valor entre 0 y 255
    int velocidad = map(porcentaje, 0, 100, 0, 255);
    
    // Girar el motor derecho hacia adelante
    analogWrite(pinMotorDerecho, velocidad);
    
    // Detener el motor izquierdo
    analogWrite(pinMotorIzquierdo, 0);
}