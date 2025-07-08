[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/mi1WNrHU)

# 🂡 Cartas VS

**🏫 Universidad Centroamericana José Simeón Cañas**  
**📘 Fundamentos de Programación**  

🧮 Aula: ICAS 24 &nbsp;&nbsp;|&nbsp;&nbsp; 🧑‍🏫 Sección: 01 &nbsp;&nbsp;|&nbsp;&nbsp; 👨‍🏫 Docente: Guillermo Cortés  

## 🎯 Proyecto: Cartas VS  

**👥 Estudiantes:**  
- 🎓 Néstor Josué Arana Guevara - 00092725  
- 🎓 Fernando José Barrera Contreras - 00115725  
- 🎓 Adrián Emanuel Escobar Avilés – 00032125  

📍 Antiguo Cuscatlán, lunes 7 de julio de 2025  

---

## 📑 Índice

1. 🎯 Objetivos  
2. 📝 Descripción del Proyecto  
3. 🧪 Mockups del Juego  
4. 💡 Recomendaciones  
5. 🙏 Agradecimientos  
6. 📚 Librerías Utilizadas
7. 🖥️ Instrucciones de Ejecución

---

## 1. 🎯 Objetivos

### 🎯 Objetivo General
Diseñar y desarrollar un videojuego de cartas completamente funcional utilizando el lenguaje de programación C++, que se ejecute desde la consola y permita al usuario elegir entre dos modalidades de juego: individual contra una inteligencia artificial básica o multijugador local por turnos. El objetivo principal es aplicar de forma práctica los conceptos fundamentales de la programación estructurada, tales como condicionales, ciclos, funciones, manejo de arreglos y estructuras de control, mediante un proyecto que estimule el aprendizaje creativo, la lógica y el trabajo colaborativo.

### ✅ Objetivos Específicos
1. 💻 Desarrollar la lógica y mecánicas de tres juegos de cartas clásicos —Póker simplificado, Blackjack y Vete a Pescar— adaptados a un entorno de consola en C++.  
2. 🤝 Fomentar el trabajo en equipo, el aprendizaje autónomo y la responsabilidad compartida entre los miembros del grupo a través de la distribución equilibrada de tareas.

---

## 2. 📝 Descripción del Proyecto

El proyecto titulado **"Cartas VS"** consiste en el diseño y desarrollo de un videojuego de cartas ejecutable desde la consola, programado en el lenguaje C++. Está orientado a reforzar de forma práctica los conocimientos adquiridos durante el curso Fundamentos de Programación, haciendo énfasis en la aplicación de estructuras de control, ciclos, funciones, condicionales, manejo de arreglos y conceptos básicos de entrada y salida de datos.

El videojuego incluirá tres minijuegos clásicos de cartas: **Póker simplificado**, **Blackjack (21)** y **Vete a Pescar**, todos adaptados para funcionar en una interfaz de texto dentro de la consola. El jugador podrá seleccionar el juego que desea iniciar desde un menú principal, así como el modo de juego.

### 🧩 Características generales del sistema
- 📜 El menú principal ofrecerá al usuario la opción de elegir entre los tres juegos disponibles o salir del programa.  
- 🧩 Todos los juegos estarán programados de forma modular.  
- 🖼️ La interfaz será completamente textual, utilizando caracteres ASCII.  
- 🧠 El programa controlará el flujo, verificará condiciones de victoria y mostrará resultados.  
- 🛡️ Entrada de datos controlada mediante validaciones.

---

### 🃏 Detalles de cada juego implementado

#### ♠️ 1. Póker simplificado
En esta versión básica, el jugador recibe una mano de 5 cartas, puede cambiar algunas y se evalúa la jugada contra la de la IA.

**🔧 Elementos clave:**
- Evaluación automática de jugadas  
- Comparación entre manos  
- Funciones para generar, evaluar y mostrar cartas  

#### ♦️ 2. Blackjack (21)
Objetivo: llegar a 21 sin pasarse. Se juega contra la banca controlada por la máquina.

**🔧 Elementos clave:**
- Valor variable del As  
- Turnos del jugador y de la IA  
- Evaluación de condiciones de victoria  

#### 🎣 3. Vete a Pescar
Juego por turnos. Se piden cartas al oponente para formar cuartetos. Gana quien forme más.

**🔧 Elementos clave:**
- Turnos entre jugadores  
- Manejo del mazo y detección de pares  
- Control de finalización del juego  

---

### 🛠️ Aspectos técnicos destacados
- **📦 Variables y tipos de datos**  
- **🔁 Condicionales y bucles**  
- **🧮 Funciones organizadas modularmente**  
- **🧾 Entrada y salida de datos con `cin` y `cout`**

---

### 🗂️ Modularidad y estructura del código
El programa se organiza por funciones e incluye archivos `.h` separados cuando es necesario, fomentando una estructura profesional y clara.

---

### 🎮 Interacción con el usuario
El flujo es intuitivo desde el menú principal. Cada juego contiene instrucciones claras, cartas presentadas con ASCII y mensajes amigables para el jugador.

---

## 3. 🧪 Mockups del Juego

🎴 **1. Menú Principal**  
![🟦 Menú Principal](https://github.com/user-attachments/assets/4c3366f7-14b7-467b-9794-039fdfcb58e8)

🃏 **2. Menú Póker**  
![♠️ Menú Poker](https://github.com/user-attachments/assets/085d5cac-ffc0-4b0e-ae20-2c83e99251ae)

🃏 **3. Partida Póker**  
![♠️ Partida Poker](https://github.com/user-attachments/assets/0beaabf5-f83c-4349-98b8-df3236a97856)

♦️ **4. Menú Blackjack**  
![Menú Blackjack](https://github.com/user-attachments/assets/239eae73-a50b-415d-91c6-32151c0152e5)

♦️ **5. Partida Blackjack**  
![Partida Blackjack](https://github.com/user-attachments/assets/c88b6b3b-1928-4235-86fc-c449490f8c3d)

🎣 **6. Menu Vete a Pescar**  
![Menu GoFish](https://github.com/user-attachments/assets/5cbb680a-9b4e-4db7-a137-c0e2c9e58ab1)

🎣 **7. Partida Vete a Pescar**
![Partida GoFish](https://github.com/user-attachments/assets/63207db7-9b17-4981-9d23-023c49b9082f)

---

## 4. 💡 Recomendaciones
- 🗓️ Planificar el proyecto desde el inicio con roles bien definidos  
- 💬 Comentar el código constantemente  
- 🧪 Realizar pruebas tras cada avance  
- 🧼 Priorizar claridad visual en la interfaz  
- 💾 Hacer respaldos frecuentes usando Git  
- 🚀 Atreverse a experimentar e innovar

---

## 5. 🙏 Agradecimientos

Queremos expresar nuestro sincero agradecimiento a todas las personas e instituciones que han contribuido, directa o indirectamente, a la realización de este proyecto.

En primer lugar, extendemos nuestro reconocimiento y gratitud al docente Guillermo Cortés, quien durante todo el curso de Fundamentos de Programación nos brindó una enseñanza clara, paciente y comprometida. Agradecer igualmente al ingeniero Miguel Rivas por guiarnos durante el desarrollo del proyecto.

Agradecemos también a la Universidad Centroamericana José Simeón Cañas (UCA) por proporcionarnos un entorno académico que favorece el pensamiento lógico, el trabajo colaborativo y el desarrollo de competencias profesionales.

Igualmente, valoramos la colaboración y el espíritu de equipo entre nosotros como estudiantes.

Finalmente, agradecemos a nuestras familias por su comprensión y apoyo durante las largas jornadas de trabajo y estudio.

---

## 6. 📚 Librerías Utilizadas

El proyecto utiliza las siguientes librerías de C++ para su funcionamiento:

### 🔧 Librerías Estándar de C++

| Librería | Propósito | Uso en el Proyecto |
|----------|-----------|-------------------|
| `<iostream>` | 📝 Entrada y salida estándar | Manejo de `cin`, `cout` para interacción con el usuario |
| `<cstdlib>` | 🎲 Funciones de utilidad general | Generación de números aleatorios con `rand()` y `srand()` |
| `<ctime>` | ⏰ Funciones de tiempo | Semilla para números aleatorios con `time()` |
| `<string>` | 📄 Manejo de cadenas de texto | Almacenamiento de nombres de cartas y mensajes |
| `<cstring>` | 🔤 Funciones de cadenas C | Manipulación de arrays de caracteres con `strcpy()` |

### 🖥️ Librerías Específicas de Windows

| Librería | Propósito | Uso en el Proyecto |
|----------|-----------|-------------------|
| `<windows.h>` | 🪟 API de Windows | Función `Sleep()` para pausas visuales en los juegos |
| `<conio.h>` | ⌨️ Entrada de consola | Función `_getch()` para navegación del menú sin presionar Enter |

### 📋 Detalles de Implementación

#### 🎲 **Generación de Números Aleatorios**
- **`srand(time(0))`**: Inicializa la semilla aleatoria con el tiempo actual
- **`rand()`**: Genera números aleatorios para barajar cartas y decisiones de IA

#### ⌨️ **Interacción de Usuario**
- **`cin` y `cout`**: Entrada y salida básica de datos
- **`_getch()`**: Captura teclas sin esperar Enter (navegación de menú)
- **`getline()`**: Lectura de líneas completas para entrada de texto

#### 🎮 **Efectos Visuales**
- **`Sleep()`**: Pausas para crear efectos dramáticos durante el juego
- **`system("cls")`**: Limpieza de pantalla para interfaz limpia

#### 🔤 **Manejo de Texto**
- **`string`**: Almacenamiento dinámico de texto
- **`strcpy()`**: Copia de nombres de jugadores en estructuras

### ⚠️ **Consideraciones de Compatibilidad**
- Las librerías `<windows.h>` y `<conio.h>` son **específicas de Windows**
- Para portabilidad a otros sistemas operativos, estas funciones requerirían alternativas multiplataforma
- El resto de librerías son **estándar de C++** y funcionan en cualquier sistema

---

## 7. 🖥️ Instrucciones de Ejecución

### 📋 Requisitos Previos
- **Sistema Operativo:** Windows (requerido para `windows.h` y `conio.h`)
- **Compilador:** MinGW-w64, Visual Studio, o cualquier compilador de C++ compatible con Windows

### 🚀 Pasos para Ejecutar

1. **Clonar el repositorio:**
   \`\`\`bash
   git clone https://github.com/FDP-01-2025/project-alt-f4-team.git
   cd project-alt-f4-team
   \`\`\`

2. **Compilar el proyecto:**
   \`\`\`bash
   g++ -o cartas_vs main.cpp
   \`\`\`

3. **Ejecutar el juego:**
   \`\`\`bash
   ./cartas_vs
   \`\`\`
   o en Windows:
   \`\`\`cmd
   cartas_vs.exe
   \`\`\`

### 🎮 Controles del Juego
- **↑/↓:** Navegar por el menú principal
- **Enter:** Seleccionar opción
- **Seguir las instrucciones en pantalla** para cada juego específico

### 📁 Estructura del Proyecto
\`\`\`
project-alt-f4-team/
├── main.cpp              # Archivo principal con menú
├── src/
│   ├── card.h           # Definición de cartas
│   ├── deck.h           # Manejo del mazo
│   ├── utils.h          # Funciones utilitarias
│   ├── poker.h          # Lógica del Póker
│   ├── blackjack.h      # Lógica del Blackjack
│   └── gofish.h         # Lógica del Vete a Pescar
└── README.md            # Este archivo
\`\`\`

### ⚠️ Notas Importantes
- El juego está optimizado para **Windows** debido al uso de librerías específicas
- Asegúrate de tener un compilador de C++ instalado
- El juego se ejecuta completamente en la consola/terminal

