
#include <iostream>

class Time
{
private:
    int hour;
    int minute;
    int second;

public:
    Time() : hour(0), minute(0), second(0) {}


    int hours()
    {
        return hour;
    }

    int minutes()
    {
        return minute;
    }
    int seconds()
    {
        return second;
    }

    void reset(int h, int m, int s)
    {
        if (h >= 0 && h < 24 && m >= 0 && m < 60 && s >= 0 && s < 60)
        {
            hour = h;
            minute = m;
            second = s;
        }
        else
        {
            std::cout << "Invalid time provided. Please provide valid values.\n";
        }
    }


    void advance(int h, int m, int s)
    {
        second += s;
        minute += second / 60;
        second %= 60;

        minute += m;
        hour += minute / 60;
        minute %= 60;

        hour += h;
        hour %= 24;
    }

    void print()
    {
        std::cout << (hour < 10 ? "0" : "") << hour << ":"
                  << (minute < 10 ? "0" : "") << minute << ":"
                  << (second < 10 ? "0" : "") << second << "\n";
    }
};

int main()
{
    Time t;

    t.reset(12, 30, 45);
    t.print();

    t.advance(2, 40, 30);
    t.print();

    t.advance(10, 50, 60);
    t.print();

    return 0;
}
