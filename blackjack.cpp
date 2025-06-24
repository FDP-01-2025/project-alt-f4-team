#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int suma = 0, opcion;
struct Carta
{
    string valor;
    int puntos;
};

Carta generarCarta()
{
    string valores[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    int puntos[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11};

    int i = rand() % 13;

    return {valores[i], puntos[i]};
}

void jugarBlackjack()
{
    srand(time(0));
    for (int i = 0; i < 2; i++)
    {
        Carta carta = generarCarta();
        cout << "Carta obtenida: [" << carta.valor << ", valor: " << carta.puntos << "]" << endl;

        suma += carta.puntos;
    }
    cout << "Tiene un puntaje de: " << suma << endl;
    cout << "Desea tomar otra carta?" << endl;
    cout << "1. Si" << endl;
    cout << "0. No" << endl;
    cin >> opcion;

    if (opcion == 1)
    {
        Carta carta = generarCarta();
        cout << "Carta obtenida: [" << carta.valor << ", valor: " << carta.puntos << "]" << endl;
        suma += carta.puntos;
    }
    cout << "Tiene un puntaje de: " << suma << endl;
}