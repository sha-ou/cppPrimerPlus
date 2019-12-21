#include "complex.h"
#include <iostream>

Complex::Complex(double x, double y)
{
    m_x = x;
    m_y = y;
}

Complex Complex::operator+(const Complex & b) const
{
    Complex c;
    c.m_x = m_x + b.m_x;
    c.m_y = m_y + b.m_y;
    return c;
}

Complex Complex::operator-(const Complex & b) const
{
    Complex c;
    c.m_x = m_x - b.m_x;
    c.m_y = m_y - b.m_y;
    return c;
}

Complex Complex::operator*(const Complex & b) const
{
    Complex c;
    c.m_x = m_x*b.m_x - m_y*b.m_y;
    c.m_y = m_x*b.m_y + m_y*b.m_x;
    return c;
}

Complex Complex::operator*(double b) const
{
    Complex c;
    c.m_x = m_x * b;
    c.m_y = m_y * b;
    return c;
}

Complex Complex::operator~(void) const
{
    Complex c;
    c.m_x = m_x;
    c.m_y = -m_y;
    return c;
}

Complex operator*(double a, const Complex & b)
{
    return b * a;
}

std::ostream & operator<<(std::ostream & os, const Complex & b)
{
    os << "(" << b.m_x << ", " << b.m_y << "i)";
    return os;
}

std::istream & operator>>(std::istream & is, Complex & b)
{
    using std::cout;

    cout << "Enter x: ";
    is >> b.m_x;
    while (is.get() != '\n');
    cout << "Enter y: ";
    is >> b.m_y;
    while (is.get() != '\n');

    return is;
}
