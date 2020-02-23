#include <iostream>
#include "brass.h"

int main()
{
    using std::cout;
    using std::endl;

    Brass Piggy("Procelot Pigg", 381229, 4000.00);
    BrassPlus Hoggy("Horatio Hogg", 382288, 3000.00);
    Piggy.ViewAcct();
    cout << endl;
    Hoggy.ViewAcct();
    cout << endl;

    cout << "Depositing $1000 into the Hogg Account: " << endl;
    Hoggy.Deposit(1000.00);
    cout << "New balance: $" << Hoggy.Balance() << endl;

    cout << "Withdrawing $4200 from the Pigg Account: " << endl;
    Piggy.Withdraw(4200.00);
    cout << "Piggy account balance: $" << Piggy.Balance() << endl;

    cout << "Withdrawing $4200 from the Hogg Account: " << endl;
    Hoggy.Withdraw(4200.00);
    Hoggy.ViewAcct();

    return 0;
}
