#include "sales.h"
#include <iostream>

SALES::Sales::Sales(void)
{
    int i = 0;
    double sum = 0.0;

    double item;
    for (i=0; i<4; i++) {
        std::cout << "Enter number: ";
        std::cin >> item;
        std::cin.get();
        sum += item;
        if (i==0) {
            m_max = item;
            m_min = item;
        } else {
            m_max = (m_max < item) ? item : m_max;
            m_min = (m_min > item) ? item : m_min;
        }
        m_sales[i] = item;
    }
    m_average = sum / i;
}

SALES::Sales::Sales(const double ar[], int n)
{
    double sum = 0;
    int min = (n<=4) ? n : 4;

    m_max = ar[0];
    m_min = ar[0];
    int i = 0;
    for (i=0; i<min; i++) {
        sum += ar[i];
        m_max = (m_max < ar[i]) ? ar[i] : m_max;
        m_min = (m_min > ar[i]) ? ar[i] : m_min;
    }
    m_average = sum / i;
}

SALES::Sales::~Sales(void)
{
    using namespace std;

    cout << "Bye" << endl;
    return;
}

void SALES::Sales::show(void) const
{
    std::cout << "Salem_max = " << m_max << std::endl;
    std::cout << "Salem_min = " << m_min << std::endl;
    std::cout << "Salem_average = " << m_average << std::endl;
}

