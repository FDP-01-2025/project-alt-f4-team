#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

using namespace std;

struct Card {
    string rank;  
    char suit;    
};

string getSuitName(char suit) {
    switch (suit) {
        case 'H': return "Hearts";
        case 'D': return "Diamonds";
        case 'C': return "Clubs";
        case 'S': return "Spades";
        default: return "Unknown";
    }
}

string getRankName(string rank) {
    if (rank == "A") return "Ace";
    if (rank == "J") return "Jack";
    if (rank == "Q") return "Queen";
    if (rank == "K") return "King";
    return rank;  
}

int getCardValueBlackjack(const Card &card) {
    if (card.rank == "A") return 11;
    if (card.rank == "K" || card.rank == "Q" || card.rank == "J") return 10;
    return stoi(card.rank);
}

int getCardValuePoker(const Card &card) {
    if (card.rank == "A") return 14;
    if (card.rank == "K") return 13;
    if (card.rank == "Q") return 12;
    if (card.rank == "J") return 11;
    return stoi(card.rank);
}

void printCard(const Card &card) {
    cout << getRankName(card.rank) << " of " << getSuitName(card.suit);
}

void printCardShort(const Card &card) {
    cout << card.rank << card.suit;
}

#endif
