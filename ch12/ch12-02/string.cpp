#include "string.h"
#include <iostream>
#include <string.h>
#include <ctype.h>

int String::m_strnum = 0;

int String::HowMany(void)
{
    return m_strnum;
}

String::String(const char *s)
{
    m_len = strlen(s);
    m_str = new char[m_len+1];
    strcpy(m_str, s);
    m_strnum++;
}

String::String(void)
{
    m_len = 1;
    m_str = new char[m_len];
    m_str[0] = '\0';
    m_strnum++;
}

String::String(const String & str)
{
    m_strnum++;
    m_len = str.m_len;
    m_str = new char[m_len+1];
    strcpy(m_str, str.m_str);
}

String::~String(void)
{
    m_strnum--;
    delete [] m_str;
}

String & String::operator=(const String & str)
{
    if (this == &str) {
        return *this;
    }
    delete [] m_str;
    m_len = str.m_len;
    m_str = new char[m_len+1];
    strcpy(m_str, str.m_str);
    return *this;
}

String & String::operator=(const char *s)
{
    delete [] m_str;
    m_len = strlen(s);
    m_str = new char[m_len+1];
    strcpy(m_str, s);
    return *this;
}

char & String::operator[](int i)
{
    return m_str[i];
}

const char & String::operator[](int i) const
{
    return m_str[i];
}

bool operator<(const String & str1, const String & str2)
{
    return (strcmp(str1.m_str, str2.m_str) < 0);
}

bool operator>(const String & str1, const String & str2)
{
    return str2 < str1;
}

bool operator==(const String & str1, const String & str2)
{
    return (strcmp(str1.m_str, str2.m_str) == 0);
}

ostream & operator<<(ostream & os, const String & str)
{
    os << str.m_str;
    return os;
}

istream & operator>>(istream & is, String & str)
{
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if (is) {
        str = temp;
    }
    while (is && is.get()!='\n');
    return is;
}

String String::operator+(const String & str) const
{
    int len = m_len + str.m_len;
    char *tmp = new char[len + 1];
    strncpy(tmp, m_str, m_len);
    strncat(tmp, str.m_str, str.m_len);
    tmp[len] = '\0';
    String result =  String(tmp);
    delete [] tmp;
    return result;
}

String String::operator+(const char *str) const
{
    String tmp = String(str);
    return tmp + *this;
}

String operator+(const char *str1, const String & str2)
{
    return str2 + str1;
}

void String::Stringlow(void)
{
    for (int i=0; m_str[i]; i++) {
        if (isupper(m_str[i])) {
            m_str[i] = tolower(m_str[i]);
        }
    }
}

void String::Stringupper(void)
{
    for (int i=0; m_str[i]; i++) {
        if (islower(m_str[i])) {
            m_str[i] = toupper(m_str[i]);
        }
    }
}

int String::Charcnt(char ch) const
{
    int cnt = 0;
    for (int i=0; m_str[i]; i++) {
        if (m_str[i] == ch) {
            cnt++;
        }
    }
    return cnt;
}
