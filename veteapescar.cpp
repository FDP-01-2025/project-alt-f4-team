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
    void eliminar_cuartetos(jugador& j) {
        for (int v = 0; v < 13; v++) {
            int cuenta = contar_valor(j, valores[v]);
            if (cuenta == 4) {
                int k = 0;
                for (int i = 0; i < j.cantidad; i++) {
                    if (strcmp(j.mano[i], valores[v]) != 0) {
                        strcpy(j.mano[k++], j.mano[i]);
                    }
                }
                j.cantidad = k;
                j.cuartetos++;
                cout << j.nombre << " formo un cuarteto de " << valores[v] << "\n";
            }
        }
    }
     bool transferir(jugador& de, jugador& a, const char* valor) {
        bool encontrado = false;
        for (int i = 0; i < de.cantidad;) {
            if (strcmp(de.mano[i], valor) == 0) {
                strcpy(a.mano[a.cantidad++], de.mano[i]);
                for (int j = i; j < de.cantidad - 1; j++) {
                    strcpy(de.mano[j], de.mano[j + 1]);
                }
                de.cantidad--;
                encontrado = true;
            } else {
                i++;
            }
        }
        return encontrado;
    }
     const char* carta_aleatoria(jugador& j) {
        if (j.cantidad == 0) return "";
        return j.mano[rand() % j.cantidad];
    }
void turno(jugador& actual, jugador oponentes[2], bool es_humano) {
        if (actual.cantidad == 0 && tope < tam_baraja) {
            strcpy(actual.mano[actual.cantidad++], baraja[tope++]);
        }

        if (actual.cantidad == 0) return;

        char valor[3];
        if (es_humano) {
            mostrar_mano(actual);
            cout << "¿que valor quieres pedir? ";
            cin >> valor;
        } else {
            strcpy(valor, carta_aleatoria(actual));
            cout << actual.nombre << " pregunta por " << valor << ".\n";
        }

        bool acierto = false;
        for (int i = 0; i < 2; i++) {
            if (transferir(oponentes[i], actual, valor)) {
                cout << oponentes[i].nombre << " entrego cartas de " << valor << " a " << actual.nombre << ".\n";
                acierto = true;
            }
        }

        if (!acierto && tope < tam_baraja) {
            cout << actual.nombre << " pesco una carta.\n";
            strcpy(actual.mano[actual.cantidad++], baraja[tope++]);
        } else if (!acierto) {
            cout << actual.nombre << " quiso pescar pero el mazo esta vacio.\n";
        }

        eliminar_cuartetos(actual);
    }

    bool terminado() {
        int total = 0;
        for (int i = 0; i < num_jugadores; i++) {
            total += jugadores[i].cuartetos;
        }
        return total == 13 || (
            jugadores[0].cantidad == 0 &&
            jugadores[1].cantidad == 0 &&
            jugadores[2].cantidad == 0 &&
            tope >= tam_baraja
        );
    }

    void mostrar_resultados() {
        cout << "\nresultados:\n";
        for (int i = 0; i < num_jugadores; i++) {
            cout << jugadores[i].nombre << ": " << jugadores[i].cuartetos << " cuartetos\n";
        }

        int max_c = -1, ganador = -1;
        for (int i = 0; i < num_jugadores; i++) {
            if (jugadores[i].cuartetos > max_c) {
                max_c = jugadores[i].cuartetos;
                ganador = i;
            }
        }

        cout << jugadores[ganador].nombre << " gana la partida\n";
    }

public:
    void jugar() {
        srand(time(0));
        crear_baraja();
        barajar();

        jugadores[0] = {{}, 0, 0, "jugador"};
        jugadores[1] = {{}, 0, 0, "cpu1"};
        jugadores[2] = {{}, 0, 0, "cpu2"};

        for (int i = 0; i < num_jugadores; i++) {
            repartir(jugadores[i], 7);
            eliminar_cuartetos(jugadores[i]);
        }

        int turno_actual = 0;
        while (!terminado()) {
            cout << "\nturno de " << jugadores[turno_actual].nombre << "\n";

            jugador oponentes[2];
            int idx = 0;
            for (int i = 0; i < num_jugadores; i++) {
                if (i != turno_actual)
                    oponentes[idx++] = jugadores[i];
            }

            turno(jugadores[turno_actual], oponentes, turno_actual == 0);
            turno_actual = (turno_actual + 1) % num_jugadores;
            system("pause");
        }

        mostrar_resultados();
    }

};

