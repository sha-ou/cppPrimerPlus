#include <iostream>
#include "brass.h"

int main()
{
    using std::cout;
    using std::endl;

    Brass Piggy("Porcelot Pigg", 381299, 4000.0);
    BrassPluss Hoggy("Horatio Hogg", 382288, 3000.0);

    Piggy.ViewAcct();
    cout << endl;
    Hoggy.ViewAcct();
    cout << endl;

    cout << "Deposit $1000 into the Hoggy account:\n";
    Hoggy.Deposit(1000);
    cout << "New balance: $" << Hoggy.Balance() << endl;

    cout << "Withdraw $4200 from the Piggy account:\n";
    Piggy.Withdraw(4200);
    cout << "New balance: $" << Piggy.Balance() << endl;

    cout << "Withdraw $4200 from the Hoggy account:\n";
    Hoggy.Withdraw(4200);
    Hoggy.ViewAcct();

    return 0;
}
