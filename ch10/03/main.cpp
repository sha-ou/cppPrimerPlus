#include <iostream>
#include "golf.h"

using namespace std;

int main(void)
{
    Golf golf1 = Golf();
    golf1.show();

    Golf golf2 = Golf("Bill", 20);
    golf2.show();
    return 0;
}
