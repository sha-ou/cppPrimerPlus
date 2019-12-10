#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include <iostream>

class Account {
    private:
        std::string m_userName;
        std::string m_accountID;
        double m_money;
    public:
        Account();
        Account(std::string userName="Mr. Nobody",
                std::string accountID="1234567",
                double money=0.0);
        ~Account();

        void show(void) const;
        void addMoney(double money);
        void delMoney(double money);
};

#endif
