#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "card.h"
#include "deck.h"
#include "utils.h"
#include <iostream>

using namespace std;

const int MAX_HAND_SIZE = 12;

struct BlackjackHand {
    Card cards[MAX_HAND_SIZE];
    int numCards;
    
    BlackjackHand() : numCards(0) {}
    
    void addCard(const Card& card) {
        if (numCards < MAX_HAND_SIZE) {
            cards[numCards++] = card;
        }
    }
    
    int getValue() {
        int value = 0;
        int aces = 0;
        
        for (int i = 0; i < numCards; i++) {
            if (cards[i].rank == ACE) {
                aces++;
                value += 11;
            } else if (cards[i].rank >= JACK) {
                value += 10;
            } else {
                value += cards[i].rank;
            }
        }
        
        // Adjust for aces
        while (value > 21 && aces > 0) {
            value -= 10;
            aces--;
        }
        
        return value;
    }
    
    bool isBusted() {
        return getValue() > 21;
    }
    
    bool isBlackjack() {
        return numCards == 2 && getValue() == 21;
    }
    
    void display(bool hideFirst = false) {
        for (int i = 0; i < numCards; i++) {
            if (i == 0 && hideFirst) {
                cout << "[Hidden] ";
            } else {
                printCardShort(cards[i]);
                cout << " ";
            }
        }
        if (!hideFirst) {
            cout << "(Value: " << getValue() << ")";
        }
        cout << endl;
    }
};

void playBlackjack() {
    clearScreen();
    cout << "========================================\n";
    cout << "            BLACKJACK\n";
    cout << "========================================\n";
    
    Deck deck;
    deck.shuffle();
    
    int playerMoney = 1000;
    
    while (playerMoney > 0) {
        cout << "\nYour money: $" << playerMoney << std::endl;
        
        int bet = getIntInput("Enter your bet (0 to quit): $", 0, playerMoney);
        if (bet == 0) break;
        
        BlackjackHand playerHand;
        BlackjackHand dealerHand;
        
        // Deal initial cards
        playerHand.addCard(deck.dealCard());
        dealerHand.addCard(deck.dealCard());
        playerHand.addCard(deck.dealCard());
        dealerHand.addCard(deck.dealCard());
        
        cout << "\nDealer's hand: ";
        dealerHand.display(true);
        
        cout << "Your hand: ";
        playerHand.display();
        
        // Check for blackjack
        if (playerHand.isBlackjack()) {
            cout << "\nBlackjack! You win!\n";
            playerMoney += bet * 1.5;
            pauseScreen();
            continue;
        }
        
        // Player's turn
        bool playerBusted = false;
        while (!playerHand.isBusted()) {
            if (!askYesNo("Hit?")) break;
            
            playerHand.addCard(deck.dealCard());
            cout << "Your hand: ";
            playerHand.display();
            
            if (playerHand.isBusted()) {
                cout << "Busted! You lose $" << bet << endl;
                playerMoney -= bet;
                playerBusted = true;
                break;
            }
        }
        
        if (!playerBusted) {
            // Dealer's turn
            cout << "\nDealer's hand: ";
            dealerHand.display();
            
            while (dealerHand.getValue() < 17) {
                dealerHand.addCard(deck.dealCard());
                cout << "Dealer hits: ";
                dealerHand.display();
            }
            
            // Determine winner
            int playerValue = playerHand.getValue();
            int dealerValue = dealerHand.getValue();
            
            if (dealerHand.isBusted()) {
                cout << "Dealer busted! You win $" << bet << endl;
                playerMoney += bet;
            } else if (playerValue > dealerValue) {
                cout << "You win $" << bet << endl;
                playerMoney += bet;
            } else if (playerValue < dealerValue) {
                cout << "Dealer wins! You lose $" << bet << endl;
                playerMoney -= bet;
            } else {
                cout << "Push! It's a tie.\n";
            }
        }
        
        pauseScreen();
        clearScreen();
    }
    
    if (playerMoney <= 0) {
        cout << "You're out of money! Game over.\n";
    } else {
        cout << "Thanks for playing! You ended with $" << playerMoney << std::endl;
    }
    
    pauseScreen();
}

#endif
