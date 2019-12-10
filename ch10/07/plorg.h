#ifndef __PLORG_H__
#define __PLORG_H__

#include <iostream>

class Plorg {
    private:
        std::string m_name;
        int m_ci;
    public:
        Plorg(const std::string & name="Plorg", int ci=50);
        void resetCI(int ci);
        void show(void) const;
};

#endif
