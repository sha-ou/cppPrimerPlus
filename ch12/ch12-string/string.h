#ifndef __STRING_H__
#define __STRING_H__

#include <iostream>

using std::ostream;
using std::istream;

class String {
    private:
        char * m_str;
        int m_len;
        static int m_strnum;
        static const int CINLIM = 80;
    public:
        String(const char *s);
        String(void);
        String(const String & str);
        ~String(void);
        int length(void) const {
            return m_len;
        }
        String & operator=(const String & str);
        String & operator=(const char * s);
        char & operator[](int i);
        const char & operator[](int i) const;

        friend bool operator<(const String & str1, const String & str2);
        friend bool operator>(const String & str1, const String & str2);
        friend bool operator==(const String & str1, const String & str2);
        friend ostream & operator<<(ostream & os, const String & str);
        friend istream & operator>>(istream & is, String & str);

        static int HowMany(void);
};

#endif
