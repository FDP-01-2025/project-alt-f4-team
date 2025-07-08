#ifndef GOFISH_H
#define GOFISH_H

#include "card.h"
#include "deck.h"
#include "utils.h"
#include <iostream>
#include <cstring>

using namespace std;

// Game constants
const int MAX_CARDS_IN_HAND = 26; // Maximum cards a player can hold
const int INITIAL_HAND_SIZE = 7;  // Starting hand size for each player
const int MAX_PLAYERS = 3;        // Maximum number of players allowed

// Structure representing a Go Fish player
struct GoFishPlayer
{
    Card hand[MAX_CARDS_IN_HAND]; // Player's cards
    int cardCount;                // Number of cards currently held
    int books;                    // Number of books (sets of 4) collected
    char name[20];                // Player's name
};

// Function to initialize a new player with given name
void initializePlayer(GoFishPlayer &player, const char *playerName)
{
    player.cardCount = 0;            // Start with no cards
    player.books = 0;                // Start with no books
    strcpy(player.name, playerName); // Copy player name
}

// Function to add a card to a player's hand
void addCard(GoFishPlayer &player, const Card &card)
{
    if (player.cardCount < MAX_CARDS_IN_HAND)
    {
        player.hand[player.cardCount] = card; // Add card to hand
        player.cardCount++;                   // Increment card count
    }
}

// Function to display a player's hand
void showHand(const GoFishPlayer &player)
{
    cout << player.name << ", your hand: ";
    for (int i = 0; i < player.cardCount; i++)
    {
        printCardShort(player.hand[i]); // Print each card in short format
        cout << " ";
    }
    cout << endl;
}

// Function to count how many cards of a specific rank a player has
int countRank(const GoFishPlayer &player, int rank)
{
    int count = 0;
    for (int i = 0; i < player.cardCount; i++)
    {
        if (getCardValuePoker(player.hand[i]) == rank)
        {
            count++; // Increment if rank matches
        }
    }
    return count;
}

// Function to get simple rank name from numeric value
const char *getRankNameSimple(int rank)
{
    switch (rank)
    {
    case 1:
        return "Ace";
    case 2:
        return "2";
    case 3:
        return "3";
    case 4:
        return "4";
    case 5:
        return "5";
    case 6:
        return "6";
    case 7:
        return "7";
    case 8:
        return "8";
    case 9:
        return "9";
    case 10:
        return "10";
    case 11:
        return "Jack";
    case 12:
        return "Queen";
    case 13:
        return "King";
    case 14:
        return "Ace"; // In case Ace = 14 in poker values
    default:
        return "Unknown";
    }
}

// Function to remove books (sets of 4 cards of same rank) from player's hand
void removeBooks(GoFishPlayer &player)
{
    // Check each possible rank (1-13)
    for (int r = 1; r <= 13; r++)
    {
        int count = countRank(player, r);

        // If player has 4 cards of this rank, form a book
        if (count == 4)
        {
            int newSize = 0;

            // Remove all cards of this rank from hand
            for (int i = 0; i < player.cardCount; i++)
            {
                if (getCardValuePoker(player.hand[i]) != r)
                {
                    player.hand[newSize] = player.hand[i]; // Keep non-matching cards
                    newSize++;
                }
            }

            player.cardCount = newSize; // Update card count
            player.books++;             // Increment book count
            cout << player.name << " formed a book of " << getRankNameSimple(r) << "s!" << endl;
        }
    }
}

// Function to transfer all cards of a specific rank from one player to another
bool transferCards(GoFishPlayer &from, GoFishPlayer &to, int rank)
{
    bool found = false;

    // Go through the 'from' player's hand
    for (int i = 0; i < from.cardCount;)
    {
        if (getCardValuePoker(from.hand[i]) == rank)
        {
            addCard(to, from.hand[i]); // Give card to 'to' player

            // Shift remaining cards down to fill the gap
            for (int j = i; j < from.cardCount - 1; j++)
            {
                from.hand[j] = from.hand[j + 1];
            }

            from.cardCount--; // Decrease 'from' player's card count
            found = true;     // Mark that we found matching cards
        }
        else
        {
            i++; // Only increment if we didn't remove a card
        }
    }

    return found; // Return whether any cards were transferred
}

// Function to show which ranks a player can ask for (ranks they currently have)
void showAvailableRanks(const GoFishPlayer &player)
{
    bool hasRank[15] = {false}; // Track which ranks player has

    // Mark which ranks the player has cards of
    for (int i = 0; i < player.cardCount; i++)
    {
        hasRank[getCardValuePoker(player.hand[i])] = true;
    }

    cout << "Available ranks: ";
    for (int rank = 1; rank <= 13; rank++)
    {
        if (hasRank[rank])
        {
            cout << getRankNameSimple(rank) << " ";
        }
    }
    cout << endl;
}

// Function to handle a single player's turn
void playerTurn(GoFishPlayer &currentPlayer, GoFishPlayer players[], int numPlayers, int currentIndex, Deck &deck)
{
    // If player has no cards and deck isn't empty, give them one card
    if (currentPlayer.cardCount == 0 && deck.cardsRemaining() > 0)
    {
        addCard(currentPlayer, deck.dealCard());
    }

    // If player still has no cards, skip their turn
    if (currentPlayer.cardCount == 0)
        return;

    // Show player's current hand and available ranks
    showHand(currentPlayer);
    showAvailableRanks(currentPlayer);

    int rankChoice;

    // Get valid rank choice from player
    do
    {
        cout << currentPlayer.name << ", what rank do you want to ask for? (1=Ace, 11=Jack, 12=Queen, 13=King): ";
        cin >> rankChoice;

        // Check if input failed (non-integer entered)
        if (cin.fail())
        {
            cout << "Invalid input! Please enter a number." << endl;
            cin.clear();             // Clear the error flag
            cin.ignore(10000, '\n'); // Ignore the rest of the line
            continue;
        }

        // Check if rank is in valid range
        if (rankChoice < 1 || rankChoice > 13)
        {
            cout << "Invalid rank!" << endl;
            continue;
        }

        // Check if player actually has cards of this rank
        if (countRank(currentPlayer, rankChoice) == 0)
        {
            cout << "You don't have cards of that rank!" << endl;
            continue;
        }

        break; // Valid input received
    } while (true);

    bool gotCards = false;

    // Ask each other player for cards of the chosen rank
    for (int i = 0; i < numPlayers; i++)
    {
        if (i != currentIndex)
        { // Don't ask yourself
            if (transferCards(players[i], currentPlayer, rankChoice))
            {
                cout << players[i].name << " gave " << getRankNameSimple(rankChoice)
                     << " cards to " << currentPlayer.name << "." << endl;
                gotCards = true;
            }
        }
    }

    // If no one had the requested cards, "go fish"
    if (!gotCards && deck.cardsRemaining() > 0)
    {
        cout << currentPlayer.name << " goes fishing." << endl;
        addCard(currentPlayer, deck.dealCard());
    }
    else if (!gotCards)
    {
        cout << currentPlayer.name << " wanted to fish but the deck is empty." << endl;
    }

    // Check for and remove any books formed
    removeBooks(currentPlayer);
}

// Function to check if the game is over (someone has 3 or more books)
bool isGameOver(GoFishPlayer players[], int numPlayers)
{
    for (int i = 0; i < numPlayers; i++)
    {
        if (players[i].books >= 3)
        { // Win condition: 3 books
            return true;
        }
    }
    return false;
}

// Function to display final results and determine winner
void showResults(GoFishPlayer players[], int numPlayers)
{
    cout << "\n========================================" << endl;
    cout << "            RESULTS" << endl;
    cout << "========================================" << endl;

    // Show each player's book count
    for (int i = 0; i < numPlayers; i++)
    {
        cout << players[i].name << ": " << players[i].books << " books" << endl;
    }

    // Find the player with the most books
    int maxBooks = -1;
    int winner = -1;

    for (int i = 0; i < numPlayers; i++)
    {
        if (players[i].books > maxBooks)
        {
            maxBooks = players[i].books;
            winner = i;
        }
    }

    cout << endl
         << players[winner].name << " wins the game!" << endl;
}

// Main Go Fish game function
void playGoFish()
{
    clearScreen();
    cout << "========================================" << endl;
    cout << "            GO FISH" << endl;
    cout << "========================================" << endl;
    cout << "NO BET INCLUDED!! JUST HAVE FUN :)" << endl;

    // Get number of players
    int numPlayers = getIntInput("How many players? (2-3): ", 2, 3);

    // Initialize all players
    GoFishPlayer players[MAX_PLAYERS];

    for (int i = 0; i < numPlayers; i++)
    {
        char playerName[20];
        cout << "Name of player " << (i + 1) << ": ";
        cin >> playerName;
        initializePlayer(players[i], playerName);
    }

    // Create and shuffle deck
    Deck deck;
    deck.shuffle();

    // Deal initial hands and check for initial books
    for (int i = 0; i < numPlayers; i++)
    {
        for (int j = 0; j < INITIAL_HAND_SIZE; j++)
        {
            addCard(players[i], deck.dealCard());
        }
        removeBooks(players[i]); // Remove any initial books
    }

    int currentTurn = 0; // Track whose turn it is

    // Main game loop
    while (!isGameOver(players, numPlayers))
    {
        cout << "\n--- " << players[currentTurn].name << "'s turn ---" << endl;

        // Execute current player's turn
        playerTurn(players[currentTurn], players, numPlayers, currentTurn, deck);

        // Move to next player (circular)
        currentTurn = (currentTurn + 1) % numPlayers;

        pauseScreen();
        clearScreen();
    }

    // Show final results
    showResults(players, numPlayers);
    pauseScreen();
}

#endif
