#include "clock.h"

int main()
{
    int hour12, minute12, second12, hour24, minute24, second24;
    int userChoice = 0;

    std::string timeOfDay = "";

    setInitialTime(hour12, minute12, second12,
        hour24, minute24, second24);

    // will loop through until user selects 4
    while (userChoice != 4)
    {
        displayClocks(hour12, minute12, second12,
            hour24, minute24, second24, timeOfDay);

        displayMenu();
        userChoice = menuChoice();

        updateClock(userChoice, hour12, minute12, second12,
            hour24, minute24, second24);
    }

    return 0;
}
