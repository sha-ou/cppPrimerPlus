#include "golf.h"
#include <string.h>
#include <iostream>

Golf::Golf(void)
{
    using namespace std;

    cout << "Enter fullname: ";
    cin.getline(m_fullname, LEN);
    cout << "Enter handicap: ";
    cin >> m_hc;

    while (cin.get() != '\n');
}

Golf::Golf(const char * fullname, int hc)
{
    strncpy(m_fullname, fullname, LEN);
    m_hc = hc;
}

Golf::~Golf(void)
{
    using namespace std;

    cout << "Bye" << endl;
    return;
}

void Golf::handicap(int hc)
{
    m_hc = hc;
}

void Golf::show(void) const
{
    using namespace std;

    cout << "fullname: " << m_fullname << endl;
    cout << "handicap: " << m_hc << endl;
}
