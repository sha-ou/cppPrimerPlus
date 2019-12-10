#include "account.h"
#include <iostream>

Account::Account(void)
{
    m_userName = "Mr. Nobody";
    m_accountID = "1234567";
    m_money = 0.0;
}

Account::Account(std::string userName, std::string accountID, double money)
{
    m_userName = userName;
    m_accountID = accountID;
    m_money = money;
}

Account::~Account(void)
{
    using namespace std;
    cout << "I am " << m_userName << " : " << m_accountID << endl;
    cout << "\tGood Bye." << endl;
    return;
}

void Account::show(void) const
{
    using namespace std;
    cout << "I am " << m_userName << endl;
    cout << "\tMy id is " << m_accountID << endl;
    cout << "\tMy money: " << m_money << endl;
    return;
}

void Account::addMoney(double money)
{
    using namespace std;
    if (money < 0) {
        cout << "Add money cannot be negative. Abort!" << endl;
        return;
    }

    m_money += money;
    return;
}

void Account::delMoney(double money)
{
    using namespace std;
    if (money < 0) {
        cout << "Add money cannot be negative. Abort!" << endl;
        return;
    } else if (money > m_money) {
        cout << "Del money is larger than that you have. Abort!" << endl;
        return;
    }

    m_money -= money;
    return;
}
