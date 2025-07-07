#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "card.h"
#include "deck.h"
#include "utils.h"
#include <iostream>
#include <windows.h>
using namespace std;

const int MAX_HAND_SIZE = 12;

struct BlackjackHand
{
    Card cards[MAX_HAND_SIZE];
    int numCards;

    void reset()
    {
        numCards = 0;
    }

    void addCard(const Card &card)
    {
        if (numCards < MAX_HAND_SIZE)
        {
            cards[numCards++] = card;
        }
    }

    int getValue()
    {
        int value = 0;
        int aces = 0;

        for (int i = 0; i < numCards; i++)
        {
            int cardVal = getCardValueBlackjack(cards[i]);
            if (cards[i].rank == "A")
                aces++;
            value += cardVal;
        }

        while (value > 21 && aces > 0)
        {
            value -= 10;
            aces--;
        }

        return value;
    }

    bool isBusted()
    {
        return getValue() > 21;
    }

    bool isBlackjack()
    {
        return numCards == 2 && getValue() == 21;
    }

    void display(bool hideFirst = false)
    {
        for (int i = 0; i < numCards; i++)
        {
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
        if (!hideFirst)
        {
            cout << "(Value: " << getValue() << ")";
        }
        cout << endl;
    }
};

void playBlackjack(int &playerMoney)
{
    clearScreen();
    cout << "========================================\n";
    cout << "            BLACKJACK\n";
    cout << "========================================\n";

    Deck deck;
    deck.initializeDeck();
    deck.shuffle();

    while (playerMoney > 0)
    {
        cout << "\nYour money: $" << playerMoney << endl;

        int bet = getIntInput("Enter your bet (0 to quit): $", 0, playerMoney);
        if (bet == 0)
            break;

        BlackjackHand playerHand;
        BlackjackHand dealerHand;
        playerHand.reset();
        dealerHand.reset();

        playerHand.addCard(deck.dealCard());
        Sleep(1000);

        dealerHand.addCard(deck.dealCard());
        Sleep(1000);

        playerHand.addCard(deck.dealCard());
        Sleep(1000);

        dealerHand.addCard(deck.dealCard());
        Sleep(1000);

        cout << "\nDealer's hand: ";
        dealerHand.display(true);

        cout << "Your hand: ";
        playerHand.display();

        if (playerHand.isBlackjack())
        {
            cout << "\nBlackjack! You win!\n";
            playerMoney += bet * 1.5;
            pauseScreen();
            continue;
        }

        bool playerBusted = false;
        while (!playerHand.isBusted())
        {
            if (!askYesNo("Hit?"))
                break;

            playerHand.addCard(deck.dealCard());
            Sleep(1000);

            cout << "Your hand: ";
            playerHand.display();

            if (playerHand.isBusted())
            {
                cout << "Busted! You lose $" << bet << endl;
                playerMoney -= bet;
                playerBusted = true;
                break;
            }
        }

        if (!playerBusted)
        {
            cout << "\nDealer's hand: ";
            dealerHand.display();

            while (dealerHand.getValue() < 17)
            {
                dealerHand.addCard(deck.dealCard());
                Sleep(1000);

                cout << "Dealer hits: ";
                dealerHand.display();
                cout << "Dealer hand value: " << dealerHand.getValue() << endl; // debug
            }

            int playerValue = playerHand.getValue();
            int dealerValue = dealerHand.getValue();

            cout << "Player final value: " << playerValue << endl; // debug
            cout << "Dealer final value: " << dealerValue << endl; // debug

            if (dealerHand.isBusted())
            {
                cout << "Dealer busted! You win $" << bet << endl;
                playerMoney += bet;
            }
            else if (playerHand.isBlackjack() && !dealerHand.isBlackjack())
            {
                cout << "You had Blackjack! You win $" << bet << endl;
                playerMoney += bet * 1.5;
            }
            else if (!playerHand.isBlackjack() && dealerHand.isBlackjack())
            {
                cout << "Dealer had Blackjack! You lose $" << bet << endl;
                playerMoney -= bet;
            }
            else
            {
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
