/*
Paula Harris
CS-210: Programming Languages
Project: Chada Tech Clock
Date: December 24, 2025
*/

#include <iostream>
#include <limits>
#include "Clock.h"

using std::cin;
using std::cout;
using std::string;

void displayClock(const Clock &clock)
{
    const string t12 = clock.getTime12();
    const string t24 = clock.getTime24();

    cout << "\n";
    cout << "**************************    **************************\n";
    cout << "*      12-Hour Clock     *    *      24-Hour Clock     *\n";
    cout << "*      " << t12 << "      *    *        " << t24 << "        *\n";
    cout << "**************************    **************************\n";
}

void displayMenu()
{
    cout << "\n**************************\n";
    cout << "* 1 - Add One Hour       *\n";
    cout << "* 2 - Add One Minute     *\n";
    cout << "* 3 - Add One Second     *\n";
    cout << "* 4 - Exit Program       *\n";
    cout << "**************************\n";
    cout << "Select an option: ";
}

int getMenuChoice()
{
    int choice;
    while (true)
    {
        if (cin >> choice && choice >= 1 && choice <= 4)
        {
            return choice;
        }

        // bad input
        cout << "Invalid choice. Please enter a number between 1 and 4: ";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

Clock getInitialTimeFromUser()
{
    int h, m, s;

    cout << "Enter initial time (24-hour format):\n";
    cout << "Hours (0-23): ";
    while (!(cin >> h) || h < 0 || h > 23)
    {
        cout << "Invalid input. Please enter hours (0-23): ";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    cout << "Minutes (0-59): ";
    while (!(cin >> m) || m < 0 || m > 59)
    {
        cout << "Invalid input. Please enter minutes (0-59): ";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    cout << "Seconds (0-59): ";
    while (!(cin >> s) || s < 0 || s > 59)
    {
        cout << "Invalid input. Please enter seconds (0-59): ";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return Clock(h, m, s);
}

int main()
{
    Clock clock = getInitialTimeFromUser();
    bool running = true;

    while (running)
    {
        displayClock(clock);
        displayMenu();
        int choice = getMenuChoice();

        switch (choice)
        {
        case 1:
            clock.addHour();
            break;
        case 2:
            clock.addMinute();
            break;
        case 3:
            clock.addSecond();
            break;
        case 4:
            running = false;
            cout << "Exiting program. Goodbye!\n";
            break;
        }
    }
    cout << "\nGoodbye!\n";
    return 0;
}
