#ifndef POKER_H
#define POKER_H

#include "card.h"
#include "deck.h"
#include "utils.h"
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

const int HAND_SIZE = 5; // Standard poker hand size

// Function to display a poker hand with optional hiding
void showHand(Card hand[HAND_SIZE], bool hide = false)
{
    for (int i = 0; i < HAND_SIZE; i++)
    {
        if (hide)
            cout << "[??] "; // Hide cards (for dramatic effect)
        else
        {
            printCardShort(hand[i]); // Show actual card
            cout << " ";
        }
        Sleep(400); // Add delay for visual effect
    }
    cout << endl;
}

// Function to sort an array of integers (bubble sort)
void sort(int arr[], int n = HAND_SIZE)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]); // Swap if out of order
}

// Function to evaluate a poker hand and return its rank
// Returns: 9=Straight Flush, 8=Four of a Kind, 7=Full House, 6=Flush,
//          5=Straight, 4=Three of a Kind, 3=Two Pair, 2=One Pair, 1=High Card
int evaluateHand(Card hand[HAND_SIZE], string &result)
{
    int counts[15] = {};   // Count of each card value (index 2-14)
    int suits[4] = {};     // Count of each suit (H=0, D=1, C=2, S=3)
    int values[HAND_SIZE]; // Array to store card values for sorting

    // Count card values and suits
    for (int i = 0; i < HAND_SIZE; i++)
    {
        int v = getCardValuePoker(hand[i]);
        values[i] = v;
        counts[v]++; // Increment count for this value

        // Count suits
        switch (hand[i].suit)
        {
        case 'H':
            suits[0]++;
            break; // Hearts
        case 'D':
            suits[1]++;
            break; // Diamonds
        case 'C':
            suits[2]++;
            break; // Clubs
        case 'S':
            suits[3]++;
            break; // Spades
        }
    }

    sort(values); // Sort values to check for straights

    // Check for straight (5 consecutive values)
    bool straight = true;
    for (int i = 1; i < HAND_SIZE; i++)
        if (values[i] != values[i - 1] + 1)
            straight = false;

    // Check for flush (all same suit)
    bool flush = false;
    for (int i = 0; i < 4; i++)
        if (suits[i] == 5)
            flush = true;

    // Evaluate hand combinations (highest to lowest)

    // Straight Flush (straight + flush)
    if (straight && flush)
    {
        result = "Straight Flush";
        return 9;
    }

    // Four of a Kind
    for (int i = 2; i <= 14; i++)
        if (counts[i] == 4)
        {
            result = "Four of a Kind";
            return 8;
        }

    // Check for three of a kind and pairs
    bool three = false, pair = false;
    for (int i = 2; i <= 14; i++)
    {
        if (counts[i] == 3)
            three = true;
        if (counts[i] == 2)
            pair = true;
    }

    // Full House (three of a kind + pair)
    if (three && pair)
    {
        result = "Full House";
        return 7;
    }

    // Flush (all same suit)
    if (flush)
    {
        result = "Flush";
        return 6;
    }

    // Straight (5 consecutive values)
    if (straight)
    {
        result = "Straight";
        return 5;
    }

    // Three of a Kind
    if (three)
    {
        result = "Three of a Kind";
        return 4;
    }

    // Count pairs for Two Pair or One Pair
    int pairs = 0;
    for (int i = 2; i <= 14; i++)
        if (counts[i] == 2)
            pairs++;

    // Two Pair
    if (pairs == 2)
    {
        result = "Two Pair";
        return 3;
    }

    // One Pair
    if (pairs == 1)
    {
        result = "One Pair";
        return 2;
    }

    // High Card (no other combination)
    result = "High Card";
    return 1;
}

// Function for CPU to decide which cards to replace
// Strategy: Keep pairs or better, replace single cards
void cpuChooseCards(Card hand[HAND_SIZE], bool change[HAND_SIZE])
{
    int counts[15] = {};

    // Count occurrences of each card value
    for (int i = 0; i < HAND_SIZE; i++)
        counts[getCardValuePoker(hand[i])]++;

    // Replace cards that appear only once (no pairs)
    for (int i = 0; i < HAND_SIZE; i++)
    {
        int value = getCardValuePoker(hand[i]);
        change[i] = (counts[value] < 2); // Replace if not part of a pair
    }
}

// Function to get the value of the highest pair in a hand
int getHighPairValue(Card hand[HAND_SIZE])
{
    int counts[15] = {};
    for (int i = 0; i < HAND_SIZE; i++)
    {
        counts[getCardValuePoker(hand[i])]++;
    }

    // Find highest value that appears exactly twice
    for (int v = 14; v >= 2; v--)
    {
        if (counts[v] == 2)
            return v;
    }
    return 0; // No pair found
}

// Function to get kicker cards (cards not part of the pair)
void getKickers(Card hand[HAND_SIZE], int pairValue, int kickers[3])
{
    int idx = 0;

    // Collect all cards that aren't part of the pair
    for (int i = 0; i < HAND_SIZE; i++)
    {
        int val = getCardValuePoker(hand[i]);
        if (val != pairValue)
        {
            kickers[idx++] = val;
        }
    }

    // Sort kickers in ascending order
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2 - i; j++)
        {
            if (kickers[j] > kickers[j + 1])
            {
                swap(kickers[j], kickers[j + 1]);
            }
        }
    }
}

// Function to compare two hands with same rank (high card comparison)
int compareHighCard(Card hand1[HAND_SIZE], Card hand2[HAND_SIZE])
{
    int vals1[HAND_SIZE], vals2[HAND_SIZE];

    // Get values for both hands
    for (int i = 0; i < HAND_SIZE; i++)
    {
        vals1[i] = getCardValuePoker(hand1[i]);
        vals2[i] = getCardValuePoker(hand2[i]);
    }

    // Sort both hands
    sort(vals1, HAND_SIZE);
    sort(vals2, HAND_SIZE);

    // Compare from highest to lowest card
    for (int i = HAND_SIZE - 1; i >= 0; i--)
    {
        if (vals1[i] > vals2[i])
            return 1; // Hand 1 wins
        if (vals2[i] > vals1[i])
            return -1; // Hand 2 wins
    }
    return 0; // Tie
}

// Function to get the value of four-of-a-kind
int getFourOfAKindValue(Card hand[HAND_SIZE])
{
    int counts[15] = {};
    for (int i = 0; i < HAND_SIZE; i++)
        counts[getCardValuePoker(hand[i])]++;

    // Find value that appears 4 times
    for (int v = 14; v >= 2; v--)
        if (counts[v] == 4)
            return v;
    return 0;
}

// Function to get the value of three-of-a-kind
int getThreeOfAKindValue(Card hand[HAND_SIZE])
{
    int counts[15] = {};
    for (int i = 0; i < HAND_SIZE; i++)
        counts[getCardValuePoker(hand[i])]++;

    // Find value that appears 3 times
    for (int v = 14; v >= 2; v--)
        if (counts[v] == 3)
            return v;
    return 0;
}

// Function to get pairs in descending order of value
void getPairsDescending(Card hand[HAND_SIZE], int pairs[2], int &countPairs)
{
    countPairs = 0;
    int counts[15] = {};

    // Count card values
    for (int i = 0; i < HAND_SIZE; i++)
        counts[getCardValuePoker(hand[i])]++;

    // Find pairs from highest to lowest value
    for (int v = 14; v >= 2; v--)
    {
        if (counts[v] == 2)
        {
            pairs[countPairs++] = v;
            if (countPairs == 2) // Stop after finding 2 pairs
                break;
        }
    }
}

// Function to get the highest kicker excluding specified values
int getSingleKickerExcluding(Card hand[HAND_SIZE], int excludeVals[], int excludeCount)
{
    int maxVal = 0;

    for (int i = 0; i < HAND_SIZE; i++)
    {
        int val = getCardValuePoker(hand[i]);
        bool excluded = false;

        // Check if this value should be excluded
        for (int j = 0; j < excludeCount; j++)
        {
            if (val == excludeVals[j])
            {
                excluded = true;
                break;
            }
        }

        // Update max if not excluded
        if (!excluded && val > maxVal)
            maxVal = val;
    }
    return maxVal;
}

// Function to break ties between hands of the same rank
// Returns: 1 if hand1 wins, -1 if hand2 wins, 0 if tie
int compareTieBreak(Card hand1[HAND_SIZE], Card hand2[HAND_SIZE], int handRank)
{
    // Straight Flush or Straight - compare highest card
    if (handRank == 9 || handRank == 5)
    {
        int high1 = 0, high2 = 0;
        int vals1[HAND_SIZE], vals2[HAND_SIZE];

        for (int i = 0; i < HAND_SIZE; i++)
        {
            vals1[i] = getCardValuePoker(hand1[i]);
            vals2[i] = getCardValuePoker(hand2[i]);
        }

        sort(vals1, HAND_SIZE);
        sort(vals2, HAND_SIZE);
        high1 = vals1[HAND_SIZE - 1];
        high2 = vals2[HAND_SIZE - 1];

        if (high1 > high2)
            return 1;
        if (high2 > high1)
            return -1;
        return 0;
    }
    // Four of a Kind - compare the four-of-a-kind value, then kicker
    else if (handRank == 8)
    {
        int four1 = getFourOfAKindValue(hand1);
        int four2 = getFourOfAKindValue(hand2);

        if (four1 > four2)
            return 1;
        if (four2 > four1)
            return -1;

        // Compare kickers
        int kicker1 = getSingleKickerExcluding(hand1, &four1, 1);
        int kicker2 = getSingleKickerExcluding(hand2, &four2, 1);

        if (kicker1 > kicker2)
            return 1;
        if (kicker2 > kicker1)
            return -1;
        return 0;
    }
    // Full House - compare three-of-a-kind, then pair
    else if (handRank == 7)
    {
        int three1 = getThreeOfAKindValue(hand1);
        int three2 = getThreeOfAKindValue(hand2);

        if (three1 > three2)
            return 1;
        if (three2 > three1)
            return -1;

        int pair1 = getHighPairValue(hand1);
        int pair2 = getHighPairValue(hand2);

        if (pair1 > pair2)
            return 1;
        if (pair2 > pair1)
            return -1;
        return 0;
    }
    // Flush - compare all cards high to low
    else if (handRank == 6)
    {
        return compareHighCard(hand1, hand2);
    }
    // Three of a Kind - compare three-of-a-kind, then kickers
    else if (handRank == 4)
    {
        int three1 = getThreeOfAKindValue(hand1);
        int three2 = getThreeOfAKindValue(hand2);

        if (three1 > three2)
            return 1;
        if (three2 > three1)
            return -1;

        // Compare kickers
        int kickers1[2], kickers2[2], idx1 = 0, idx2 = 0;

        for (int i = 0; i < HAND_SIZE; i++)
        {
            int val = getCardValuePoker(hand1[i]);
            if (val != three1)
                kickers1[idx1++] = val;

            val = getCardValuePoker(hand2[i]);
            if (val != three2)
                kickers2[idx2++] = val;
        }

        sort(kickers1, 2);
        sort(kickers2, 2);

        // Compare kickers from high to low
        for (int i = 1; i >= 0; i--)
        {
            if (kickers1[i] > kickers2[i])
                return 1;
            if (kickers2[i] > kickers1[i])
                return -1;
        }
        return 0;
    }
    // Two Pair - compare higher pair, lower pair, then kicker
    else if (handRank == 3)
    {
        int pairs1[2], pairs2[2], count1, count2;
        getPairsDescending(hand1, pairs1, count1);
        getPairsDescending(hand2, pairs2, count2);

        // Compare higher pair
        if (pairs1[0] > pairs2[0])
            return 1;
        if (pairs2[0] > pairs1[0])
            return -1;

        // Compare lower pair
        if (pairs1[1] > pairs2[1])
            return 1;
        if (pairs2[1] > pairs1[1])
            return -1;

        // Compare kicker
        int exclude1[2] = {pairs1[0], pairs1[1]};
        int exclude2[2] = {pairs2[0], pairs2[1]};
        int kicker1 = getSingleKickerExcluding(hand1, exclude1, 2);
        int kicker2 = getSingleKickerExcluding(hand2, exclude2, 2);

        if (kicker1 > kicker2)
            return 1;
        if (kicker2 > kicker1)
            return -1;
        return 0;
    }
    // One Pair - compare pair value, then kickers
    else if (handRank == 2)
    {
        int pair1 = getHighPairValue(hand1);
        int pair2 = getHighPairValue(hand2);

        if (pair1 > pair2)
            return 1;
        if (pair2 > pair1)
            return -1;

        // Compare kickers
        int kickers1[3], kickers2[3];
        getKickers(hand1, pair1, kickers1);
        getKickers(hand2, pair2, kickers2);

        // Compare kickers from high to low
        for (int i = 2; i >= 0; i--)
        {
            if (kickers1[i] > kickers2[i])
                return 1;
            if (kickers2[i] > kickers1[i])
                return -1;
        }
        return 0;
    }
    // High Card - compare all cards
    else if (handRank == 1)
    {
        return compareHighCard(hand1, hand2);
    }

    return 0; // Should never reach here
}

// Main poker game function
void playPoker(int &playerMoney)
{
    // Main game loop while player has money
    while (playerMoney > 0)
    {
        clearScreen();
        cout << "========================================\n";
        cout << "            POKER\n";
        cout << "========================================\n";
        cout << "\nYour money: $" << playerMoney << endl;

        // Get player's bet with input validation
        int bet;
        while (true)
        {
            cout << "Enter your bet (0 to quit): $";
            cin >> bet;

            if (cin.fail())
            {
                cout << "Invalid input. Please enter a number.\n";
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }

            if (bet < 0 || bet > playerMoney)
            {
                cout << "Please enter a number between 0 and " << playerMoney << ".\n";
                continue;
            }

            break;
        }
        if (bet == 0)
            break;

        // Create new deck and deal hands
        Deck deck;
        Card player[HAND_SIZE], cpu[HAND_SIZE];

        // Deal 5 cards to each player
        for (int i = 0; i < HAND_SIZE; i++)
        {
            player[i] = deck.dealCard();
            cpu[i] = deck.dealCard();
        }

        clearScreen();
        cout << "\nYour initial hand:\n";
        showHand(player);

        // Player chooses which cards to replace
        bool change[HAND_SIZE] = {};
        cout << "\nEnter card numbers to replace (e.g., 1 3 5), or press Enter to keep all: ";

        // Clear the input buffer first
        cin.ignore();

        string line;
        getline(cin, line);

        // Parse the input to determine which cards to change
        for (int i = 0; i < line.length(); i++)
        {
            char c = line[i];
            if (c >= '1' && c <= '5') // Valid card positions
            {
                change[c - '1'] = true; // Mark card for replacement
            }
        }

        // Replace selected cards for player
        for (int i = 0; i < HAND_SIZE; i++)
        {
            if (change[i])
            {
                player[i] = deck.dealCard();
            }
        }

        // CPU makes its choices automatically
        bool cpuChange[HAND_SIZE] = {};
        cpuChooseCards(cpu, cpuChange);
        for (int i = 0; i < HAND_SIZE; i++)
        {
            if (cpuChange[i])
            {
                cpu[i] = deck.dealCard();
            }
        }

        // Show final hands and evaluate
        clearScreen();
        cout << "\nYour final hand:\n";
        showHand(player);

        string resultPlayer;
        int valPlayer = evaluateHand(player, resultPlayer);
        cout << "Your play: " << resultPlayer << endl;

        Sleep(1000); // Dramatic pause

        cout << "\nCPU's hand:\n";
        showHand(cpu);

        string resultCPU;
        int valCPU = evaluateHand(cpu, resultCPU);
        cout << "CPU's play: " << resultCPU << endl;

        Sleep(800); // Another pause

        // Determine winner and update money
        if (valPlayer > valCPU)
        {
            cout << "\n>>> You win $" << bet << "!\n";
            playerMoney += bet;
        }
        else if (valCPU > valPlayer)
        {
            cout << "\n>>> CPU wins. You lose $" << bet << ".\n";
            playerMoney -= bet;
        }
        else // Same hand rank - use tiebreaker
        {
            int tieResult = compareTieBreak(player, cpu, valPlayer);
            if (tieResult == 1)
            {
                cout << "\n>>> You win by tie-break! $" << bet << "\n";
                playerMoney += bet;
            }
            else if (tieResult == -1)
            {
                cout << "\n>>> CPU wins by tie-break. You lose $" << bet << "\n";
                playerMoney -= bet;
            }
            else
            {
                cout << "\n>>> It's a tie. Bet returned.\n";
            }
        }

        pauseScreen();
        clearScreen();
    }

    // End game message
    if (playerMoney <= 0)
        cout << "You're out of money! Game over.\n";
    else
        cout << "Thanks for playing! You ended with $" << playerMoney << endl;

    pauseScreen();
}

#endif
