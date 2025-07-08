#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <cstdlib>

using namespace std;

// Function to clear the console screen
// Works on both Windows and Unix-based systems (Linux/Mac)
void clearScreen()
{
#ifdef _WIN32
    system("cls"); // Windows command to clear screen
#else
    system("clear"); // Unix/Linux command to clear screen
#endif
}

// Function to pause execution and wait for user input
// Useful for keeping results visible before continuing
void pauseScreen()
{
    cout << "\nPress Enter to continue...";
    cin.ignore(); // Clear any leftover input from buffer
    cin.get();    // Wait for Enter key press
}

// Function to ask a yes/no question and return boolean result
// Returns true for 'y' or 'Y', false for 'n' or 'N'
bool askYesNo(const string &question)
{
    char answer;
    cout << question << " (y/n): ";
    cin >> answer;
    return (answer == 'y' || answer == 'Y'); // Case-insensitive yes check
}

// Function to get validated integer input within a specified range
int getIntInput(const string &prompt, int min, int max)
{
    int input;

    do
    {
        cout << prompt;
        cin >> input;

        // Check if input failed (non-integer entered)
        if (cin.fail())
        {
            cout << "Invalid input! Please enter a number." << endl;
            cin.clear();             // Clear the error flag
            cin.ignore(10000, '\n'); // Ignore the rest of the line up to newline
            continue;                // Skip range check and try again
        }

        // Check if input is within valid range
        if (input < min || input > max)
        {
            cout << "Please enter a number between " << min << " and " << max << "." << endl;
        }

    } while (cin.fail() || input < min || input > max); // Continue until valid input

    return input; // Return the validated input
}

#endif
