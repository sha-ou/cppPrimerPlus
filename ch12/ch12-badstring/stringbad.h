#ifndef __STRINGBAD_H__
#define __STRINGBAD_H__

#include <iostream>

class Stringbad {
    private:
        char *m_str;
        int m_len;
        static int m_stringnum;
    public:
        Stringbad(const char *s);
        Stringbad(void);
        ~Stringbad(void);
        friend std::ostream & operator<<(std::ostream & os, const Stringbad & st);
};

#endif
