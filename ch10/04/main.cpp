#include "sales.h"
#include <iostream>

int main(void)
{
    SALES::Sales sales1 = SALES::Sales();
    double sales[] = {5, 6, 7, 8};
    SALES::Sales sales2 = SALES::Sales(sales, 4);

    std::cout << "Sales1 :" << std::endl;
    sales1.show();
    std::cout << "Sales2 :" << std::endl;
    sales2.show();

    return 0;
}
