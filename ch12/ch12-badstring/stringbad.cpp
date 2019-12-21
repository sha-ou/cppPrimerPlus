#include "stringbad.h"
#include <string.h>

using std::cout;

int Stringbad::m_stringnum = 0;

Stringbad::Stringbad(const char *s)
{
    m_len = strlen(s);
    m_str = new char[m_len+1];
    strcpy(m_str, s);
    m_stringnum++;
    cout << m_stringnum << ": \"" << m_str << "\" object created" << std::endl;
}

Stringbad::Stringbad(void)
{
    m_len = 4;
    m_str = new char[m_len];
    strcpy(m_str, "c++");
    m_stringnum++;
    cout << m_stringnum << ": \"" << m_str << "\" object created" << std::endl;
}

Stringbad::~Stringbad(void)
{
    cout << "\"" << m_str << "\" object deleted" << std::endl;
    m_stringnum--;
    cout << m_stringnum << " left" << std::endl;
    delete [] m_str;
}

std::ostream & operator<<(std::ostream & os, const Stringbad & st)
{
    os << st.m_str;
    return os;
}
