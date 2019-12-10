#ifndef __SALES_H__
#define __SALES_H__

namespace SALES {
    class Sales {
        private:
            static const int QUARTERS = 4;
            double m_sales[QUARTERS];
            double m_average;
            double m_max;
            double m_min;
        public:
            Sales(void);
            Sales(const double ar[], int n);
            ~Sales(void);

            void show(void) const;

    };
}

#endif
