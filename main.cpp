#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>  
#include <conio.h>
using namespace std;

void jugarBlackjack();
void jugarPoker();
void imprimirMenu(int seleccion) {
    system("cls");
    cout << "*************** BIENVENIDO A UCA CARDS ***************\n\n";

    string opciones[4] = {
        "1. Poker",
        "2. 21 (Blackjack)",
        "3. Vete a Pescar",
        "4. Salir"
    };

    for (int i = 0; i < 4; i++) {
        if (i == seleccion) {
            cout << " > " << opciones[i] << " <\n";
        } else {
            cout << "   " << opciones[i] << "\n";
        }
    }
}

int main() {
    int seleccion = 0; 

    while (true) {
        imprimirMenu(seleccion);  

        int tecla = _getch();     

        if (tecla == 224 || tecla == 0) {  
            int flecha = _getch();        

            if (flecha == 72) {            
                seleccion--;
                if (seleccion < 0) seleccion = 3;
            } else if (flecha == 80) {     // Flecha ↓
                seleccion++;
                if (seleccion > 3) seleccion = 0;
            }
        } else if (tecla == 13) {  // Enter
            system("cls");

            switch (seleccion) {
                case 0:
                    jugarPoker();
                    break;
                case 1:
                    jugarBlackjack();
                    break;
                case 2:
                    cout << "Has seleccionado Vete a Pescar.\n";
                    system("pause");
                    break;
                case 3:
                    cout << "Gracias por jugar en UCA CARDS. ¡Hasta pronto!\n";
                    return 0;
            }
        }
    }

    return 0;
}