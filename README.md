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
3. 🎨 Temática y Ambientación
4. 💻 Aplicación de los Temas Vistos
5. 🛠️ Consideraciones Técnicas del Desarrollo
6. 🧪 Mockups del Juego  
7. 💡 Recomendaciones  
8. 🙏 Agradecimientos  
9. 📚 Librerías Utilizadas
10. 🖥️ Instrucciones de Ejecución

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

## 3. 🎨 Temática y Ambientación

### 🎰 **Concepto General**

**"Cartas VS"** adopta la temática clásica de un **casino virtual** adaptado para consola, donde el jugador experimenta la emoción de los juegos de cartas tradicionales en un ambiente controlado y educativo.

### 🎭 **Elementos Temáticos**

#### 🏛️ **Ambientación de Casino Clásico**
- **Interfaz retro**: Uso de caracteres ASCII para recrear la estética de los primeros videojuegos
- **Mensajes inmersivos**: Frases como "¡Blackjack!" y "¡Buena jugada!" para mantener la emoción
- **Sistema de apuestas**: Dinero virtual que simula la experiencia de casino real

#### 🎨 **Diseño Visual**
- **Menús elegantes**: Marcos decorativos con asteriscos y líneas
- **Representación de cartas**: Formato compacto (ej: "AH", "KS") fácil de leer
- **Colores conceptuales**: Aunque es texto plano, se sugieren los colores tradicionales (rojo/negro)

#### 🎵 **Atmósfera Sonora Conceptual**
- **Pausas dramáticas**: Uso de `Sleep()` para crear tensión
- **Ritmo de juego**: Velocidad controlada para mantener el suspenso

### 🎪 **Experiencia de Usuario**
- **Navegación intuitiva**: Menú principal con selección por flechas
- **Feedback inmediato**: Respuestas claras a cada acción del jugador
- **Progresión**: Sistema de dinero que persiste entre partidas de Poker y Blackjack

---

## 4. 💻 Aplicación de los Temas Vistos

### 📊 **Implementación Detallada de Conceptos de Programación**

#### 🔢 **1. Variables y Tipos de Datos**

**📝 Tipos Básicos:**

```cpp
// Enteros para contadores y valores
int playerMoney = 1000;        // Dinero del jugador
int cardCount = 0;             // Contador de cartas
int choice = 0;                // Selección de menú

// Caracteres para representación
char suit = 'H';               // Palo de carta (Hearts)
char answer;                   // Respuesta y/n

// Booleanos para estados
bool isRunning = true;         // Control de bucle principal
bool playerBusted = false;     // Estado de juego
```

**📋 Tipos Compuestos:**

```cpp
// Strings para texto
string rankName = "Ace";       // Nombre de carta
string playerName;             // Nombre del jugador

// Arrays para colecciones
Card hand[MAX_HAND_SIZE];      // Mano de cartas
int values[HAND_SIZE];         // Valores para ordenamiento
```

#### 🏗️ **2. Estructuras (struct)**

**🃏 Estructura de Carta:**

```cpp
struct Card {
    string rank;    // Rango de la carta (A, 2-10, J, Q, K)
    char suit;      // Palo (H, D, C, S)
};
```

**🎮 Estructura de Jugador:**

```cpp
struct GoFishPlayer {
    Card hand[MAX_CARDS_IN_HAND];  // Cartas en mano
    int cardCount;                 // Número de cartas
    int books;                     // Libros formados
    char name[20];                 // Nombre del jugador
};
```

**🃏 Estructura de Mazo:**

```cpp
struct Deck {
    Card cards[DECK_SIZE];    // Array de 52 cartas
    int topCard;              // Índice de próxima carta
    
    // Métodos integrados
    void shuffle();           // Barajar cartas
    Card dealCard();          // Repartir carta
};
```

#### 🔄 **3. Estructuras de Control**

**🔀 Condicionales (if/else):**

```cpp
// Evaluación de mano en Blackjack
if (playerHand.isBlackjack()) {
    cout << "¡Blackjack! ¡Ganaste!" << endl;
    playerMoney += bet * 1.5;
} else if (playerHand.isBusted()) {
    cout << "¡Te pasaste! Perdiste $" << bet << endl;
    playerMoney -= bet;
} else {
    // Continuar juego normal
}
```

**🎯 Switch-Case:**

```cpp
// Menú principal
switch (choice) {
    case 0:
        playPoker(playerMoney);
        break;
    case 1:
        playBlackjack(playerMoney);
        break;
    case 2:
        playGoFish();
        break;
    case 3:
        cout << "¡Gracias por jugar!" << endl;
        return 0;
}
```

#### 🔁 **4. Ciclos (Loops)**

**♾️ While Loop:**

```cpp
// Bucle principal del juego
while (playerMoney > 0) {
    // Mostrar dinero actual
    cout << "Tu dinero: $" << playerMoney << endl;
    
    // Obtener apuesta
    int bet = getIntInput("Ingresa tu apuesta: ", 1, playerMoney);
    
    // Jugar ronda
    playRound(bet);
}
```

**🔢 For Loop:**

```cpp
// Repartir cartas iniciales
for (int i = 0; i < HAND_SIZE; i++) {
    player[i] = deck.dealCard();
    cpu[i] = deck.dealCard();
}

// Mostrar mano del jugador
for (int i = 0; i < player.cardCount; i++) {
    printCardShort(player.hand[i]);
    cout << " ";
}
```

**🔄 Do-While Loop:**

```cpp
// Validación de entrada
do {
    cout << "¿Quieres otra carta? (y/n): ";
    cin >> answer;
    
    if (cin.fail()) {
        cout << "Entrada inválida!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }
} while (cin.fail() || (answer != 'y' && answer != 'n'));
```

#### 🧮 **5. Funciones**

**📤 Funciones sin Retorno (void):**

```cpp
// Mostrar mano de cartas
void showHand(const GoFishPlayer& player) {
    cout << player.name << ", tu mano: ";
    for (int i = 0; i < player.cardCount; i++) {
        printCardShort(player.hand[i]);
        cout << " ";
    }
    cout << endl;
}

// Limpiar pantalla
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
```

**🔙 Funciones con Retorno:**

```cpp
// Evaluar mano de poker
int evaluateHand(Card hand[HAND_SIZE], string &result) {
    // Lógica de evaluación...
    if (straight && flush) {
        result = "Escalera de Color";
        return 9;
    }
    // Más evaluaciones...
    return handValue;
}

// Obtener valor de carta para Blackjack
int getCardValueBlackjack(const Card &card) {
    if (card.rank == "A") return 11;
    if (card.rank == "K" || card.rank == "Q" || card.rank == "J") 
        return 10;
    return stoi(card.rank);
}
```

**📥 Funciones con Parámetros por Referencia:**

```cpp
// Transferir cartas entre jugadores
bool transferCards(GoFishPlayer& from, GoFishPlayer& to, int rank) {
    bool found = false;
    for (int i = 0; i < from.cardCount;) {
        if (getCardValuePoker(from.hand[i]) == rank) {
            addCard(to, from.hand[i]);
            // Remover carta del jugador origen
            for (int j = i; j < from.cardCount - 1; j++) {
                from.hand[j] = from.hand[j + 1];
            }
            from.cardCount--;
            found = true;
        } else {
            i++;
        }
    }
    return found;
}
```

#### 📚 **6. Arrays y Manejo de Memoria**

**🗃️ Arrays Estáticos:**

```cpp
// Array de cartas en mano
Card playerHand[MAX_HAND_SIZE];

// Array de contadores para evaluación
int counts[15] = {};  // Inicializado en ceros

// Array de opciones de menú
string options[4] = {
    "1. Poker",
    "2. 21 (Blackjack)", 
    "3. Go Fish",
    "4. Salir"
};
```

**🔄 Manipulación de Arrays:**

```cpp
// Ordenamiento burbuja
void sort(int arr[], int n = HAND_SIZE) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
```

#### 🎲 **7. Generación de Números Aleatorios**

```cpp
// Inicialización de semilla
srand(time(0));

// Barajado de cartas
void shuffle() {
    for (int i = DECK_SIZE - 1; i > 0; i--) {
        int randIndex = rand() % (i + 1);
        Card temp = cards[i];
        cards[i] = cards[randIndex];
        cards[randIndex] = temp;
    }
}
```

#### 🛡️ **8. Validación de Entrada**

```cpp
// Función robusta de validación
int getIntInput(const string& prompt, int min, int max) {
    int input;
    do {
        cout << prompt;
        cin >> input;
        
        if (cin.fail()) {
            cout << "¡Entrada inválida! Ingresa un número." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        
        if (input < min || input > max) {
            cout << "Ingresa un número entre " << min << " y " << max << "." << endl;
        }
    } while (cin.fail() || input < min || input > max);
    
    return input;
}
```

---

## 5. 🛠️ Consideraciones Técnicas del Desarrollo

### 🏗️ **Arquitectura del Sistema**

#### 📁 **Organización Modular**

```
src/
├── card.h      - Definición y manejo de cartas individuales
├── deck.h      - Gestión del mazo completo y barajado
├── utils.h     - Funciones utilitarias y validación
├── poker.h     - Lógica específica del juego de Poker
├── blackjack.h - Implementación del Blackjack
└── gofish.h    - Mecánicas del juego Vete a Pescar
```

#### 🔗 **Separación de Responsabilidades**
- **Presentación**: Funciones de interfaz y menús
- **Lógica de Negocio**: Reglas de juegos y evaluaciones
- **Datos**: Estructuras de cartas y jugadores
- **Utilidades**: Validación y funciones auxiliares

### ⚡ **Optimización y Rendimiento**

#### 🚀 **Eficiencia Algorítmica**

```cpp
// Algoritmo de Fisher-Yates para barajado O(n)
void shuffle() {
    for (int i = DECK_SIZE - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(cards[i], cards[j]);
    }
}

// Búsqueda optimizada de pares O(n)
int countRank(const GoFishPlayer& player, int rank) {
    int count = 0;
    for (int i = 0; i < player.cardCount; i++) {
        if (getCardValuePoker(player.hand[i]) == rank) {
            count++;
        }
    }
    return count;
}
```

#### 💾 **Gestión de Memoria**
- **Arrays estáticos**: Evita fragmentación de memoria
- **Paso por referencia**: Reduce copias innecesarias
- **Reutilización de estructuras**: Minimiza allocaciones

### 🛡️ **Robustez y Manejo de Errores**

#### ✅ **Validación Exhaustiva**

```cpp
// Validación de entrada con recuperación
bool askYesNoValidated(const string& prompt) {
    string input;
    while (true) {
        cout << prompt << " (y/n): ";
        getline(cin, input);
        
        if (input == "y" || input == "Y") return true;
        if (input == "n" || input == "N") return false;
        
        cout << "Entrada inválida. Ingresa 'y' o 'n'." << endl;
    }
}
```

#### 🔒 **Prevención de Estados Inválidos**

```cpp
// Verificación de límites de array
void addCard(GoFishPlayer& player, const Card& card) {
    if (player.cardCount < MAX_CARDS_IN_HAND) {
        player.hand[player.cardCount] = card;
        player.cardCount++;
    }
    // Silenciosamente ignora si está lleno (previene overflow)
}
```

### 🎮 **Experiencia de Usuario**

#### ⌨️ **Interfaz Intuitiva**

```cpp
// Navegación con flechas del teclado
int key = _getch();
if (key == 224 || key == 0) {  // Tecla extendida
    int arrow = _getch();
    if (arrow == 72) {          // Flecha arriba
        choice = (choice - 1 + 4) % 4;
    } else if (arrow == 80) {   // Flecha abajo
        choice = (choice + 1) % 4;
    }
}
```

#### 🎭 **Efectos Visuales**

```cpp
// Pausas dramáticas para crear tensión
void showHand(Card hand[HAND_SIZE], bool hide = false) {
    for (int i = 0; i < HAND_SIZE; i++) {
        if (hide) {
            cout << "[??] ";
        } else {
            printCardShort(hand[i]);
            cout << " ";
        }
        Sleep(400);  // Pausa para efecto visual
    }
    cout << endl;
}
```

### 🔧 **Mantenibilidad y Extensibilidad**

#### 📝 **Código Autodocumentado**

```cpp
// Nombres descriptivos y comentarios claros
bool isGameOver(GoFishPlayer players[], int numPlayers) {
    // Verificar si algún jugador ha alcanzado la condición de victoria
    for (int i = 0; i < numPlayers; i++) {
        if (players[i].books >= 3) {  // 3 libros = victoria
            return true;
        }
    }
    return false;
}
```

#### 🔄 **Reutilización de Código**

```cpp
// Funciones genéricas reutilizables
template<typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}
```

### 🧪 **Estrategias de Testing**

#### ✅ **Casos de Prueba Integrados**
- **Validación de entrada**: Números fuera de rango, caracteres inválidos
- **Estados límite**: Mazo vacío, mano llena, dinero agotado
- **Lógica de juego**: Todas las combinaciones de poker, valores de blackjack

#### 🐛 **Debugging y Monitoreo**

```cpp
#ifdef DEBUG
    cout << "DEBUG: Carta repartida: " << card.rank << card.suit << endl;
    cout << "DEBUG: Dinero actual: $" << playerMoney << endl;
#endif
```

---

## 6. 🧪 Mockups del Juego

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

## 7. 💡 Recomendaciones

- 🗓️ Planificar el proyecto desde el inicio con roles bien definidos  
- 💬 Comentar el código constantemente  
- 🧪 Realizar pruebas tras cada avance  
- 🧼 Priorizar claridad visual en la interfaz  
- 💾 Hacer respaldos frecuentes usando Git  
- 🚀 Atreverse a experimentar e innovar

---

## 8. 🙏 Agradecimientos

Queremos expresar nuestro sincero agradecimiento a todas las personas e instituciones que han contribuido, directa o indirectamente, a la realización de este proyecto.

En primer lugar, extendemos nuestro reconocimiento y gratitud al docente Guillermo Cortés, quien durante todo el curso de Fundamentos de Programación nos brindó una enseñanza clara, paciente y comprometida. Agradecer igualmente al ingeniero Miguel Rivas por guiarnos durante el desarrollo del proyecto.

Agradecemos también a la Universidad Centroamericana José Simeón Cañas (UCA) por proporcionarnos un entorno académico que favorece el pensamiento lógico, el trabajo colaborativo y el desarrollo de competencias profesionales.

Igualmente, valoramos la colaboración y el espíritu de equipo entre nosotros como estudiantes.

Finalmente, agradecemos a nuestras familias por su comprensión y apoyo durante las largas jornadas de trabajo y estudio.

---

## 9. 📚 Librerías Utilizadas

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

## 10. 🖥️ Instrucciones de Ejecución

### 📋 Requisitos Previos
- **Sistema Operativo:** Windows (requerido para `windows.h` y `conio.h`)
- **Compilador:** MinGW-w64, Visual Studio, o cualquier compilador de C++ compatible con Windows

### 🚀 Pasos para Ejecutar

1. **Clonar el repositorio:**
   ```bash
   git clone https://github.com/FDP-01-2025/project-alt-f4-team.git
   cd project-alt-f4-team
   ```

2. **Compilar el proyecto:**
   ```bash
   g++ -o cartas_vs main.cpp
   ```

3. **Ejecutar el juego:**
   ```bash
   ./cartas_vs
   ```
   o en Windows:
   ```cmd
   cartas_vs.exe
   ```

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
