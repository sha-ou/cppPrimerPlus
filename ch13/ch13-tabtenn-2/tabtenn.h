#ifndef __TABTENN_H__
#define __TABTENN_H__

#include <string>

using std::string;

class TableTennisPlayer {
    private:
        string firstname;
        string lastname;
        bool hasTable;
    public:
        TableTennisPlayer(const string & fn="none", const string & ln="none",
                bool ht=false);
        void Name() const;
        bool HasTable() const { return hasTable; }
        void ResetTable(bool v) { hasTable = v; }
};

// 共有派生
// 派生类对象包含基类对象
// 基类公有成员成为派生类的公有成员
// 基类私有成员也成为派生类的一部分，但是只能通过基类的公有和保护方法访问
//
// 派生类对象存储了基类的数据成员 --> 派生类继承了基类的实现
// 派生类对象可以使用基类的方法   --> 派生类继承了基类的接口
//
// 派生类需要有自己的构造函数
// 派生类可以根据需要添加数据成员和成员函数
class RatePlayer : public TableTennisPlayer {
    private:
        unsigned int rating;
    public:
        RatePlayer(unsigned int r=0, const string & fn="none",
                const string & ln="none", bool ht=false);
        RatePlayer(unsigned int r, const TableTennisPlayer &tp);
        unsigned int Rating() const { return rating; }
        void ResetRating(unsigned int r) { rating = r;  }
};

#endif
