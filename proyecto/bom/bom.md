# Lista de Componentes y Herramientas para el Proyecto Ruléticas S.A.

## El proyecto

El proyecto de [Ruléticas S.A.](https://sites.google.com/view/ruleticas/) consiste en el diseño e implementación de un sistema automatizado de ruleta para simular juegos de azar. Utiliza un microcontrolador Arduino como núcleo de control para gestionar un motor DC que gira la ruleta y un servomotor que eleva la pelota, además de sensores para detectar la posición de la pelota.  Este sistema está orientado a aplicaciones en la industria del entretenimiento y la enseñanza de automatización y control en proyectos de mecatrónica.

## Lista

La presente lista de componentes y herramientas incluye todo lo necesario para construir y ensamblar el sistema, garantizando un funcionamiento preciso, seguro y fiable.

A continuación se presenta una lista de componentes comerciales recomendados para el proyecto de mecatrónica sobre un sistema automatizado de ruleta, junto con sus especificaciones, marcas, modelos y cantidades sugeridas.

### Componentes

- **Arduino Microcontroller**
  - **Marca**: Arduino
  - **Modelo**: Arduino Uno
  - **Características**: 
    - Microchip ATmega328P
    - 14 pines digitales I/O, 6 pines analógicos
    - Voltaje operativo: 5V
    - Memoria Flash: 32 KB
    - Tamaño: 68.6 mm x 53.4 mm
  - **Cantidad**: 1

- **Servo Motor**
  - **Marca**: TowerPro
  - **Modelo**: SG90
  - **Características**:
    - Tipo de motor: DC con engranajes plásticos
    - Voltaje operativo: 4.8V a 6V
    - Torque de estancamiento: hasta 1.5 kg/cm (6V)
    - Dimensiones: 23 x 11.5 x 24 mm
    - Peso: 9 g
  - **Cantidad**: 1

- **DC Motor**
  - **Marca**: Johnson Electric
  - **Modelo**: HF283LG-011 (ejemplo)
  - **Características**:
    - Voltaje de entrada: 5V DC
    - Velocidad sin carga: hasta 26,500 rpm
    - Torque nominal: hasta 4 mNm
    - Tamaño compacto para aplicaciones pequeñas
  - **Cantidad**: 1

- **H-Bridge Motor Driver**
  - **Marca**: L298N
  - **Modelo**: L298N Dual H-Bridge Motor Driver
  - **Características**:
    - Capacidad de corriente: hasta 2A por canal
    - Voltaje operativo: hasta 46V
    - Control de dirección y velocidad para motores DC
    - Tamaño compacto, fácil integración con Arduino
  - **Cantidad**: 1

- **Contact Sensors**
  - **Marca**: Omron (ejemplo)
  - **Modelo**: D2HW-DL (ejemplo)
  - **Características**:
    - Tipo de sensor de límite (limit switch)
    - Capacidad de corriente nominal: hasta 10A
    - Tamaño compacto y fácil instalación en proyectos electrónicos
  - **Cantidad**: 2

- **Optocouplers**
  - **Marca**: Vishay
  - **Modelo**: MOC3021 (ejemplo)
  - **Características**:
    - Tipo de optoacoplador fototransistor
    - Voltaje máximo de entrada: hasta 35V 
    - Aislamiento eléctrico entre circuitos 
  - **Cantidad**: 2

- **Decoupling Capacitors**
  - **Marca**: Panasonic (ejemplo)
  - **Modelo**: ECJ-0EB1H104K (ejemplo)
  - **Características**:
    - Capacitancia: 0.1 µF 
    - Voltaje nominal: hasta 50V 
    - Uso común en circuitos para estabilización y filtrado 
  - **Cantidad**: Varias (5)

- **Fuses**
  - **Marca**: Littelfuse (ejemplo)
  - **Modelo**: FRS Series (ejemplo)
  - **Características**:
    - Protección contra sobrecorrientes 
    - Diferentes valores nominales disponibles (e.g., FRS-2A)
    - Tamaño estándar para montaje en PCB 
  - **Cantidad**: Varias (5)

- **Heatsinks**
   - **Marca**: Aavid Thermalloy (ejemplo)
   - **Modelo**: HS-100 (ejemplo)
   - **Características**:
     - Material de aluminio 
     - Dimensiones variables según el componente a refrigerar 
     - Mejora la disipación térmica en circuitos electrónicos 
   - **Cantidad**: Según necesidad 

- **Power Supply Unit**
   - **Marca**: Mean Well 
   - **Modelo**: LRS-150-5 
   - **Características**:
     - Salida de voltaje ajustable a +5V DC 
     - Potencia máxima de salida de hasta150W 
     - Eficiencia alta y tamaño compacto 
   - **Cantidad**: 1

- **Wires and Connectors**
   – Generalmente disponibles en tiendas electrónicas.
   – Variedad de tamaños y tipos según la aplicación.
   – Se recomienda tener al menos un rollo de cableado y varios conectores.

- **Emergency Cutoff Switch**
   – Generalmente disponible en tiendas electrónicas.
   – Interruptor tipo botón o palanca para corte rápido.
   – Debe ser adecuado para la corriente del sistema.

### Herramientas

- **Impresora 3D**: Utilizada para crear prototipos y piezas personalizadas necesarias para el montaje físico del sistema.

- **Software CAD**: Herramientas como SolidWorks o Fusion 360 son útiles para diseñar y simular las piezas mecánicas antes de su fabricación[5].

- **Multímetro**: Para realizar pruebas eléctricas y verificar conexiones en el circuito.

- **Soldador y Estaño**: Para realizar conexiones eléctricas permanentes entre los componentes.

- **Protoboard o PCB personalizada**: Facilita el montaje inicial y las pruebas del circuito antes de pasar a una placa de circuito impreso definitiva.

- **Herramientas de mano**: Destornilladores, alicates y otras herramientas manuales son necesarias para el ensamblaje físico del sistema.

- **Fuente de alimentación regulable**: Permite ajustar los niveles de voltaje necesarios para los diferentes componentes del sistema.

- **Pinzas de sujeción y soporte de soldadura**: Herramientas que facilitan el trabajo con componentes pequeños y delicados durante el proceso de soldadura.

## Referencias

[1] https://en.wikipedia.org/wiki/Arduino_UNO

[2] https://www.jsumo.com/sg90-micro-servo-motor

[3] https://cl.urany.net/blog/principales-componentes-de-un-sistema-de-control-de-movimiento

[4] https://www.contact-evolution.ch/files/DC_motors.pdf

[5] https://www.camsco.com.tw/micro-mini-limit-switch/limit-switch-specifications.html

[6] https://www.globalspec.com/learnmore/optics_optical_components/optoelectronics/optocouplers

[7] https://www.eaton.com/content/dam/eaton/products/electronic-components/resources/technical/eaton-fuse-technology-terminology-specifications-device-selection.pdf

[8] https://blog.precision.cl/multimetros-digitales-como-elegirlos

[9] https://coolinnovations.com/products/general-purpose-heat-sinks/data-sheets/

[10] https://library.e.abb.com/public/01062990474d471f9c22a4cb6538ad5b/2CDC114099D0201_G_CP-C.1_24_5_datasheet.pdf

[11] https://whadda.com/product/arduino-uno-rev-3-arduino-uno-r3/

[12] https://www.robotpark.com/L298N-Dual-H-Bridge-Motor-Driver

[13] https://www.farnell.com/datasheets/1682209.pdf

[14] https://www.xataka.com/basics/que-arduino-como-funciona-que-puedes-hacer-uno

[15] https://daneel-mechatronics.com/productos/sistemas-y-componentes-electronicos-de-control/

[16] https://robotuno.com/proyecto-con-arduino-ruleta-led-aleatoria/

[17] https://roboticaxyz.com/herramientas/

[18] https://www.artec3d.com/es/learning-center/best-cad-software-for-mechanical-engineers

[19] https://cl.urany.net/blog/principales-componentes-de-un-sistema-de-control-de-movimiento

[20] https://www.cursoderobotica.com/herramientas-para-electronica/