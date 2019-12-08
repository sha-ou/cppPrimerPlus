#ifndef STOCK_H_
#define STOCK_H_

#include <string.h>
#include <iostream>

class Stock {
    private:
        std::string company;
        long shares;
        double share_val;
        double total_val;
        void set_tot(void) {
            total_val = shares * share_val;
        }
    public:
        Stock();  /* 默认构造函数 */
        Stock(const std::string & co, long n=0, double pr=0.0);  /* 构造函数 */
        ~Stock();  /* 析构函数 */
        void acquire(const std::string & co, long n, double pr);
        void buy(long num, double price);
        void sell(long num, double price);
        void update(double price);
        void show(void);
};

#endif
