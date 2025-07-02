#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <map>
#include <sstream>
using namespace std;

struct Carta {
    string valor;
    string palo;
};

vector<Carta> crearBaraja() {
    vector<Carta> baraja;
    string valores[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    string palos[] = {"P", "C", "D", "T"}; 

    for (const string &palo : palos) {
        for (const string &valor : valores) {
            baraja.push_back({valor, palo});
        }
    }
    return baraja;
}

void barajar(vector<Carta> &baraja) {
    srand(time(0));
    random_shuffle(baraja.begin(), baraja.end());
}

void mostrarMano(const vector<Carta> &mano, bool ocultar = false) {
    for (int i = 0; i < mano.size(); i++) {
        if (ocultar)
            cout << i + 1 << ") [??]  ";
        else
            cout << i + 1 << ") " << mano[i].valor << mano[i].palo << "  ";
    }
    cout << endl;
}

int valorNumerico(const string &valor) {
    if (valor == "J") return 11;
    if (valor == "Q") return 12;
    if (valor == "K") return 13;
    if (valor == "A") return 14;
    return stoi(valor);
}

string evaluarMano(const vector<Carta> &mano) {
    map<string, int> contador;
    map<string, int> palos;
    vector<int> valores;

    for (const auto &c : mano) {
        contador[c.valor]++;
        palos[c.palo]++;
        valores.push_back(valorNumerico(c.valor));
    }

    sort(valores.begin(), valores.end());

    bool escalera = true;
    for (int i = 1; i < valores.size(); i++) {
        if (valores[i] != valores[i - 1] + 1) {
            escalera = false;
            break;
        }
    }

    bool color = (palos.size() == 1);

    if (escalera && color) return "Escalera de color";
    if (count_if(contador.begin(), contador.end(), [](auto p){ return p.second == 4; })) return "Póker";
    if (count_if(contador.begin(), contador.end(), [](auto p){ return p.second == 3; }) &&
        count_if(contador.begin(), contador.end(), [](auto p){ return p.second == 2; })) return "Full house";
    if (color) return "Color";
    if (escalera) return "Escalera";
    if (count_if(contador.begin(), contador.end(), [](auto p){ return p.second == 3; })) return "Trío";
    if (count_if(contador.begin(), contador.end(), [](auto p){ return p.second == 2; }) == 2) return "Doble par";
    if (count_if(contador.begin(), contador.end(), [](auto p){ return p.second == 2; })) return "Par";

    return "Carta alta";
}

// Valor numérico de la jugada para comparar
int valorJugada(const string &jugada) {
    if (jugada == "Escalera de color") return 9;
    if (jugada == "Póker") return 8;
    if (jugada == "Full house") return 7;
    if (jugada == "Color") return 6;
    if (jugada == "Escalera") return 5;
    if (jugada == "Trío") return 4;
    if (jugada == "Doble par") return 3;
    if (jugada == "Par") return 2;
    return 1;
}

vector<Carta> repartirMano(vector<Carta> &baraja) {
    vector<Carta> mano;
    for (int i = 0; i < 5; i++) {
        mano.push_back(baraja.back());
        baraja.pop_back();
    }
    return mano;
}

vector<int> seleccionarCartasCPU(const vector<Carta>& mano) {
    map<string, int> contador;
    for (const auto &c : mano) contador[c.valor]++;
    vector<int> indices;

    // Buscar qué conservar
    for (int i = 0; i < mano.size(); i++) {
        if (contador[mano[i].valor] >= 2) continue; // Conservar pares o más
        indices.push_back(i); // Desechar lo demás
    }

    return indices;
}

void jugarPoker() {
    vector<Carta> baraja = crearBaraja();
    barajar(baraja);

    vector<Carta> jugador = repartirMano(baraja);
    vector<Carta> cpu = repartirMano(baraja);

    cout << "\nTu mano:\n";
    mostrarMano(jugador);
string entrada;
vector<int> cambiarJugador;

while (true) {
    cout << "\n¿Deseas cambiar cartas? (Ej: 2 4 o 0 para no cambiar): ";
    getline(cin, entrada);

    if (!entrada.empty()) {
        stringstream ss(entrada);
        int idx;
        bool valido = true;
        cambiarJugador.clear();

        while (ss >> idx) {
            if (idx == 0) {
                cambiarJugador.clear(); // no cambiar nada
                break;
            }
            if (idx >= 1 && idx <= 5) {
                cambiarJugador.push_back(idx - 1);
            } else {
                valido = false;
                break;
            }
        }

        if (valido) break;
        else cout << "Entrada inválida. Intenta de nuevo.\n";
    }
}

for (int i : cambiarJugador) {
    jugador[i] = baraja.back();
    baraja.pop_back();
}

    // Cambio de cartas CPU
    vector<int> cambiarCPU = seleccionarCartasCPU(cpu);
    for (int i : cambiarCPU) {
        cpu[i] = baraja.back();
        baraja.pop_back();
    }

    // Mostrar resultados
    cout << "\nTu mano final:\n";
    mostrarMano(jugador);
    string jugadaJugador = evaluarMano(jugador);
    cout << "Tu jugada: " << jugadaJugador << "\n";

    cout << "\nMano de la CPU:\n";
    mostrarMano(cpu);
    string jugadaCPU = evaluarMano(cpu);
    cout << "Jugada de la CPU: " << jugadaCPU << "\n";

    // Ganador
    int vj = valorJugada(jugadaJugador);
    int vc = valorJugada(jugadaCPU);

    if (vj > vc) cout << "\n¡Ganaste la partida!\n";
    else if (vc > vj) cout << "\nLa CPU gana esta ronda.\n";
    else cout << "\n¡Empate!\n";

    system("pause");
}
