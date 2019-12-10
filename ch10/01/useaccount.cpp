#include "account.h"
#include <iostream>

int main(void)
{
    Account account = Account("Mr. Black", "31415926", 300);
    account.show();

    account.addMoney(200);
    account.show();

    account.delMoney(500);
    account.show();

    return 0;
}
