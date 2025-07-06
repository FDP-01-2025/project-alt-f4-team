#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <cstdlib>

using namespace std;

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pauseScreen() {
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}

bool askYesNo(const string& question) {
    char answer;
    cout << question << " (y/n): ";
    cin >> answer;
    return (answer == 'y' || answer == 'Y');
}

int getIntInput(const string& prompt, int min, int max) {
    int input;
    do {
        cout << prompt;
        cin >> input;
        if (input < min || input > max) {
            cout << "Please enter a number between " << min << " and " << max << ".\n";
        }
    } while (input < min || input > max);
    return input;
}

#endif
