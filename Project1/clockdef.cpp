#include "clock.h"
#include <iostream>
#include <iomanip>

// switches from 12hr format to 24hr and vice versa
void changeHourFormat(int& h12, int& h24)
{
    if (h12 >= 0 && h12 <= 12)
    {
        h24 = h12;
    }
    else if (h12 >= 13 && h12 <= 23)
    {
        h24 = h12;
        h12 -= 12;
    }
}

// makes sure that the user entered a correct number for hours, minutes, and seconds
bool checkValidInput(int h12, int m12, int s12)
{
    if (h12 > 23 || h12 < 0)
    {
        std::cout << "Please enter a valid hour." << std::endl;
        return false;
    }

    if (m12 > 59 || m12 < 0)
    {
        std::cout << "Please enter a valid minute." << std::endl;
        return false;
    }

    if (s12 > 59 || s12 < 0)
    {
        std::cout << "Please enter a valid second." << std::endl;
        return false;
    }

    return true;
}

// takes user input for the initial time
void setInitialTime(int& h12, int& m12, int& s12, int& h24, int& m24, int& s24)
{
    do {
        std::cout << "Please enter the current hour using 2 digits: ";
        std::cin >> h12;

        std::cout << "Please enter the current minute using 2 digits: ";
        std::cin >> m12;

        std::cout << "Please enter the current second using 2 digits: ";
        std::cin >> s12;
    } while (!checkValidInput(h12, m12, s12)); // checks for valid input

    h24 = h12;
    m24 = m12;
    s24 = s12;

    changeHourFormat(h12, h24); // switches format
}

// outputs the 12hr and 24hr clocks side by side to user
void displayClocks(int h12, int m12, int s12, int h24, int m24, int s24, std::string& timeDay)
{

    if (h24 <= 11)
    {
        timeDay = "AM";
    }
    else
    {
        timeDay = "PM";
    }

    std::cout << std::endl;
    std::cout << "*************************" << "   " << "*************************" << std::endl;
    std::cout << "*     12-Hour Clock     *" << "   " << "*     24-Hour Clock     *" << std::endl;

    // formats the numbers and time of day correctly
    std::cout << "*      " << std::setfill('0') << std::setw(2) << h12 << ":"
        << std::setw(2) << m12 << ":"
        << std::setw(2) << s12
        << " " << timeDay << "      *" << "   "
        << "*        " << std::setw(2) << h24 << ":"
        << std::setw(2) << m24 << ":"
        << std::setw(2) << s24 <<
        "       *" << std::endl;

    std::cout << "*************************" << "   " << "*************************" << std::endl << std::endl;
}

// shows the options to the user
void displayMenu()
{
    std::cout << "----------------------" << std::endl;
    std::cout << "| 1 - Add one hour   |" << std::endl;
    std::cout << "| 2 - Add one minute |" << std::endl;
    std::cout << "| 3 - Add one second |" << std::endl;
    std::cout << "| 4 - Exit program   |" << std::endl;
    std::cout << "----------------------" << std::endl << std::endl;
}

// gets choice from user
int menuChoice()
{
    int choice;

    do { // loops until user enters a number between 1-4
        std::cout << "Please enter your choice: ";
        std::cin >> choice;

        if (choice < 1 || choice > 4)
        {
            std::cout << "Please enter a valid selection." << std::endl;
        }
    } while (choice < 1 || choice > 4);

    return choice;
}

// adds one hour to time
void changeHour(int& hr12, int& hr24)
{
    hr12 += 1;
    hr24 += 1;

    // checks to see if 12hr is already at 12, if so then switch to 1
    if (hr12 > 12)
    {
        hr12 -= 12;
    }

    // checks to see if 24hr is at 24, if so switch to 00
    if (hr24 == 24)
    {
        hr24 -= 24;
        hr12 = 12;
    }

}

// adds one minute to time
void changeMinute(int& hr12, int& hr24, int& min12, int& min24)
{
    min12 += 1;

    // will update hour if minute goes from 59 to 60
    if (min12 > 59)
    {
        min12 -= 60;
        changeHour(hr12, hr24);
    }

    min24 = min12;
}

// adds one second to time
void changeSecond(int& hr12, int& hr24, int& min12, int& min24, int& sec12, int& sec24)
{
    sec12 += 1;

    // will update minute (and hour, if needed) if second goes from 59 to 60
    if (sec12 > 59)
    {
        changeMinute(hr12, hr24, min12, min24);
        sec12 -= 60;
    }

    sec24 = sec12;
}

// will update the clock based on user choice
void updateClock(int choice, int& h12, int& m12, int& s12, int& h24, int& m24, int& s24)
{
    switch (choice)
    {
    case 1: // changes hour
        changeHour(h12, h24);
        break;

    case 2: // changes minute
        changeMinute(h12, h24, m12, m24);
        break;

    case 3: // changes second
        changeSecond(h12, h24, m12, m24, s12, s24);
        break;

    default:
        break;
    }
}