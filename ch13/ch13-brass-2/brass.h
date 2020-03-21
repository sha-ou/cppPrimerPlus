#ifndef __BRASS_H__
#define __BRASS_H__

#include <string>

// 虚方法实现多态共有继承

// --------------------------------------------------------------------
// |          |        普通方法          |           虚方法           |
// |------------------------------------------------------------------|
// | 对象调用 | 基类对象调基类的方法     | 基类对象调基类方法         |
// |          | 派生类对象调派生类的方法 | 派生类对象调派生类方法     |
// |------------------------------------------------------------------|
// | 指针或引 | 不论什么对象，什么指针调 | 不论什么指针，指向什么对象 |
// | 用调用   | 什么方法                 | 调什么方法                 |
// --------------------------------------------------------------------
//
// 虚方法会继承
//
// 基类析构函数必须声明为虚方法，不然通过指针调用派生类对象，析构时会直接调
// 基类析构函数，声明为虚方法后，派生类对象析构时，会先调派生类的析构函数，
// 然后调基类的析构函数。因此，哪怕基类的析构函数啥也不干，也要显式声明为虚
// 方法。
//

class Brass {
    private:
        std::string fullName;
        long acctNum;
        double balance;
    public:
        Brass(const std::string & s="Nullbody", long an=-1,
                double bal=0.0);
        void Deposit(double amt);
        virtual void ViewAcct() const;  // 与派生类的实现不同
        virtual void Withdraw(double amt);  // 与派生类的实现不同
        double Balance() const;
        virtual ~Brass() {}
};

class BrassPluss : public Brass {
    private:
        double maxLoan;
        double rate;
        double owesBank;
    public:
        BrassPluss(const std::string & s="Nullbody", long an=-1,
                double bal=0.0, double ml=500, double r=0.11125);
        BrassPluss(const Brass & ba, double ml=500, double r=0.11125);
        virtual void ViewAcct() const;  // 与基类的实现不同
        virtual void Withdraw(double amt);  // 与基类的实现不同
        void ResetMax(double m) { maxLoan = m; }
        void ResetRate(double r) { rate = r ; }
        void ResetOwes() { owesBank = 0; }
};

#endif
