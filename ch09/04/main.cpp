#include "sales.h"
#include <iostream>

int main(void)
{
    SALES::Sales sales1;
    SALES::Sales sales2;

    SALES::setSales(sales1);
    SALES::setSales(sales2, sales1.sales, 4);

    std::cout << "sales1: " << std::endl;
    SALES::showSales(sales1);
    std::cout << "sales2: " << std::endl;
    SALES::showSales(sales2);

    return 0;
}
