#include "stock.h"
#include <iostream>
#include <string.h>

Stock::Stock()
{
    company = new char[1];
    strcpy(company, "");
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}

Stock::Stock(const char *co, long n, double pr)
{
    company = new char[strlen(co) + 1];
    strncpy(company, co, strlen(co));
    company[strlen(co)] = '\0';

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
    delete [] company;
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

std::ostream & operator<<(std::ostream & os, const Stock & st)
{
    std::ios_base::fmtflags orig = os.setf(std::ios_base::fixed, std::ios_base::floatfield);

    /* 修改浮点数输出格式为#.### */
    std::streamsize prec = os.precision(3);
    os << "Company: " << st.company
        << " Shares: " << st.shares << std::endl;
    std::cout << "Share Price: $" << st.share_val;

    /* 修改浮点数输出格式为#.## */
    os.precision(2);
    os << "  Total Worth: $" << st.total_val << std::endl;

    /* 恢复以前设置 */
    os.setf(orig, std::ios_base::floatfield);
    os.precision(prec);

    return os;
}

const Stock & Stock::topval(const Stock & s) const
{
    if (s.total_val > total_val) {
        return s;
    } else {
        return *this;
    }
}
