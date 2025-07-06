#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

enum Suit {
    HEARTS = 0,
    DIAMONDS = 1,
    CLUBS = 2,
    SPADES = 3
};

enum Rank {
    ACE = 1,
    TWO = 2,
    THREE = 3,
    FOUR = 4,
    FIVE = 5,
    SIX = 6,
    SEVEN = 7,
    EIGHT = 8,
    NINE = 9,
    TEN = 10,
    JACK = 11,
    QUEEN = 12,
    KING = 13
};

struct Card {
    Suit suit;
    Rank rank;
    
    Card() : suit(HEARTS), rank(ACE) {}
    Card(Suit s, Rank r) : suit(s), rank(r) {}
};

std::string getSuitName(Suit suit) {
    switch (suit) {
        case HEARTS: return "Hearts";
        case DIAMONDS: return "Diamonds";
        case CLUBS: return "Clubs";
        case SPADES: return "Spades";
        default: return "Unknown";
    }
}

std::string getRankName(Rank rank) {
    switch (rank) {
        case ACE: return "Ace";
        case TWO: return "2";
        case THREE: return "3";
        case FOUR: return "4";
        case FIVE: return "5";
        case SIX: return "6";
        case SEVEN: return "7";
        case EIGHT: return "8";
        case NINE: return "9";
        case TEN: return "10";
        case JACK: return "Jack";
        case QUEEN: return "Queen";
        case KING: return "King";
        default: return "Unknown";
    }
}

char getSuitSymbol(Suit suit) {
    switch (suit) {
        case HEARTS: return 'H';
        case DIAMONDS: return 'D';
        case CLUBS: return 'C';
        case SPADES: return 'S';
        default: return '?';
    }
}

void printCard(const Card& card) {
    std::cout << getRankName(card.rank) << " of " << getSuitName(card.suit);
}

void printCardShort(const Card& card) {
    if (card.rank == 10) {
        std::cout << "10" << getSuitSymbol(card.suit);
    } else {
        std::cout << getRankName(card.rank)[0] << getSuitSymbol(card.suit);
    }
}

int getCardValue(const Card& card) {
    if (card.rank >= JACK) {
        return 10;
    }
    return card.rank;
}

int getCardValueAceHigh(const Card& card) {
    if (card.rank == ACE) {
        return 14;
    }
    return card.rank;
}

#endif
