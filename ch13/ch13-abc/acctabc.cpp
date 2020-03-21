#include <iostream>
#include "acctabc.h"

using std::cout;
using std::ios_base;
using std::endl;
using std::string;

AcctABC::AcctABC(const string & s, long an, double bal)
{
    fullName = s;
    acctNum = an;
    balance = bal;
}

void AcctABC::Deposit(double amt)
{
    if (amt < 0) {
        cout << "Negative deposit not allowed;"
            << "deposit is cancelled." << endl;
    } else {
        balance += amt;
    }
}

void AcctABC::Withdraw(double amt)
{
    balance -= amt;
}

AcctABC::Formatting AcctABC::SetFormat() const
{
    Formatting f;
    f.flag = cout.setf(ios_base::fixed, ios_base::floatfield);
    f.pr = cout.precision(2);
    return f;
}

void AcctABC::Restore(Formatting & f) const
{
    cout.setf(f.flag, ios_base::floatfield);
    cout.precision(f.pr);
}

void Brass::Withdraw(double amt)
{
    if (amt < 0) {
        cout << "Negative deposit not allowed;"
            << "deposit is cancelled." << endl;
    } else if (amt <= Balance()) {
        AcctABC::Withdraw(amt);
    } else {
        cout << "Withdraw amount of $" << amt
            << " exceeds your balance" << endl
            << "Withdraw canceled." << endl;
    }
}

void Brass::ViewAcct() const
{
    Formatting f = SetFormat();
    cout << "Brass Client: " << FullName() << endl;
    cout << "Account Number: " << AcctNum() << endl;
    cout << "Balance: $" << Balance() << endl;
    Restore(f);
}

BrassPlus::BrassPlus(const string & s, long an,
        double bal, double ml,
        double r) : AcctABC(s, an, bal)  // 初始化列表只在实现构造函数时使用
{
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

BrassPlus::BrassPlus(const Brass & ba, double ml,
        double r) : AcctABC(ba)  // 这里使用的是隐式复制构造函数
{
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

void BrassPlus::ViewAcct() const
{
    Formatting f = SetFormat();

    cout << "BrassPlus Client: " << FullName() << endl;
    cout << "Account Number: " << AcctNum() << endl;
    cout << "Balance: $" << Balance() << endl;
    cout << "Maximum loan: $" << maxLoan << endl;
    cout << "Owed to bank: $" << owesBank << endl;
    cout.precision(3);
    cout << "Loan Rate: " << 100*rate << "%" << endl;

    Restore(f);
}

void BrassPlus::Withdraw(double amt)
{
    Formatting f = SetFormat();

    double bal = Balance();
    if (amt <= bal) {
        AcctABC::Withdraw(amt);
    } else if (amt <= bal + maxLoan - owesBank) {
        double advance = amt - bal;
        owesBank += advance * (1.0 + rate);
        cout << "Bank advance: $" << advance << endl;
        cout << "Finance charge: $" << advance*rate << endl;
        Deposit(advance);
        AcctABC::Withdraw(amt);
    } else {
        cout << "Credit limit exceeded."
            << " Transaction cancelled." << endl;
    }

    Restore(f);
}