#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <iostream>

namespace VECTOR {
    class Vector {
        public:
            enum Mode {RECT, POL};
        private:
            double m_x;
            double m_y;
            double m_mag;
            double m_ang;
            Mode m_mode;

            void set_mag(void);
            void set_ang(void);
            void set_x(void);
            void set_y(void);
        public:
            Vector(void);
            Vector(double n1, double n2, Mode form=RECT);
            void reset(double n1, double n2, Mode form=RECT);
            ~Vector(void);

            double xval(void) const { return m_x; }
            double yval(void) const { return m_y; }
            double magval(void) const { return m_mag; }
            double angval(void) const { return m_ang; }

            void polar_mode(void);
            void rect_mode(void);

            Vector operator+(const Vector & v) const;
            Vector operator-(const Vector & v) const;
            Vector operator-(void) const;
            Vector operator*(double n) const;

            friend Vector operator*(double n, const Vector & v);
            friend std::ostream & operator<<(std::ostream & os, const Vector & v);
    };
};
#endif
