// clock class definition for managing time in both 12 and 24 hour formats

#ifndef CLOCK_H
#define CLOCK_H

#include <string>

class Clock
{
private:
    int hours;   // 0-23
    int minutes; // 0-59
    int seconds; // 0-59

    // keeps time values within valid ranges
    void normalize();

public:
    Clock(int h = 0, int m = 0, int s = 0);

    // increment operations
    void addHour();
    void addMinute();
    void addSecond();

    int getHour24() const;

    // display helpers
    std::string getTime24() const; // HH:MM:SS format
    std::string getTime12() const; // HH:MM:SS AM/PM format
};
#endif // CLOCK_H
