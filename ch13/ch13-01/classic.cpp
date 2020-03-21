#include <iostream>
#include <string.h>
#include "classic.h"

Classic::Classic()
{
    Cd();
    plays[0] = '\0';
}

Classic::Classic(char * ps, char * perf, char * lab,
        int sel, double time) : Cd(perf, lab, sel, time)  // 初始化列表，调基类构造函数构造自身基类部分
{
    strncpy(plays, ps, 199);;
    plays[199] = '\0';
}

Classic::Classic(const Classic & cd) : Cd(cd) // 初始化列表，使用基类复制构造函数把基类部分数据复制到自身
{
    strcpy(plays, cd.plays);
}

Classic::~Classic()
{
}

void Classic::Report() const
{
    using std::cout;
    using std::endl;

    Cd::Report(); // 调基类函数
    cout << "Plays: " << plays << endl; // 完成自身特定的Report
}

Classic & Classic::operator=(const Classic & cd)
{
    if (this == &cd) { // 如果等号两侧一样，直接返回自身
        return *this;
    }

    Cd::operator=(cd); // 调基类赋值构造函数构造基类对象
    strcpy(plays, cd.plays); // 构造自身特有的数据成员
    return *this;
}
