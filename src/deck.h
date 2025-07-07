#ifndef DECK_H
#define DECK_H

#include "card.h"
#include <cstdlib>
#include <ctime>
#include <string>

const int DECK_SIZE = 52;

struct Deck
{
    Card cards[DECK_SIZE];
    int topCard;

    Deck()
    {
        srand(time(0)); 
        initializeDeck();
        shuffle();
    }

    void initializeDeck()
    {
        std::string ranks[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
        char suits[4] = {'H', 'D', 'C', 'S'};

        int index = 0;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 13; j++)
            {
                cards[index].rank = ranks[j];
                cards[index].suit = suits[i];
                index++;
            }
        }
        topCard = 0;
    }

    void shuffle()
    {
        for (int i = DECK_SIZE - 1; i > 0; i--)
        {
            int randIndex = rand() % (i + 1);
            Card temp = cards[i];
            cards[i] = cards[randIndex];
            cards[randIndex] = temp;
        }
        topCard = 0;
    }

    Card dealCard()
    {
        if (topCard >= DECK_SIZE)
        {
            shuffle();
        }
        return cards[topCard++];
    }

    bool isEmpty()
    {
        return topCard >= DECK_SIZE;
    }

    int cardsRemaining()
    {
        return DECK_SIZE - topCard;
    }
};

#endif
