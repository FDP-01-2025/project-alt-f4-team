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
    string palos[] = {"P", "C", "D", "T"}; // P=♠, C=♥, D=♦, T=♣ (ASCII-friendly)

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

void mostrarMano(const vector<Carta> &mano) {
    cout << "Tu mano:\n";
    for (int i = 0; i < mano.size(); i++) {
        cout << i+1 << ") " << mano[i].valor << mano[i].palo << "  ";
    }
    cout << endl;
}

vector<Carta> repartirMano(vector<Carta> &baraja) {
    vector<Carta> mano;
    for (int i = 0; i < 5; i++) {
        mano.push_back(baraja.back());
        baraja.pop_back();
    }
    return mano;
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

    // Evaluar escalera
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
void jugarPoker() {
    vector<Carta> baraja = crearBaraja();
    barajar(baraja);

    vector<Carta> mano = repartirMano(baraja);
    mostrarMano(mano);

    // Cambiar cartas
    cout << "\n¿Deseas cambiar alguna carta? (Ej: 2 5 o 0 para no cambiar): ";
    cin.ignore(); // Limpiar entrada anterior
    string entrada;
    getline(cin, entrada);

    stringstream ss(entrada);
    int idx;
    vector<int> cambiar;

    while (ss >> idx) {
        if (idx >= 1 && idx <= 5)
            cambiar.push_back(idx - 1);
    }

    for (int i : cambiar) {
        mano[i] = baraja.back();
        baraja.pop_back();
    }

    cout << "\nTu mano final:\n";
    mostrarMano(mano);

    string resultado = evaluarMano(mano);
    cout << "\nTu jugada: " << resultado << endl;

    system("pause");
}