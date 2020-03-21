#include "tabtenn.h"
#include <iostream>

/* 列表初始化，在为变量申请内存的时候把值填进去 */
TableTennisPlayer::TableTennisPlayer(const string & fn, const string & ln,
        bool ht) : firstname(fn), lastname(ln), hasTable(ht)
{}

/* const限制对象调用这个方法时不能修改调用对象 */
void TableTennisPlayer::Name() const
{
    std::cout << lastname << ", " << firstname;
}

// RatePlayer的方法
// 使用了列表初始化，TableTennisPlayer(fn, ln, ht)使用了构造函数
//
// 创建派生类对象时，程序首先创建基类对象。
// 这意味着基类对象应当在程序进入派生类对象的构造函数之前被创建。
// c++使用成员初始化列表来完成这种工作
//
// 1. 首先创建基类对象
// 2. 派生类构造函数应通过成员初始化列表将基类信息传递给基类构造函数
// 3. 派生类构造函数应初始化派生类新增的数据成员
RatePlayer::RatePlayer(unsigned int r, const string & fn,
        const string & ln,
        bool ht) : TableTennisPlayer(fn, ln, ht)
{
    rating = r;
}

// 使用了列表初始化，TableTennisPlayer(tp)使用了编译器提供的默认复制构造函数
RatePlayer::RatePlayer(unsigned int r,
        const TableTennisPlayer &tp) : TableTennisPlayer(tp), rating(r)
{}
