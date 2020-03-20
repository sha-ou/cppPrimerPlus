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
