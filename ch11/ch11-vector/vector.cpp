#include "vector.h"
#include <math.h>

using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;
using std::endl;


namespace VECTOR {
    const double Rad_to_deg = 45.0 / atan(1.0);

    void Vector::set_mag(void)
    {
        m_mag = sqrt(m_x*m_x + m_y*m_y);
    }

    void Vector::set_ang(void)
    {
        if (m_x == 0.0 && m_y == 0.0) {
            m_ang = 0.0;
        } else {
            m_ang = atan2(m_y, m_x);
        }
    }

    void Vector::set_x(void)
    {
        m_x = m_mag * cos(m_ang);
    }

    void Vector::set_y(void)
    {
        m_y = m_mag * sin(m_ang);
    }

    Vector::Vector(void)
    {
        m_x = m_y = m_mag = m_ang = 0.0;
        m_mode = RECT;
    }

    Vector::Vector(double n1, double n2, Mode form)
    {
        m_mode = form;

        if (m_mode == RECT) {
            m_x = n1;
            m_y = n2;
            set_mag();
            set_ang();
        } else if (m_mode == POL) {
            m_mag = n1;
            m_ang = n2 / Rad_to_deg;
            set_x();
            set_y();
        } else {
            cout << "Incorrect 3rd argument to Vector() -- ";
            cout << "vector set to 0" << endl;
            m_x = m_y = m_mag = m_ang = 0.0;
            m_mode = RECT;
        }
    }

    void Vector::reset(double n1, double n2, Mode form)
    {
        m_mode = form;

        if (m_mode == RECT) {
            m_x = n1;
            m_y = n2;
            set_mag();
            set_ang();
        } else if (m_mode == POL) {
            m_mag = n1;
            m_ang = n2 / Rad_to_deg;
            set_x();
            set_y();
        } else {
            cout << "Incorrect 3rd argument to Vector() --";
            cout << "vector set to 0" << endl;
            m_x = m_y = m_mag = m_ang = 0.0;
            m_mode = RECT;
        }
    }

    Vector::~Vector(void)
    {
        return;
    }

    void Vector::polar_mode(void)
    {
        m_mode = POL;
    }

    void Vector::rect_mode(void)
    {
        m_mode = RECT;
    }

    Vector Vector::operator+(const Vector & v) const
    {
        return Vector(m_x + v.m_x, m_y + v.m_y);
    }

    Vector Vector::operator-(const Vector & v) const
    {
        return Vector(m_x-v.m_x, m_y-v.m_y);
    }

    Vector Vector::operator-(void) const
    {
        return Vector(-m_x, -m_y);
    }

    Vector Vector::operator*(double n) const
    {
        return Vector(m_x*n, m_y*n);
    }

    Vector operator*(double n, const Vector & v)
    {
        return v*n;
    }

    std::ostream & operator<<(std::ostream & os, const Vector & v)
    {
        if (v.m_mode == Vector::RECT) {
            os << "(x, y) = (" << v.m_x << ", " << v.m_y << ")";
        } else if (v.m_mode == Vector::POL) {
            os << "(m, a) = (" << v.m_mag << ", " << v.m_ang << ")";
        } else {
            os << "Vector object mode is invalid";
        }
        return os;
    }
};
