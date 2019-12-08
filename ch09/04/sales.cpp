#include "sales.h"
#include <iostream>

namespace SALES {
    void setSales(Sales & s, const double ar[], int n)
    {
        double sum = 0;
        int min = (n<=4) ? n : 4;

        s.max = ar[0];
        s.min = ar[0];
        int i = 0;
        for (i=0; i<min; i++) {
            sum += ar[i];
            s.max = (s.max < ar[i]) ? ar[i] : s.max;
            s.min = (s.min > ar[i]) ? ar[i] : s.min;
        }
        s.average = sum / i;
    }

    void setSales(Sales & s)
    {
        int i = 0;
        double sum = 0.0;

        double item;
        for (i=0; i<4; i++) {
            std::cout << "Enter number: ";
            std::cin >> item;
            std::cin.get();
            sum += item;
            if (i==0) {
                s.max = item;
                s.min = item;
            } else {
                s.max = (s.max < item) ? item : s.max;
                s.min = (s.min > item) ? item : s.min;
            }
            s.sales[i] = item;
        }
        s.average = sum / i;
    }

    void showSales(const Sales & s)
    {
        std::cout << "Sales.max = " << s.max << std::endl;
        std::cout << "Sales.min = " << s.min << std::endl;
        std::cout << "Sales.average = " << s.average << std::endl;
    }
}
