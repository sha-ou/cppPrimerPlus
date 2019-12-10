#include "mytime.h"
#include <iostream>

Time::Time(void)
{
    m_hours = 0;
    m_minutes = 0;
}

Time::Time(int h, int m)
{
    m_hours = h;
    m_minutes = m;
}

void Time::AddMin(int m)
{
    m_minutes += m;
    m_hours = m_minutes / 60;
    m_minutes %= 60;
}

void Time::AddHr(int h)
{
    m_hours += h;
}

void Time::Reset(int h, int m)
{
    m_hours = h;
    m_minutes = m;
}

Time Time::operator+(const Time & t) const
{
    Time sum;
    sum.m_minutes = m_minutes + t.m_minutes;
    sum.m_hours = m_hours + t.m_hours + sum.m_minutes / 60;
    sum.m_minutes %= 60;

    return sum;
}

Time Time::operator-(const Time & t) const
{
    Time diff;
    int tot1, tot2;
    tot1 = t.m_minutes + 60 * t.m_hours;
    tot2 = m_minutes + 60 * m_hours;
    diff.m_minutes = (tot2 - tot1) % 60;
    diff.m_hours = (tot2 - tot1) / 60;
    return diff;
}

Time Time::operator*(double n) const
{
    Time result;
    long totalminutes = m_hours * n * 60 + m_minutes * 60;
    result.m_minutes = totalminutes % 60;
    result.m_hours = totalminutes / 60;
    return result;
}

std::ostream & operator<<(std::ostream & os, const Time & t)
{
    os << t.m_hours << " hours, " << t.m_minutes << " minutes";
    return os;
}
