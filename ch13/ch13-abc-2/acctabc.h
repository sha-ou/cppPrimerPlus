#ifndef __ACCTABC_H__
#define __ACCTABC_H__

#include <iostream>
#include <string>

// 抽象基类
class AcctABC {
    private:
        std::string fullName;
        long acctNum;
        double balance;
    protected:
        struct Formating {
            std::ios_base::fmtflags flag;
            std::streamsize pr;
        };
        const std::string & FullName() const { return fullName; }
        long AcctNum() const { return acctNum; }
        Formating SetFormat() const;
        void Restore(Formating & f) const;
    public:
        AcctABC(const std::string &s="Nullbody", long an=-1,
                double bal=0.0);
        void Deposit(double amt);
        // 内联函数，编译后的代码直接插入到调用它的地方，而不是以函数调用的形式使用
        // 即任何调用这个函数的地方，都有它的代码副本
        double Balance() const { return balance; }
        // 纯虚函数，可以不提供实现，也可提供实现
        // 包含纯虚函数的类不能创建对象，只能用作基类
        // Withdraw这个纯虚函数在AcctABC中提供了实现
        // ViewAcct这个纯虚函数在AcctABC中就没有提供实现
        virtual void Withdraw(double amt) = 0;
        virtual void ViewAcct() const = 0;
        // 基类析构函数必须为虚函数，保证通过基类指针调用析构函数时能调到派生类的析构函数
        virtual ~AcctABC() {}
};

// Brass
class Brass : public AcctABC {
    public:
        // 构造函数在实现时使用成员列表初始化
        Brass(const std::string & s="Nullbody", long an=-1,
                double bal=0.0) : AcctABC(s, an, bal) {}
        virtual void Withdraw(double amt);
        virtual void ViewAcct() const;
        virtual ~Brass() {}
};

// Brass Plus
class BrassPlus : public AcctABC {
    private:
        double maxLoan;
        double rate;
        double owesBank;
    public:
        // 构造函数在声明时不使用成员列表初始化
        BrassPlus(const std::string & s="Nullbody", long an=-1,
                double bal=0.0, double ml=500, double r=0.10);
        BrassPlus(const Brass & ba, double ml=500, double r=0.10);
        virtual void Withdraw(double amt);
        virtual void ViewAcct() const;
        // 内联函数，编译后的代码直接插入到调用它的地方，而不是以函数调用的形式使用
        // 即任何调用这个函数的地方，都有它的代码副本
        void ResetMax(double m) { maxLoan = m; }
        void ResetRate(double r) { rate = r; }
        void ResetOwes() { owesBank = 0; }

};
#endif
