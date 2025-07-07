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