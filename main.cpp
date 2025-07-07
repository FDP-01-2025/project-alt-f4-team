#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <conio.h>
#include "src/card.h"
#include "src/deck.h"
#include "src/blackjack.h"
#include "src/utils.h"
using namespace std;

// void jugarPoker();
void printMenu(int choice)
{
    system("cls");
    cout << "*************** WELCOME TO CARDS VS ***************\n\n";

    string options[4] = {
        "1. Poker",
        "2. 21 (Blackjack)",
        "3. Vete a Pescar",
        "4. Salir"};

    for (int i = 0; i < 4; i++)
    {
        if (i == choice)
        {
            cout << " > " << options[i] << " <\n";
        }
        else
        {
            cout << "   " << options[i] << "\n";
        }
    }
}

int main()
{
    int choice = 0;
    int playerMoney = 1000;

    if(playerMoney == 0){
        playerMoney = 1000;
    }
    while (true)
    {
        printMenu(choice);

        int tecla = _getch();

        if (tecla == 224 || tecla == 0)
        {
            int flecha = _getch();

            if (flecha == 72)
            {
                choice--;
                if (choice < 0)
                    choice = 3;
            }
            else if (flecha == 80)
            { // Flecha ↓
                choice++;
                if (choice > 3)
                    choice = 0;
            }
        }
        else if (tecla == 13)
        { // Enter
            system("cls");

            switch (choice)
            {
            case 0:
                // jugarPoker();
                break;
            case 1:
                playBlackjack(playerMoney);
                break;
            case 2:
                cout << "Has seleccionado Vete a Pescar.\n";
                system("pause");
                break;
            case 3:
                cout << "Gracias por jugar en CARDS. ¡Hasta pronto!\n";
                return 0;
            }
        }
    }

    return 0;
}