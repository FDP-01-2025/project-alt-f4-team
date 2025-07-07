#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <limits>
using namespace std;

struct Carta {
    char valor[3];  
    char palo;      
};


void crearbaraja(Carta baraja[52]) {
    const char* valores[] = {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    const char palos[] = {'P','C','D','T'};
    int k = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            strcpy(baraja[k].valor, valores[j]);
            baraja[k].palo = palos[i];
            k++;
        }
    }
}



void barajar(Carta baraja[52]) {
    for (int i = 0; i < 52; i++) {
        int j = rand() % 52;
        Carta temp = baraja[i];
        baraja[i] = baraja[j];
        baraja[j] = temp;
    }
}

void mostrarmano(Carta mano[5], bool ocultar = false) {
    for (int i = 0; i < 5; i++) {
        if (ocultar)
            cout << i + 1 << ") [??]  ";
        else
            cout << i + 1 << ") " << mano[i].valor << mano[i].palo << "  ";
    }
    cout << endl;
}


int valornumerico(const char* v) {
    if (strcmp(v, "J") == 0) return 11;
    if (strcmp(v, "Q") == 0) return 12;
    if (strcmp(v, "K") == 0) return 13;
    if (strcmp(v, "A") == 0) return 14;
    return atoi(v);
}

int contarvalor(Carta mano[5], const char* v) {
    int c = 0;
    for (int i = 0; i < 5; i++)
        if (strcmp(mano[i].valor, v) == 0) c++;
    return c;
}


int evaluarjugada(Carta mano[5], char resultado[30]) {
    int valores[5];
    int repeticiones[15] = {0};
    int palos[4] = {0}; 

    for (int i = 0; i < 5; i++) {
        valores[i] = valornumerico(mano[i].valor);
        repeticiones[valores[i]]++;

        if (mano[i].palo == 'P') palos[0]++;
        else if (mano[i].palo == 'C') palos[1]++;
        else if (mano[i].palo == 'D') palos[2]++;
        else if (mano[i].palo == 'T') palos[3]++;
    }

    for (int i = 0; i < 4; i++)
        for (int j = i + 1; j < 5; j++)
            if (valores[i] > valores[j]) {
                int tmp = valores[i];
                valores[i] = valores[j];
                valores[j] = tmp;
            }

    bool escalera = true;
    for (int i = 1; i < 5; i++)
        if (valores[i] != valores[i - 1] + 1) escalera = false;

    bool color = false;
    for (int i = 0; i < 4; i++)
        if (palos[i] == 5) color = true;

    if (escalera && color) { strcpy(resultado, "Escalera de color"); return 9; }
    for (int i = 2; i <= 14; i++)
        if (repeticiones[i] == 4) { strcpy(resultado, "Póker"); return 8; }

    bool tiene3 = false, tiene2 = false;
    for (int i = 2; i <= 14; i++) {
        if (repeticiones[i] == 3) tiene3 = true;
        if (repeticiones[i] == 2) tiene2 = true;
    }
    if (tiene3 && tiene2) { strcpy(resultado, "Full house"); return 7; }
    if (color) { strcpy(resultado, "Color"); return 6; }
    if (escalera) { strcpy(resultado, "Escalera"); return 5; }
    if (tiene3) { strcpy(resultado, "Trío"); return 4; }

    int pares = 0;
    for (int i = 2; i <= 14; i++)
        if (repeticiones[i] == 2) pares++;
    if (pares == 2) { strcpy(resultado, "Doble par"); return 3; }
    if (pares == 1) { strcpy(resultado, "Par"); return 2; }

    strcpy(resultado, "Carta alta");
    return 1;
}