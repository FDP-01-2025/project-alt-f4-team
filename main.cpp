#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int opcion = 0;

    while (opcion != 4)
    {
        cout << "\n*************** BIENVENIDO A UCA CARDS ***************" << endl;
        cout << "1. Poker" << endl;
        cout << "2. 21 (Blackjack)" << endl;
        cout << "3. Vete a Pescar" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cout << "Has seleccionado Poker." << endl;
            break;
        case 2:
            cout << "Has seleccionado Blackjack." << endl;
            jugarBlackjack();
            break;
        case 3:
            cout << "Has seleccionado Vete a Pescar. (Aquí iría el código del juego)" << endl;
            break;
        case 4:
            cout << "Gracias por jugar en UCA CARDS. ¡Hasta pronto!" << endl;
            break;
        default:
            cout << "Opcion no valida. Por favor seleccione una opcion del 1 al 4." << endl;
            break;
        }
    }

    return 0;
}

void jugarBlackjack()
{
    //Valores de las cartas para juego de blackjack
    string nombres[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    int valores[] = {11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};
    const int totalCartas = 13;

    int indiceCarta = rand() % totalCartas;
    string nombre = nombres[indiceCarta];
    int valor = valores[indiceCarta];

    
}
