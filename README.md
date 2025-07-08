[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/mi1WNrHU)

# Cartas VS

**Universidad Centroamericana José Simeón Cañas**  
**Fundamentos de Programación**  
Aula: ICAS 24. Sección: 01  
Docente: Guillermo Cortés  

### Proyecto: Cartas VS  

**Estudiantes:**  
- Néstor Josué Arana Guevara - 00092725  
- Fernando José Barrera Contreras - 00115725  
- Adrián Emanuel Escobar Avilés – 00032125  

Antiguo Cuscatlán, lunes 7 de julio de 2025  

---

## Índice

1. Objetivos  
2. Descripción del Proyecto  
3. Flujograma  
4. Recomendaciones  
5. Agradecimientos  

---

## 1. Objetivos

### Objetivo General

Diseñar y desarrollar un videojuego de cartas completamente funcional utilizando el lenguaje de programación C++, que se ejecute desde la consola y permita al usuario elegir entre dos modalidades de juego: individual contra una inteligencia artificial básica o multijugador local por turnos. El objetivo principal es aplicar de forma práctica los conceptos fundamentales de la programación estructurada, tales como condicionales, ciclos, funciones, manejo de arreglos y estructuras de control, mediante un proyecto que estimule el aprendizaje creativo, la lógica y el trabajo colaborativo.

### Objetivos Específicos

1. Desarrollar la lógica y mecánicas de tres juegos de cartas clásicos —Póker simplificado, Blackjack y Vete a Pescar— adaptados a un entorno de consola en C++. Cada juego contará con reglas y dinámicas definidas que serán programadas mediante el uso adecuado de estructuras de datos, condicionales, funciones personalizadas, ciclos iterativos y estructuras selectivas.

2. Fomentar el trabajo en equipo, el aprendizaje autónomo y la responsabilidad compartida entre los miembros del grupo a través de la distribución equilibrada de tareas, el seguimiento del avance y la documentación continua del proyecto. Durante el desarrollo del videojuego, cada integrante del equipo asumirá roles definidos, ya sea en el diseño lógico, la codificación, las pruebas o la documentación. Se mantendrá un registro de avances, dificultades y decisiones técnicas, lo cual permitirá mejorar la comunicación interna, aprender de los errores y generar un producto final que no solo cumpla los objetivos técnicos, sino que también refleje el esfuerzo y la colaboración de todos los participantes.

---

## 2. Descripción del Proyecto

En esta sección se detalla el proyecto de juego, incluyendo:

El proyecto titulado “Cartas VS” consiste en el diseño y desarrollo de un videojuego de cartas ejecutable desde la consola, programado en el lenguaje C++. Está orientado a reforzar de forma práctica los conocimientos adquiridos durante el curso Fundamentos de Programación, haciendo énfasis en la aplicación de estructuras de control, ciclos, funciones, condicionales, manejo de arreglos y conceptos básicos de entrada y salida de datos.

El videojuego incluirá tres minijuegos clásicos de cartas: Póker simplificado, Blackjack (21) y Vete a Pescar, todos adaptados para funcionar en una interfaz de texto dentro de la consola. El jugador podrá seleccionar el juego que desea iniciar desde un menú principal, así como el modo de juego: contra una inteligencia artificial básica (IA) o modo multijugador local, en el cual dos o tres usuarios se turnan utilizando el mismo dispositivo, en el caso de Vete a Pescar.

### Características generales del sistema

- El menú principal ofrecerá al usuario la opción de elegir entre los tres juegos disponibles o salir del programa.  
- Todos los juegos estarán programados de forma modular, es decir, con funciones separadas que permitan mayor organización y mantenimiento del código.  
- La interfaz del usuario será completamente textual, con una presentación clara y organizada utilizando caracteres ASCII para simular las cartas, los menús y las jugadas realizadas.  
- El programa controlará el flujo de cada juego, verificará las condiciones de victoria y mostrará los resultados de cada partida.  
- La entrada de datos será controlada mediante validaciones para evitar errores durante el uso del sistema.  

### Detalles de cada juego implementado

#### 1. Póker simplificado

En esta versión básica de Póker, el jugador recibe una mano de 5 cartas generadas aleatoriamente. Luego tiene la oportunidad de cambiar una o varias cartas (indicando sus posiciones). Después del cambio, se evalúa la mano final y se compara con la de la máquina, la cual realiza un cambio automático con una lógica sencilla. Las jugadas posibles incluyen par, doble par, trío, full house, póker y escalera.

**Elementos clave:**

- Evaluación automática de jugadas  
- Comparación entre manos del jugador y de la IA  
- Uso de funciones para generar cartas, verificar combinaciones y mostrar resultados  

#### 2. Blackjack (21)

En este juego, el objetivo del jugador es sumar lo más cerca posible a 21 sin pasarse. El jugador comienza con dos cartas. El jugador decide si quiere otra carta (“pedir”) o si desea detenerse (“plantarse”). La banca (la máquina) juega después, siguiendo una lógica preestablecida (por ejemplo, pedir hasta llegar a 17). Al final se comparan los puntajes para determinar al ganador.

**Elementos clave:**

- Lógica de suma de valores de cartas, controlando el valor del As como 1 u 11  
- Control de turnos y decisiones del jugador  
- Evaluación de condiciones de victoria  

#### 3. Vete a Pescar

Este es un juego por turnos en el que el jugador debe pedirle al otro una carta de un valor específico (por ejemplo: “¿Tienes algún 5?”). Si el oponente tiene una o más cartas de ese valor, las entrega. Si no, el jugador “pesca” del mazo. El objetivo es formar la mayor cantidad de cuatro cartas iguales posibles. El juego termina cuando el jugador llegue a juntar 3 veces cuatro cartas del mismo número o letra.

**Elementos clave:**

- Comunicación entre jugadores 
- Detección y eliminación de pares en la mano  
- Lógica de pesca y control del mazo  

---

### Aspectos técnicos destacados

- **Variables y tipos de datos**: Se utilizan para representar las cartas, manos, mazo, puntajes y estados de juego.  
- **Condicionales**: Aplicadas para verificar combinaciones ganadoras, decisiones del jugador, estados de victoria o derrota, etc.  
- **Bucles**: Controlan las rondas de juego, la petición de cartas, la repartición y validación de manos.  
- **Funciones**: Organizan el código para tareas específicas como generar cartas, repartir manos, evaluar jugadas y mostrar información en pantalla.  
- **Entrada y salida de datos**: Se trabaja con `cin` y `cout` para capturar decisiones del usuario y mostrar el estado del juego.  

---

### Modularidad y estructura del código

El programa estará dividido en secciones lógicas mediante el uso de funciones. Se incluirán archivos separados si es necesario (por ejemplo, archivos `.h` independientes), lo que permitirá una estructura más clara y profesional.

---

### Interacción con el usuario

Todo el flujo del programa está diseñado para ser intuitivo. Al iniciar, el jugador verá un menú general desde el que podrá acceder a los diferentes juegos. Cada juego tendrá instrucciones claras, una presentación organizada de cartas y resultados finales. Se busca que el usuario no necesite conocimientos previos para poder jugar.

---

## 3. Mockups del Juego
![Texto alternativo]("C:\Users\sando\OneDrive\Escritorio\Mockups\menu.png")

---

## 4. Recomendaciones

- Planificar adecuadamente el proyecto desde sus primeras etapas, estableciendo una división clara de tareas entre los integrantes del equipo.  
- Comentar el código durante su elaboración, para que todos los miembros del grupo comprendan su funcionamiento.  
- Realizar pruebas constantes después de programar cada función o bloque importante.  
- Priorizar la claridad de la interfaz de texto para facilitar la experiencia del usuario.  
- Guardar respaldos frecuentes del proyecto, preferiblemente usando Git.  
- Aprovechar este tipo de proyectos para experimentar e innovar.  

---

## 5. Agradecimientos

Queremos expresar nuestro sincero agradecimiento a todas las personas e instituciones que han contribuido, directa o indirectamente, a la realización de este proyecto.

En primer lugar, extendemos nuestro reconocimiento y gratitud al docente Guillermo Cortés, quien durante todo el curso de Fundamentos de Programación nos brindó una enseñanza clara, paciente y comprometida. Agradecer igualmente al ingeniero Miguel Rivas por guiarnos durante el desarrollo del proyecto.

Agradecemos también a la Universidad Centroamericana José Simeón Cañas (UCA) por proporcionarnos un entorno académico que favorece el pensamiento lógico, el trabajo colaborativo y el desarrollo de competencias profesionales.

Igualmente, valoramos la colaboración y el espíritu de equipo entre nosotros como estudiantes.

Finalmente, agradecemos a nuestras familias por su comprensión y apoyo durante las largas jornadas de trabajo y estudio.

---
