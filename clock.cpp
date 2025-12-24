// clock class implementation

#include "Clock.h"
#include <iomanip>
#include <sstream>

Clock::Clock(int h, int m, int s) : hours(h), minutes(m), seconds(s)
{
    normalize();
}
void Clock::normalize()
{
    // handle seconds overflow/underflow
    while (seconds >= 60)
    {
        seconds -= 60;
        minutes++;
    }
    while (seconds < 0)
    {
        seconds += 60;
        minutes--;
    }

    // handle minutes overflow/underflow
    while (minutes >= 60)
    {
        minutes -= 60;
        hours++;
    }
    while (minutes < 0)
    {
        minutes += 60;
        hours--;
    }

    // handle hours overflow/underflow
    while (hours >= 24)
    {
        hours -= 24;
    }
    while (hours < 0)
    {
        hours += 24;
    }
}

void Clock::addHour()
{
    hours++;
    normalize();
}
void Clock::addMinute()
{
    minutes++;
    normalize();
}
void Clock::addSecond()
{
    seconds++;
    normalize();
}
int Clock::getHour24() const
{
    return hours;
}

std::string Clock::getTime24() const
{
    std::ostringstream out;
    out << std::setfill('0')
        << std::setw(2) << hours << ":"
        << std::setw(2) << minutes << ":"
        << std::setw(2) << seconds;
    return out.str();
}

std::string Clock::getTime12() const
{
    int displayHour = hours % 12;
    if (displayHour == 0)
        displayHour = 12; // handle midnight/noon case

    std::string ampm = (hours < 12) ? "AM" : "PM";

    std::ostringstream out;
    out << std::setfill('0')
        << std::setw(2) << displayHour << ":"
        << std::setw(2) << minutes << ":"
        << std::setw(2) << seconds << " "
        << ampm;
    return out.str();
}
