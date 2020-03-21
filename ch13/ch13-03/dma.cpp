#include <iostream>
#include <string.h>
#include "dma.h"

// 派生类的复制构造函数：通过列表初始化调基类的复制构造函数
//                       基类的复制构造函数入口参数为派生类的引用，只复制基类部分
// 派生类的赋值构造函数：通过 baseClass::operator=(derivedClass)的形式调用基类的
//                       赋值构造函数来copy基类部分
// 派生类的友元函数    ：通过引用强制类型转换来调用基类的对应友元函数
//
// 派生类包含动态内存管理时，必须为派生类实现复制构造函数、赋值构造函数和析构函数

// abcDMA
abcDMA::abcDMA(const char *l, int r)
{
    label = new char[strlen(l)+1];
    strcpy(label, l);
    rating = r;
}

abcDMA::abcDMA(const abcDMA & as)
{
    label = new char[strlen(as.label)+1];
    strcpy(label, as.label);
    rating = as.rating;
}

abcDMA & abcDMA::operator=(const abcDMA & as)
{
    if (this == &as) {
        return *this;
    }

    delete [] label;
    label = new char[strlen(as.label)+1];
    strcpy(label, as.label);
    rating = as.rating;

    return *this;
}

abcDMA::~abcDMA()
{
    delete [] label;
}

void abcDMA::View() const
{
    std::cout << "Lable: " << label << std::endl;
    std::cout << "Rating: " << rating << std::endl;
}

std::ostream & operator<<(std::ostream & os,
        const abcDMA & as)
{
    os << "Lable: " << as.label << std::endl;
    os << "Rating: " << as.rating << std::endl;
    return os;
}

// baseDMA
baseDMA & baseDMA::operator=(const baseDMA & rs) // 赋值构造函数
{
    if (this == &rs) {
        return *this;
    }
    abcDMA::operator=(rs);
    return *this;
}

void baseDMA::View() const
{
    abcDMA::View();
}

std::ostream & operator<<(std::ostream & os, const baseDMA & rs)  // 友元函数
{
    os << (abcDMA &)rs;
    return os;
}

// lacksDMA
// 使用了成员列表初始化
lacksDMA::lacksDMA(const char *c, const char *l, int r)
    : abcDMA(l, r)
{
    strncpy(color, c, 39);
    color[39] = '\0';
}

// 使用了成员列表初始化
// baseDMA(rs)使用了基类的复制构造函数
lacksDMA::lacksDMA(const char *c, const baseDMA & rs)
    : abcDMA(rs)
{
    strncpy(color, c, 39);
    color[39] = '\0';
}

void lacksDMA::View() const
{
    abcDMA::View();
    std::cout << "Color: " << color << std::endl;
}

std::ostream & operator<<(std::ostream & os, const lacksDMA & ls)
{
    // 通过将派生类引用强制转换为基类引用
    // 从而调用基类的友元函数
    os << (abcDMA &)ls;
    os << "Color: " << ls.color << std::endl;
    return os;
}

// hasDMA
// 使用了成员列表初始化
hasDMA::hasDMA(const char *s, const char *l, int r)
    : abcDMA(l, r)
{
    style = new char[strlen(s)+1];
    strcpy(style, s);
}

// 使用了成员列表初始化
// baseDMA(rs)使用了基类的复制构造函数
hasDMA::hasDMA(const char *s, const baseDMA & rs)
    : abcDMA(rs)
{
    style = new char[strlen(s)+1];
    strcpy(style, s);
}

// 使用了成员列表初始化
// baseDMA(rs)使用了基类的复制构造函数
hasDMA::hasDMA(const hasDMA & hs)
    : abcDMA(hs)
{
    style = new char[strlen(hs.style)+1];
    strcpy(style, hs.style);
}

hasDMA::~hasDMA()
{
    delete [] style;
}

hasDMA & hasDMA::operator=(const hasDMA & hs)
{
    if (this == &hs) {
        return *this;
    }

    // 通过这种方式调用基类的赋值构造函数
    abcDMA::operator=(hs);
    delete [] style;
    style = new char[strlen(hs.style)+1];
    strcpy(style, hs.style);
    return *this;
}

void hasDMA::View() const
{
    abcDMA::View();
    std::cout << "Style: " << style << std::endl;
}

std::ostream & operator<<(std::ostream & os, const hasDMA & hs)
{
    // 通过将派生类引用强制转换为基类引用
    // 从而调用基类的友元函数
    os << (abcDMA &)hs;
    os << "Style: " << hs.style << std::endl;
    return os;
}

