#include "tabtenn.h"
#include <iostream>

TableTennisPlayer::TableTennisPlayer(const string & fn,
        const string & ln, bool ht) : m_firstname(fn), m_lastname(ln), m_hastable(ht)
{
}

void TableTennisPlayer::Name(void) const
{
    std::cout << m_lastname << ", " << m_firstname;
}
