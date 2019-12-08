#include "stock.h"
#include <iostream>

void Stock::acquire(const std::string & co, long n, double pr)
{
    /* 设置公司 */
    company = co;

    /* 设置shares */
    if (n < 0) {
        std::cout << "Number of shares can't be negative; "
            << company << " shares set to 0." << std::endl;
        shares = 0;
    } else {
        shares = n;
    }

    /* 设置share_val */
    share_val = pr;

    /* 计算总数 */
    set_tot();
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

void Stock::show(void)
{
    std::ios_base::fmtflags orig = std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);

    /* 修改浮点数输出格式为#.### */
    std::streamsize prec = std::cout.precision(3);
    std::cout << "Company: " << company
        << " Shares: " << shares << std::endl;
    std::cout << "Share Price: $" << share_val;

    /* 修改浮点数输出格式为#.## */
    std::cout.precision(2);
    std::cout << "Total Worth: $" << total_val << std::endl;

    /* 恢复以前设置 */
    std::cout.setf(orig, std::ios_base::floatfield);
    std::cout.precision(prec);
}
