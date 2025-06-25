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
    suma = 0;
    
    for (int i = 0; i < 2; i++)
    {
        Carta carta = generarCarta();
        cout << "Carta obtenida: [" << carta.valor << ", valor: " << carta.puntos << "]" << endl;

        suma += carta.puntos;
    }

    while (suma < 21)
    {
        cout << "Tiene un puntaje de: " << suma << endl;

        do
        {
            cout << "Desea tomar otra carta?" << endl;
            cout << "1. Si" << endl;
            cout << "0. No" << endl;
            cin >> opcion;

            if (opcion != 0 && opcion != 1)
            {
                cout << "Ingrese un numero valido" << endl;
            }
            else if (cin.fail())
            {
                cin.clear();
                cin.ignore(1000, '\n');
                opcion = -1;
                cout << "Ingrese un valor valido" << endl;
            }
        } while (opcion != 0 && opcion != 1);

        if (opcion == 1)
        {
            Carta carta = generarCarta();
            cout << "Carta obtenida: [" << carta.valor << ", valor: " << carta.puntos << "]" << endl;
            suma += carta.puntos;
        }
        else if (opcion == 0)
        {
            cout << "Te plantaste con un puntaje de: " << suma << endl;
            break;
        }

        if (suma > 21)
        {
            cout << "PERDISTE!, Te pasaste de 21, tu puntaje fue de: " << suma << endl;
        }
        else if (suma == 21)
        {
            cout << "GANASTE!, obtuviste puntaje exacto";
        }
    }
}