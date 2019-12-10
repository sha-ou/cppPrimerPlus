#ifndef __MYTIME_H__
#define __MYTIME_H__

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
        void Show(void) const;
};

#endif
