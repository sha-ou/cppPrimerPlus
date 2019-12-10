#include "person.h"
#include <iostream>

int main(void)
{
    Person one;
    Person two {"Smythecraft"};

    one.show();
    one.formalShow();

    two.show();
    two.formalShow();

    return 0;
}
