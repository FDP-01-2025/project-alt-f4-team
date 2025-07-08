#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <conio.h>

// Main files to run the code
#include "src/card.h"
#include "src/deck.h"
#include "src/blackjack.h"
#include "src/utils.h"
#include "src/poker.h"
#include "src/gofish.h"

using namespace std;

// Function to display the main menu with highlighted selection
void printMenu(int choice)
{
    system("cls"); // Clear screen for fresh menu display
    cout << "*************** WELCOME TO CARDS VS ***************\n\n";

    // Array of menu options
    string options[4] = {
        "1. Poker",
        "2. 21 (Blackjack)",
        "3. Go Fish",
        "4. Salir" // Exit in Spanish
    };

    // Display each option with highlighting for current selection
    for (int i = 0; i < 4; i++)
    {
        if (i == choice)
        {
            cout << " > " << options[i] << " <\n"; // Highlight selected option
        }
        else
        {
            cout << "   " << options[i] << "\n"; // Normal display
        }
    }
}

// Main function - entry point of the program
int main()
{
    int choice = 0;         // Currently selected menu option
    int playerMoney = 1000; // Starting money for betting games

    // Ensure player always starts with money
    if (playerMoney == 0)
    {
        playerMoney = 1000; // Reset to starting amount
    }

    // Main program loop
    while (true)
    {
        printMenu(choice); // Display menu with current selection

        int key = _getch(); // Get key press without waiting for Enter

        // Handle arrow keys (they send two-byte sequences)
        if (key == 224 || key == 0) // Extended key prefix
        {
            int arrow = _getch(); // Get the actual arrow key code

            if (arrow == 72) // Up arrow key
            {
                choice--;
                if (choice < 0)
                    choice = 3; // Wrap to bottom option
            }
            else if (arrow == 80) // Down arrow key (Arrow ↓)
            {
                choice++;
                if (choice > 3)
                    choice = 0; // Wrap to top option
            }
        }
        else if (key == 13) // Enter key pressed
        {
            system("cls"); // Clear screen before starting game

            // Execute selected game or action
            switch (choice)
            {
            case 0: // Poker selected
                playPoker(playerMoney);
                break;

            case 1: // Blackjack selected
                playBlackjack(playerMoney);
                break;

            case 2: // Go Fish selected
                playGoFish();
                break;

            case 3: // Exit selected
                cout << "Thanks for playing CARD VS! See you soon!\n";
                return 0; // Exit program
            }
        }
    }

    return 0; // Should never reach here due to infinite loop
}
