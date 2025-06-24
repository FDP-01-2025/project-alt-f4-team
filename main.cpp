#include <iostream>
#include <cstdlib>
#include <ctime>

void jugarBlackjack();

using namespace std;

int main()
{
    int opcion = 0;
    float saldo = 0;

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
