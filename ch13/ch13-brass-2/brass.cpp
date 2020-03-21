#include <iostream>
#include "brass.h"

using std::cout;
using std::endl;
using std::string;

// formating stuff
typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;
format setFormat();
void restore(format f, precis p);

// Brass methods
Brass::Brass(const string & s, long an, double bal)
{
    fullName = s;
    acctNum = an;
    balance = bal;
}

void Brass::Deposit(double amt)
{
    if (amt<0) {
        cout << "Err\n";
    } else {
        balance += amt;
    }
}

void Brass::Withdraw(double amt)
{
    format initialState = setFormat();
    precis prec = cout.precision(2);

    if (amt<0) {
        cout << "Err\n";
    } else if (amt<=balance) {
        balance -= amt;
    } else {
        cout << "Withdraw amount of $" << amt
            << " exceeds your balance\n"
            << "Withdraw cancled\n";
    }

    restore(initialState, prec);
}

double Brass::Balance() const
{
    return balance;
}

void Brass::ViewAcct() const
{
    format initialState = setFormat();
    precis prec = cout.precision(2);

    cout << "Client: " << fullName << endl;
    cout << "Account Number: " << acctNum << endl;
    cout << "Balance: $" << balance << endl;

    restore(initialState, prec);
}

// BrassPluss Methods
// 使用成员初始化列表方法，初始化基类对象
// 这里使用的是构造函数
BrassPluss::BrassPluss(const string &s, long an, double bal,
        double ml, double r): Brass(s, an, bal)
{
    maxLoan = ml;
    owesBank = 0;
    rate = r;
}

// 使用成员初始化列表方法，初始化基类对象
// 这里使用的是编译器提供的默认复制构造函数
BrassPluss::BrassPluss(const Brass &ba, double ml, double r)
    : Brass(ba)
{
    maxLoan = ml;
    owesBank = 0;
    rate = r;
}

void BrassPluss::ViewAcct() const
{
    format initialState = setFormat();
    precis prec = cout.precision(2);

    Brass::ViewAcct(); // 使用作用域解析运算符来调基类同名方法
    cout << "Maximum loan: $" << maxLoan << endl;
    cout << "Owed to bank: $" << owesBank << endl;
    cout.precision(3);
    cout << "Loan Rate: " << 100*rate << "%\n";
    restore(initialState, prec);
}

void BrassPluss::Withdraw(double amt)
{
    format initialState = setFormat();
    precis prec = cout.precision(2);

    double bal = Balance();
    if (amt<=bal) {
        Brass::Withdraw(amt);
    } else if (amt<=bal+maxLoan-owesBank) {
        double advance = amt - bal;
        owesBank += advance*(1.0+rate);
        cout << "Bank advance: $" << advance << endl;
        cout << "Finance charge: $" << advance*rate << endl;
        Deposit(advance);
        Brass::Withdraw(amt);
    } else {
        cout << "Exceeded. Canled\n";
    }

    restore(initialState, prec);
}

format setFormat()
{
    return cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
}

void restore(format f, precis p)
{
    cout.setf(f, std::ios_base::floatfield);
    cout.precision(p);
}
