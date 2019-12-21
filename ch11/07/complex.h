#ifndef __COMPLEX_H__
#define __COMPLEX_H__

#include <iostream>

class Complex {
    private:
        double m_x;
        double m_y;
    public:
        Complex(double x=0.0, double y=0.0);
        Complex operator+(const Complex & b) const;
        Complex operator-(const Complex & b) const;
        Complex operator*(const Complex & b) const;
        Complex operator*(double b) const;
        Complex operator~(void) const;
        friend Complex operator*(double a, const Complex & b);
        friend std::ostream & operator<<(std::ostream & os, const Complex & b);
        friend std::istream & operator>>(std::istream & is, Complex & b);
};

#endif
