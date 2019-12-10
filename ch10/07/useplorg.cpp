#include "plorg.h"
#include <iostream>

int main(void)
{
    Plorg plorg1 = Plorg();
    Plorg plorg2 = Plorg("Mr. Black", 30);

    plorg1.show();
    plorg2.show();

    plorg1.resetCI(20);
    plorg1.show();

    return 0;
}
