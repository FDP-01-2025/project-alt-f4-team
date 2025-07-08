#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "card.h"
#include "deck.h"
#include "utils.h"
#include <iostream>
#include <windows.h>

using namespace std;

const int MAX_HAND_SIZE = 12;

// Structure representing a blackjack hand
struct BlackjackHand
{
    Card cards[MAX_HAND_SIZE]; // Array of cards in the hand
    int numCards;              // Current number of cards

    // Resets the hand to 0 cards
    void reset()
    {
        numCards = 0;
    }

    // Adds a card to the hand if there's space
    void addCard(const Card &card)
    {
        if (numCards < MAX_HAND_SIZE)
        {
            cards[numCards++] = card;
        }
    }

    // Calculates the total value of the hand considering aces
    int getValue()
    {
        int value = 0;
        int aces = 0;

        // Sum the value of all cards and count aces
        for (int i = 0; i < numCards; i++)
        {
            int cardVal = getCardValueBlackjack(cards[i]);
            if (cards[i].rank == "A")
                aces++;
            value += cardVal;
        }

        // Adjust ace values if necessary (11 -> 1)
        while (value > 21 && aces > 0)
        {
            value -= 10;
            aces--;
        }

        return value;
    }

    // Checks if the hand is busted (over 21)
    bool isBusted()
    {
        return getValue() > 21;
    }

    // Checks if it's blackjack (21 with 2 cards)
    bool isBlackjack()
    {
        return numCards == 2 && getValue() == 21;
    }

    // Displays the cards in the hand
    void display(bool hideFirst = false)
    {
        for (int i = 0; i < numCards; i++)
        {
            // Hide the first card if hideFirst is true (for dealer)
            if (i == 0 && hideFirst)
            {
                cout << "[Hidden] ";
            }
            else
            {
                printCardShort(cards[i]);
                cout << " ";
            }
        }
        // Show total value if not hidden
        if (!hideFirst)
        {
            cout << "(Value: " << getValue() << ")";
        }
        cout << endl;
    }
};

// Function to validate integer input within a specific range
int getValidatedIntSimple(const string &prompt, int min, int max)
{
    int value;
    while (true)
    {
        cout << prompt;
        cin >> value;

        // Check if input failed (not a number)
        if (cin.fail())
        {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();            // Clear error flag
            cin.ignore(1000, '\n'); // Ignore invalid characters
            continue;
        }

        // Check if it's within valid range
        if (value < min || value > max)
        {
            cout << "Please enter a number between " << min << " and " << max << ".\n";
            cin.ignore(1000, '\n'); // Clear buffer
            continue;
        }

        cin.ignore(1000, '\n'); // Clear buffer before returning
        return value;
    }
}

// Function to ask for yes/no response with validation
bool askYesNoValidated(const string &prompt)
{
    string input;
    while (true)
    {
        cout << prompt << " (y/n): ";
        getline(cin, input);

        // Accept 'y' or 'Y' as yes
        if (input == "y" || input == "Y")
            return true;
        // Accept 'n' or 'N' as no
        if (input == "n" || input == "N")
            return false;

        cout << "Invalid input. Please enter 'y' or 'n'.\n";
    }
}

// Main blackjack game function
void playBlackjack(int &playerMoney)
{
    clearScreen();
    cout << "========================================\n";
    cout << "            BLACKJACK\n";
    cout << "========================================\n";

    // Initialize and shuffle the deck
    Deck deck;
    deck.initializeDeck();
    deck.shuffle();

    // Main game loop while player has money
    while (playerMoney > 0)
    {
        cout << "\nYour money: $" << playerMoney << endl;

        // Ask for player's bet
        int bet = getValidatedIntSimple("Enter your bet (0 to quit): $", 0, playerMoney);
        if (bet == 0)
            break;

        // Initialize player and dealer hands
        BlackjackHand playerHand;
        BlackjackHand dealerHand;

        playerHand.reset();
        dealerHand.reset();

        // Deal initial cards (2 for each)
        playerHand.addCard(deck.dealCard());
        Sleep(1000);
        dealerHand.addCard(deck.dealCard());
        Sleep(1000);
        playerHand.addCard(deck.dealCard());
        Sleep(1000);
        dealerHand.addCard(deck.dealCard());
        Sleep(1000);

        // Show initial hands
        cout << "\nDealer's hand: ";
        dealerHand.display(true); // Hide dealer's first card

        cout << "Your hand: ";
        playerHand.display();

        // Check if player has blackjack
        if (playerHand.isBlackjack())
        {
            cout << "\nBlackjack! You win!\n";
            playerMoney += bet * 1.5; // Blackjack payout (1.5:1)
            pauseScreen();
            continue;
        }

        // Player's turn
        bool playerBusted = false;
        while (!playerHand.isBusted())
        {
            // Ask if player wants another card
            if (!askYesNoValidated("Hit?"))
                break;

            // Add card and show updated hand
            playerHand.addCard(deck.dealCard());
            Sleep(1000);
            cout << "Your hand: ";
            playerHand.display();

            // Check if player busted
            if (playerHand.isBusted())
            {
                cout << "Busted! You lose $" << bet << endl;
                playerMoney -= bet;
                playerBusted = true;
                break;
            }
        }

        // If player didn't bust, dealer plays
        if (!playerBusted)
        {
            cout << "\nDealer's hand: ";
            dealerHand.display(); // Show all dealer cards

            // Dealer must hit until reaching 17 or higher
            while (dealerHand.getValue() < 17)
            {
                dealerHand.addCard(deck.dealCard());
                Sleep(1000);
                cout << "Dealer hits: ";
                dealerHand.display();
                cout << "Dealer hand value: " << dealerHand.getValue() << endl;
            }

            // Get final values
            int playerValue = playerHand.getValue();
            int dealerValue = dealerHand.getValue();

            cout << "Player final value: " << playerValue << endl;
            cout << "Dealer final value: " << dealerValue << endl;

            // Determine winner
            if (dealerHand.isBusted())
            {
                cout << "Dealer busted! You win $" << bet << endl;
                playerMoney += bet;
            }
            else if (playerHand.isBlackjack() && !dealerHand.isBlackjack())
            {
                cout << "You had Blackjack! You win $" << bet * 1.5 << endl;
                playerMoney += bet * 1.5;
            }
            else if (!playerHand.isBlackjack() && dealerHand.isBlackjack())
            {
                cout << "Dealer had Blackjack! You lose $" << bet << endl;
                playerMoney -= bet;
            }
            else
            {
                // Compare normal values
                if (playerValue > dealerValue)
                {
                    cout << "You win $" << bet << "!\n";
                    playerMoney += bet;
                }
                else if (playerValue < dealerValue)
                {
                    cout << "You lose $" << bet << "!\n";
                    playerMoney -= bet;
                }
                else
                {
                    cout << "Push! It's a tie.\n";
                }
            }
        }

        pauseScreen();
        clearScreen();
    }

    // End game message
    if (playerMoney <= 0)
    {
        cout << "You're out of money! Game over.\n";
    }
    else
    {
        cout << "Thanks for playing! You ended with $" << playerMoney << endl;
    }

    pauseScreen();
}

#endif
