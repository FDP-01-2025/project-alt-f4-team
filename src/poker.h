#ifndef POKER_H
#define POKER_H

#include "card.h"
#include "deck.h"
#include "utils.h"
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

const int HAND_SIZE = 5;

void showHand(Card hand[HAND_SIZE], bool hide = false)
{
    for (int i = 0; i < HAND_SIZE; i++)
    {
        if (hide)
            cout << "[??] ";
        else
        {
            printCardShort(hand[i]);
            cout << " ";
        }
        Sleep(400);
    }
    cout << endl;
}

void sort(int arr[], int n = HAND_SIZE)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

int evaluateHand(Card hand[HAND_SIZE], string &result)
{
    int counts[15] = {};
    int suits[4] = {};
    int values[HAND_SIZE];

    for (int i = 0; i < HAND_SIZE; i++)
    {
        int v = getCardValuePoker(hand[i]);
        values[i] = v;
        counts[v]++;
        switch (hand[i].suit)
        {
        case 'H':
            suits[0]++;
            break;
        case 'D':
            suits[1]++;
            break;
        case 'C':
            suits[2]++;
            break;
        case 'S':
            suits[3]++;
            break;
        }
    }

    sort(values);
    bool straight = true;
    for (int i = 1; i < HAND_SIZE; i++)
        if (values[i] != values[i - 1] + 1)
            straight = false;

    bool flush = false;
    for (int i = 0; i < 4; i++)
        if (suits[i] == 5)
            flush = true;

    if (straight && flush)
    {
        result = "Straight Flush";
        return 9;
    }
    for (int i = 2; i <= 14; i++)
        if (counts[i] == 4)
        {
            result = "Four of a Kind";
            return 8;
        }

    bool three = false, pair = false;
    for (int i = 2; i <= 14; i++)
    {
        if (counts[i] == 3)
            three = true;
        if (counts[i] == 2)
            pair = true;
    }
    if (three && pair)
    {
        result = "Full House";
        return 7;
    }
    if (flush)
    {
        result = "Flush";
        return 6;
    }
    if (straight)
    {
        result = "Straight";
        return 5;
    }
    if (three)
    {
        result = "Three of a Kind";
        return 4;
    }

    int pairs = 0;
    for (int i = 2; i <= 14; i++)
        if (counts[i] == 2)
            pairs++;

    if (pairs == 2)
    {
        result = "Two Pair";
        return 3;
    }
    if (pairs == 1)
    {
        result = "One Pair";
        return 2;
    }

    result = "High Card";
    return 1;
}

void cpuChooseCards(Card hand[HAND_SIZE], bool change[HAND_SIZE])
{
    int counts[15] = {};
    for (int i = 0; i < HAND_SIZE; i++)
        counts[getCardValuePoker(hand[i])]++;

    for (int i = 0; i < HAND_SIZE; i++)
    {
        int value = getCardValuePoker(hand[i]);
        change[i] = (counts[value] < 2);
    }
}

int getHighPairValue(Card hand[HAND_SIZE])
{
    int counts[15] = {};
    for (int i = 0; i < HAND_SIZE; i++)
    {
        counts[getCardValuePoker(hand[i])]++;
    }
    for (int v = 14; v >= 2; v--)
    {
        if (counts[v] == 2)
            return v;
    }
    return 0;
}

void getKickers(Card hand[HAND_SIZE], int pairValue, int kickers[3])
{
    int idx = 0;
    for (int i = 0; i < HAND_SIZE; i++)
    {
        int val = getCardValuePoker(hand[i]);
        if (val != pairValue)
        {
            kickers[idx++] = val;
        }
    }
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

int compareHighCard(Card hand1[HAND_SIZE], Card hand2[HAND_SIZE])
{
    int vals1[HAND_SIZE], vals2[HAND_SIZE];
    for (int i = 0; i < HAND_SIZE; i++)
    {
        vals1[i] = getCardValuePoker(hand1[i]);
        vals2[i] = getCardValuePoker(hand2[i]);
    }

    sort(vals1, HAND_SIZE);
    sort(vals2, HAND_SIZE);

    for (int i = HAND_SIZE - 1; i >= 0; i--)
    {
        if (vals1[i] > vals2[i])
            return 1;
        if (vals2[i] > vals1[i])
            return -1;
    }
    return 0;
}

int getFourOfAKindValue(Card hand[HAND_SIZE])
{
    int counts[15] = {};
    for (int i = 0; i < HAND_SIZE; i++)
        counts[getCardValuePoker(hand[i])]++;
    for (int v = 14; v >= 2; v--)
        if (counts[v] == 4)
            return v;
    return 0;
}

int getThreeOfAKindValue(Card hand[HAND_SIZE])
{
    int counts[15] = {};
    for (int i = 0; i < HAND_SIZE; i++)
        counts[getCardValuePoker(hand[i])]++;
    for (int v = 14; v >= 2; v--)
        if (counts[v] == 3)
            return v;
    return 0;
}

void getPairsDescending(Card hand[HAND_SIZE], int pairs[2], int &countPairs)
{
    countPairs = 0;
    int counts[15] = {};
    for (int i = 0; i < HAND_SIZE; i++)
        counts[getCardValuePoker(hand[i])]++;

    for (int v = 14; v >= 2; v--)
    {
        if (counts[v] == 2)
        {
            pairs[countPairs++] = v;
            if (countPairs == 2)
                break;
        }
    }
}

int getSingleKickerExcluding(Card hand[HAND_SIZE], int excludeVals[], int excludeCount)
{
    int maxVal = 0;
    for (int i = 0; i < HAND_SIZE; i++)
    {
        int val = getCardValuePoker(hand[i]);
        bool excluded = false;
        for (int j = 0; j < excludeCount; j++)
        {
            if (val == excludeVals[j])
            {
                excluded = true;
                break;
            }
        }
        if (!excluded && val > maxVal)
            maxVal = val;
    }
    return maxVal;
}

int compareTieBreak(Card hand1[HAND_SIZE], Card hand2[HAND_SIZE], int handRank)
{
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
    else if (handRank == 8)
    {
        int four1 = getFourOfAKindValue(hand1);
        int four2 = getFourOfAKindValue(hand2);
        if (four1 > four2)
            return 1;
        if (four2 > four1)
            return -1;

        int kicker1 = getSingleKickerExcluding(hand1, &four1, 1);
        int kicker2 = getSingleKickerExcluding(hand2, &four2, 1);
        if (kicker1 > kicker2)
            return 1;
        if (kicker2 > kicker1)
            return -1;
        return 0;
    }
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
    else if (handRank == 6)
    {
        return compareHighCard(hand1, hand2);
    }
    else if (handRank == 4)
    {
        int three1 = getThreeOfAKindValue(hand1);
        int three2 = getThreeOfAKindValue(hand2);
        if (three1 > three2)
            return 1;
        if (three2 > three1)
            return -1;

        int exclude1[1] = {three1};
        int exclude2[1] = {three2};

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

        for (int i = 1; i >= 0; i--)
        {
            if (kickers1[i] > kickers2[i])
                return 1;
            if (kickers2[i] > kickers1[i])
                return -1;
        }
        return 0;
    }
    else if (handRank == 3)
    {
        int pairs1[2], pairs2[2], count1, count2;
        getPairsDescending(hand1, pairs1, count1);
        getPairsDescending(hand2, pairs2, count2);

        if (pairs1[0] > pairs2[0])
            return 1;
        if (pairs2[0] > pairs1[0])
            return -1;

        if (pairs1[1] > pairs2[1])
            return 1;
        if (pairs2[1] > pairs1[1])
            return -1;
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
    else if (handRank == 2)
    {
        int pair1 = getHighPairValue(hand1);
        int pair2 = getHighPairValue(hand2);
        if (pair1 > pair2)
            return 1;
        if (pair2 > pair1)
            return -1;

        int kickers1[3], kickers2[3];
        getKickers(hand1, pair1, kickers1);
        getKickers(hand2, pair2, kickers2);

        for (int i = 2; i >= 0; i--)
        {
            if (kickers1[i] > kickers2[i])
                return 1;
            if (kickers2[i] > kickers1[i])
                return -1;
        }
        return 0;
    }
    else if (handRank == 1)
    {
        return compareHighCard(hand1, hand2);
    }

    return 0;
}

void playPoker(int &playerMoney)
{
    while (playerMoney > 0)
    {
        clearScreen();
        cout << "========================================\n";
        cout << "            POKER\n";
        cout << "========================================\n";
        cout << "\nYour money: $" << playerMoney << endl;
        int bet = getIntInput("Enter your bet (0 to quit): $", 0, playerMoney);
        if (bet == 0)
            break;

        Deck deck;
        Card player[HAND_SIZE], cpu[HAND_SIZE];
        for (int i = 0; i < HAND_SIZE; i++)
        {
            player[i] = deck.dealCard();
            cpu[i] = deck.dealCard();
        }

        clearScreen();
        cout << "\nYour initial hand:\n";
        showHand(player);

        bool change[HAND_SIZE] = {};
        cout << "\nEnter card numbers to replace (e.g., 2 4), or 0 to keep all: ";
        string line;
        getline(cin, line);

        for (char c : line)
            if (c >= '1' && c <= '5')
                change[c - '1'] = true;

        for (int i = 0; i < HAND_SIZE; i++)
            if (change[i])
                player[i] = deck.dealCard();

        bool cpuChange[HAND_SIZE] = {};
        cpuChooseCards(cpu, cpuChange);
        for (int i = 0; i < HAND_SIZE; i++)
            if (cpuChange[i])
                cpu[i] = deck.dealCard();

        clearScreen();
        cout << "\nYour final hand:\n";
        showHand(player);
        string resultPlayer;
        int valPlayer = evaluateHand(player, resultPlayer);
        cout << "Your play: " << resultPlayer << endl;

        Sleep(1000);
        cout << "\nCPU's hand:\n";
        showHand(cpu);
        string resultCPU;
        int valCPU = evaluateHand(cpu, resultCPU);
        cout << "CPU's play: " << resultCPU << endl;

        Sleep(800);
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
        else
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

    if (playerMoney <= 0)
        cout << "You're out of money! Game over.\n";
    else
        cout << "Thanks for playing! You ended with $" << playerMoney << endl;

    pauseScreen();
}

#endif
