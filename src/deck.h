#ifndef DECK_H
#define DECK_H

#include "card.h"
#include <cstdlib>
#include <ctime>
#include <string>

const int DECK_SIZE = 52; // Standard deck has 52 cards

// Structure representing a deck of playing cards
struct Deck
{
    Card cards[DECK_SIZE]; // Array to hold all 52 cards
    int topCard;           // Index of the next card to be dealt

    // Constructor: automatically initializes and shuffles the deck
    Deck()
    {
        srand(time(0));   // Seed random number generator with current time
        initializeDeck(); // Create all 52 cards
        shuffle();        // Randomize card order
    }

    // Function to create a standard 52-card deck
    void initializeDeck()
    {
        // Array of all possible ranks (2 through Ace)
        std::string ranks[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

        // Array of all four suits
        char suits[4] = {'H', 'D', 'C', 'S'}; // Hearts, Diamonds, Clubs, Spades

        int index = 0;

        // Create cards for each suit
        for (int i = 0; i < 4; i++)
        {
            // Create all ranks for current suit
            for (int j = 0; j < 13; j++)
            {
                cards[index].rank = ranks[j]; // Set card rank
                cards[index].suit = suits[i]; // Set card suit
                index++;
            }
        }

        topCard = 0; // Reset to beginning of deck
    }

    // Function to shuffle the deck using Fisher-Yates algorithm
    void shuffle()
    {
        // Start from the last card and work backwards
        for (int i = DECK_SIZE - 1; i > 0; i--)
        {
            // Pick a random index from 0 to i (inclusive)
            int randIndex = rand() % (i + 1);

            // Swap current card with randomly selected card
            Card temp = cards[i];
            cards[i] = cards[randIndex];
            cards[randIndex] = temp;
        }

        topCard = 0; // Reset to beginning of shuffled deck
    }

    // Function to deal the next card from the deck
    Card dealCard()
    {
        // If we've dealt all cards, reshuffle the deck
        if (topCard >= DECK_SIZE)
        {
            shuffle();
        }

        // Return the next card and increment the index
        return cards[topCard++];
    }

    // Function to check if all cards have been dealt
    bool isEmpty()
    {
        return topCard >= DECK_SIZE;
    }

    // Function to get the number of cards remaining in the deck
    int cardsRemaining()
    {
        return DECK_SIZE - topCard;
    }
};

#endif
