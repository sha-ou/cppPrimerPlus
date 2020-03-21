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

RatePlayer::RatePlayer(unsigned int r, const string & fn, const string & ln,
        bool ht) : TableTennisPlayer(fn, ln, ht) {
    m_rate = r;
}

RatePlayer::RatePlayer(unsigned int r, const TableTennisPlayer & tp) : TableTennisPlayer(tp), m_rate(r)
{

}
