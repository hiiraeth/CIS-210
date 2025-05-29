#ifndef CLOCK_H
#define CLOCK_H

#include <string>

// --- prototypes ---

void changeHourFormat(int& h12, int& h24);
bool checkValidInput(int h12, int m12, int s12);
void setInitialTime(int& h12, int& m12, int& s12,
    int& h24, int& m24, int& s24);

void changeHour(int& hr12, int& hr24);
void changeMinute(int& hr12, int& hr24,
    int& min12, int& min24);
void changeSecond(int& hr12, int& hr24,
    int& min12, int& min24,
    int& sec12, int& sec24);
void updateClock(int choice,
    int& h12, int& m12, int& s12,
    int& h24, int& m24, int& s24);

void displayClocks(int h12, int m12, int s12,
    int h24, int m24, int s24,
    std::string& timeDay);
void displayMenu();
int  menuChoice();

// ------------------
#endif #pragma once
