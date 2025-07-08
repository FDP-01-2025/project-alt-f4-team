#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

using namespace std;

// Structure representing a playing card
struct Card
{
    string rank; // Card rank (A, 2-10, J, Q, K)
    char suit;   // Card suit (H, D, C, S)
};

// Function to get the full name of a suit from its character
string getSuitName(char suit)
{
    switch (suit)
    {
    case 'H':
        return "Hearts"; // Hearts suit
    case 'D':
        return "Diamonds"; // Diamonds suit
    case 'C':
        return "Clubs"; // Clubs suit
    case 'S':
        return "Spades"; // Spades suit
    default:
        return "Unknown"; // Invalid suit
    }
}

// Function to get the full name of a rank from its string representation
string getRankName(string rank)
{
    if (rank == "A")
        return "Ace"; // Ace
    if (rank == "J")
        return "Jack"; // Jack
    if (rank == "Q")
        return "Queen"; // Queen
    if (rank == "K")
        return "King"; // King
    return rank;       // For numbered cards (2-10), return as is
}

// Function to get card value for Blackjack game
// Aces are worth 11 (adjusted later if needed), face cards are 10
int getCardValueBlackjack(const Card &card)
{
    if (card.rank == "A")
        return 11; // Ace initially worth 11
    if (card.rank == "K" || card.rank == "Q" || card.rank == "J")
        return 10;          // Face cards worth 10
    return stoi(card.rank); // Convert string to int for numbered cards
}

// Function to get card value for Poker game
// Aces are high (14), face cards have specific values
int getCardValuePoker(const Card &card)
{
    if (card.rank == "A")
        return 14; // Ace is high in poker
    if (card.rank == "K")
        return 13; // King
    if (card.rank == "Q")
        return 12; // Queen
    if (card.rank == "J")
        return 11;          // Jack
    return stoi(card.rank); // Convert string to int for numbered cards
}

// Function to print a card in full format (e.g., "Ace of Hearts")
void printCard(const Card &card)
{
    cout << getRankName(card.rank) << " of " << getSuitName(card.suit);
}

// Function to print a card in short format (e.g., "AH")
void printCardShort(const Card &card)
{
    cout << card.rank << card.suit;
}

#endif
