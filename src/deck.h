#ifndef DECK_H
#define DECK_H

#include "card.h"
#include <cstdlib>

const int DECK_SIZE = 52;

struct Deck {
    Card cards[DECK_SIZE];
    int topCard;
    
    Deck() {
        initializeDeck();
    }
    
    void initializeDeck() {
        int index = 0;
        for (int suit = 0; suit < 4; suit++) {
            for (int rank = 1; rank <= 13; rank++) {
                cards[index] = Card(static_cast<Suit>(suit), static_cast<Rank>(rank));
                index++;
            }
        }
        topCard = 0;
    }
    
    void shuffle() {
        for (int i = 0; i < DECK_SIZE; i++) {
            int randomIndex = rand() % DECK_SIZE;
            Card temp = cards[i];
            cards[i] = cards[randomIndex];
            cards[randomIndex] = temp;
        }
        topCard = 0;
    }
    
    Card dealCard() {
        if (topCard >= DECK_SIZE) {
            // Deck is empty, reshuffle
            shuffle();
        }
        return cards[topCard++];
    }
    
    bool isEmpty() {
        return topCard >= DECK_SIZE;
    }
    
    int cardsRemaining() {
        return DECK_SIZE - topCard;
    }
};

#endif
