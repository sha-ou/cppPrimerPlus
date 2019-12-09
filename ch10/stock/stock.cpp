#include "stock.h"
#include <iostream>

Stock::Stock()
{
    company = "no name";
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}

Stock::Stock(const std::string &co, long n, double pr)
{
    company = co;

    if (n < 0) {
        std::cout << "Number of shares can't be negative; "
            << company << " shares set to 0." << std::endl;
        shares = 0;
    } else {
        shares = n;
    }

    share_val = pr;
    set_tot();
}

Stock::~Stock()
{
}

void Stock::buy(long num, double price)
{
    if (num < 0) {
        /* 买入数量小于0报错 */
        std::cout << "Number of shares purchased can't be negative. "
            << "Transaction is aborted." << std::endl;
    } else {
        /* 增加shares，重设shares_val和total_val */
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price)
{
    if (num < 0) {
        /* 卖出数量小于0报错 */
        std::cout << "Number of shares purchased can't be negative. "
            << "Transaction is aborted." << std::endl;
    } else if (num > shares) {
        /* 卖出数量大于持有数量报错 */
        std::cout << "You can't sell more than you have! "
            << "Transaction is aborted." << std::endl;
    } else {
        /* 降低持有数量，重设shares_val和total_val */
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price)
{
    /* 更新价格 */
    share_val = price;
    set_tot();
}

void Stock::show(void) const
{
    std::ios_base::fmtflags orig = std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);

    /* 修改浮点数输出格式为#.### */
    std::streamsize prec = std::cout.precision(3);
    std::cout << "Company: " << company
        << " Shares: " << shares << std::endl;
    std::cout << "Share Price: $" << share_val;

    /* 修改浮点数输出格式为#.## */
    std::cout.precision(2);
    std::cout << "  Total Worth: $" << total_val << std::endl;

    /* 恢复以前设置 */
    std::cout.setf(orig, std::ios_base::floatfield);
    std::cout.precision(prec);
}

const Stock & Stock::topval(const Stock & s) const
{
    if (s.total_val > total_val) {
        return s;
    } else {
        return *this;
    }
}
