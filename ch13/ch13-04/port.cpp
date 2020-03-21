#include <iostream>
#include <string.h>
#include "port.h"

Port::Port(const char *br, const char *st, int b)
{
    brand = new char[strlen(br)+1];
    strcpy(brand, br);
    strncpy(style, st, 19);
    style[19] = '\0';
    bottles = b;
}

Port::Port(const Port & p)
{
    brand = new char[strlen(p.brand)+1];
    strcpy(brand, p.brand);
    strncpy(style, p.style, 19);
    style[19] = '\0';
    bottles = p.bottles;
}

Port & Port::operator=(const Port & p)
{
    if (this == &p) {
        return *this;
    }

    delete [] brand;
    brand = new char[strlen(p.brand)+1];
    strcpy(brand, p.brand);
    strncpy(style, p.style, 19);
    style[19] = '\0';
    bottles = p.bottles;

    return *this;
}

Port & Port::operator+=(int b)
{
    bottles += b;
    return *this;
}

Port & Port::operator-=(int b)
{
    if (bottles >= b) {
        bottles -= b;
    }
    return *this;
}

void Port::Show() const
{
    using std::cout;
    using std::endl;

    cout << "Brand: " << brand << endl;
    cout << "Kind: " << style << endl;
    cout << "Bottles: " << bottles << endl;
}

ostream & operator<<(ostream & os, const Port & p)
{
    os << p.brand << ", " << p.style << ", " << p.bottles;
    return os;
}

VintagePort::VintagePort() : Port("none", "vintage", 0)
{
    nickname = new char[1];
    nickname[0] = '\0';
    year = -1;
}

VintagePort::VintagePort(const char *br, int b,
        const char *nn, int y) : Port(br, "vintage", b)
{
    nickname = new char[strlen(nn)+1];
    strcpy(nickname, nn);
    year = y;
}

VintagePort::VintagePort(const VintagePort & vp)
    : Port(vp)
{
    nickname = new char[strlen(vp.nickname)+1];
    strcpy(nickname, vp.nickname);
    year = vp.year;
}

void VintagePort::Show() const
{
    using std::cout;
    using std::endl;

    Port::Show();
    cout << "NickName: " << nickname << endl;
    cout << "Year: " << year;
}

ostream & operator<<(ostream & os, const VintagePort & vp)
{
    os << (Port &)vp;
    os << ", " << vp.nickname << ", " << vp.year;
    return os;
}
