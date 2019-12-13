#include "stonewt.h"
#include <iostream>

using std::cout;
using std::endl;

Stonewt::Stonewt(double lbs)
{
    m_stone = int(lbs)/Lbs_per_stn;
    m_pds_left = int(lbs) % Lbs_per_stn;
    m_pounds = lbs;
}

Stonewt::Stonewt(int stn, double lbs)
{
    m_stone = stn;
    m_pds_left = lbs;
    m_pounds = m_stone * Lbs_per_stn + m_pds_left;
}

Stonewt::Stonewt(void)
{
    m_stone = m_pounds = m_pds_left = 0;
}

Stonewt::~Stonewt(void)
{

}

void Stonewt::ShowStn(void)
{
    cout << m_stone << " stones, " << m_pds_left << " pounds" << endl;
}

void Stonewt::ShowLbs(void)
{
    cout << m_pounds << " pounds" << endl;
}
