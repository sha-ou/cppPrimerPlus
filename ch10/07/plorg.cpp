#include "plorg.h"
#include <iostream>

Plorg::Plorg(const std::string & name, int ci)
{
    m_name = name;
    m_ci = ci;
}

void Plorg::resetCI(int ci)
{
    m_ci = ci;
}

void Plorg::show(void) const
{
    using namespace std;

    cout << "Name: " << m_name << endl;
    cout << "CI: " << m_ci << endl;

    return;
}
