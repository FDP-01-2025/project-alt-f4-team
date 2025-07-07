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
     jugador jugadores[num_jugadores];
    char baraja[tam_baraja][3];
    int tope = 0;
      void crear_baraja() {
        int idx = 0;
        for (int i = 0; i < 13; i++) {
            for (int j = 0; j < 4; j++) {
                strcpy(baraja[idx++], valores[i]);
            }
        }
    }
 void barajar() {
        for (int i = 0; i < tam_baraja; i++) {
            int j = rand() % tam_baraja;
            char temp[3];
            strcpy(temp, baraja[i]);
            strcpy(baraja[i], baraja[j]);
            strcpy(baraja[j], temp);
        }
    }
    void repartir(jugador& j, int cantidad) {
        for (int i = 0; i < cantidad && tope < tam_baraja; i++) {
            strcpy(j.mano[j.cantidad++], baraja[tope++]);
        }
    }
   void mostrar_mano(jugador& j) {
        cout << "tu mano: ";
        for (int i = 0; i < j.cantidad; i++) {
            cout << j.mano[i] << " ";
        }
        cout << endl;
    }
int contar_valor(jugador& j, const char* val) {
        int cont = 0;
        for (int i = 0; i < j.cantidad; i++) {
            if (strcmp(j.mano[i], val) == 0) cont++;
        }
        return cont;
    }
};
