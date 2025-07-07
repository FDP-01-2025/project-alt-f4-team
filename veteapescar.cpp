#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

class veteapescar {
private:
    const static int num_jugadores = 3;
    const static int tam_max = 26;
    const static int tam_baraja = 52;
    const char* valores[13] = {"a","2","3","4","5","6","7","8","9","10","j","q","k"};
struct jugador {
        char mano[tam_max][3];
        int cantidad = 0;
        int cuartetos = 0;
        const char* nombre;
    };
};
