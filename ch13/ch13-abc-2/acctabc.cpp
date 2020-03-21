#include <iostream>
#include "acctabc.h"

using std::cout;
using std::ios_base;
using std::endl;
using std::string;

// AcctABC
AcctABC::AcctABC(const string & s, long an, double bal)
{
    fullName = s;
    acctNum = an;
    balance = bal;
}

void AcctABC::Deposit(double amt)
{
    if (amt<0) {
        cout << "Err\n";
    } else {
        balance += amt;
    }
}

// 虽然Withdraw被声明为纯虚函数，但是仍然可以提供实现
// 纯虚函数只是可以不提供实现，并没有限制不能提供实现
void AcctABC::Withdraw(double amt)
{
    balance -= amt;
}

AcctABC::Formating AcctABC::SetFormat() const
{
    Formating f;
    f.flag = cout.setf(ios_base::fixed, ios_base::floatfield);
    f.pr = cout.precision(2);
    return f;
}

void AcctABC::Restore(Formating & f) const
{
    cout.setf(f.flag, ios_base::floatfield);
    cout.precision(f.pr);
}

// Brass
void Brass::Withdraw(double amt)
{
    if (amt<0) {
        cout << "Err\n";
    } else if (amt<=Balance()) {
        AcctABC::Withdraw(amt);
    } else {
        cout << "Withdraw amount of $" << amt
            << " exceeds your balance\n"
            << "Withdraw cancled\n";
    }
}

void Brass::ViewAcct() const
{
    Formating f = SetFormat();

    // fullName, acctNum, balance都是基类的私有成员
    // 派生类必须通过基类的共有接口来访问
    cout << "Client: " << FullName() << endl;
    cout << "Account Number: " << AcctNum() << endl;
    cout << "Balance: $" << Balance() << endl;

    Restore(f);
}

// BrassPlus
// 构造函数在实现时使用成员列表初始化
BrassPlus::BrassPlus(const string & s, long an, double bal,
        double ml, double r) : AcctABC(s, an, bal)
{
    maxLoan = ml;
    rate = r;
    owesBank = 0;
}

// 这里的成员列表初始化使用了编译器提供的隐式复制构造函数
// 这个隐式复制构造函数的形参是基类引用，但是传入的是派生类引用
// 由于基类引用可以引用派生类，因此是合法的
// 但是这个复制构造函数只复制派生类中基类包含的那部分成员
// 派生类自己添加的成员是不复制的
BrassPlus::BrassPlus(const Brass & ba, double ml,
        double r) : AcctABC(ba)
{
    maxLoan = ml;
    rate = r;
    owesBank = 0;
}

void BrassPlus::Withdraw(double amt)
{
    Formating f = SetFormat();

    double bal = Balance();
    if (amt<=bal) {
        AcctABC::Withdraw(amt);
    } else if (amt<=bal+maxLoan-owesBank) {
        double advance = amt - bal;
        owesBank += advance*(1.0+rate);
        cout << "Bank advance: $" << advance << endl;
        cout << "Finance charge: $" << advance*rate << endl;
        Deposit(advance);
        AcctABC::Withdraw(amt);
    } else {
        cout << "Exceeded. Canled\n";
    }

    Restore(f);
}

void BrassPlus::ViewAcct() const
{
    Formating f = SetFormat();

    // fullName, acctNum, balance都是基类的私有成员
    // 派生类必须通过基类的共有接口来访问
    cout << "Client: " << FullName() << endl;
    cout << "Account Number: " << AcctNum() << endl;
    cout << "Balance: $" << Balance() << endl;
    cout << "Maximum loan: $" << maxLoan << endl;
    cout << "Owed to bank: $" << owesBank << endl;
    cout.precision(3);
    cout << "Loan Rate: " << 100*rate << "%\n";

    Restore(f);
}
