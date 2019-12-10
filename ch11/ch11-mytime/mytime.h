#ifndef __MYTIME_H__
#define __MYTIME_H__

#include <iostream>

class Time {
    private:
        int m_hours;
        int m_minutes;
    public:
        Time(void);
        Time(int h, int m=0);
        void AddMin(int m);
        void AddHr(int h);
        void Reset(int h=0, int m=0);
        Time operator+(const Time & t) const;
        Time operator-(const Time & t) const;
        Time operator*(double n) const;
        friend Time operator*(double n, const Time & t) { return t * n; }
        friend std::ostream & operator<<(std::ostream & os, const Time & t);
};

#endif
