#include <iostream>
#include <cstdlib> // For rand() method
#include <ctime> // To reset the values every moment the program executes
#include <windows.h> //For console commands such as "cls"


using namespace std;

int suma = 0, opcion;


// Struct for the cards
struct Carta
{
    string valor;
    int puntos;
};

//Method to generate the card of the games
Carta generarCarta()
{
    string valores[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    int puntos[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11};

    int i = rand() % 13;

    return {valores[i], puntos[i]};
}

//Main method
void jugarBlackjack()
{
    srand(time(0)); // Resetting every value of the game
    suma = 0;
    int opcion;
    int asesComoOnce = 0;

    cout << "Sacando cartas iniciales....." << endl;
    Sleep(1000); // 

    for (int i = 0; i < 2; i++)
    {
        //Generando las primeras 2 cartas de la partida
        Carta carta = generarCarta();
        cout << "Carta obtenida: [" << carta.valor << ", valor: " << carta.puntos << "]" << endl;
        Sleep(1000);

        suma += carta.puntos; //Actualiza 

        if (carta.valor == "A")
            asesComoOnce++;

        while (suma > 21 && asesComoOnce > 0)
        {
            suma -= 10;
            asesComoOnce--;
        }
    }

    while (suma < 21)
    {
        cout << "PUNTAJE: " << suma << endl;
        cout << "********************************************" << endl;

        do
        {
            cout << "Desea tomar otra carta?" << endl;
            cout << "1. Si" << endl;
            cout << "0. No" << endl;
            cin >> opcion;

            if (cin.fail() || (opcion != 0 && opcion != 1))
            {
                cin.clear();
                cin.ignore(1000, '\n');
                opcion = -1;
                cout << "Ingrese un valor valido (0 o 1)" << endl;
            }

        } while (opcion != 0 && opcion != 1);

        if (opcion == 1)
        {
            Carta carta = generarCarta();
            system("cls");
            cout << "Sacando nueva carta....." << endl;
            Sleep(1000);
            cout << "Carta obtenida: [" << carta.valor << ", valor: " << carta.puntos << "]" << endl;
            Sleep(1000);

            suma += carta.puntos;

            if (carta.valor == "A")
                asesComoOnce++;

            while (suma > 21 && asesComoOnce > 0)
            {
                suma -= 10;
                asesComoOnce--;
            }
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
            cout << "BLACKJACK!, obtuviste puntaje exacto" << endl;
            cout << "PUNTAJE: " << suma << endl;
            break;
        }
    }
}
