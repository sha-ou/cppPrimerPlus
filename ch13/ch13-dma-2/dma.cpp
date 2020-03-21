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

// baseDMA
baseDMA::baseDMA(const char *l, int r)
{
    label = new char[strlen(l)+1];
    strcpy(label, l);
    rating = r;
}

baseDMA::baseDMA(const baseDMA & rs)
{
    label = new char[strlen(rs.label)+1];
    strcpy(label, rs.label);
    rating = rs.rating;
}

baseDMA::~baseDMA()
{
    delete [] label;
}

baseDMA & baseDMA::operator=(const baseDMA & rs)
{
    if (this==&rs) {
        return *this;
    }
    delete [] label;  // 先释放原来的lable
    label = new char[strlen(rs.label)+1];
    strcpy(label, rs.label);
    rating = rs.rating;
    return *this;
}

std::ostream & operator<<(std::ostream & os, const baseDMA & rs)
{
    os << "Lable: " << rs.label << std::endl;
    os << "Rating: " << rs.rating << std::endl;
    return os;
}

// lacksDMA
// 使用了成员列表初始化
lacksDMA::lacksDMA(const char *c, const char *l, int r)
    : baseDMA(l, r)
{
    strncpy(color, c, 39);
    color[39] = '\0';
}

// 使用了成员列表初始化
// baseDMA(rs)使用了基类的复制构造函数
lacksDMA::lacksDMA(const char *c, const baseDMA & rs)
    : baseDMA(rs)
{
    strncpy(color, c, 39);
    color[39] = '\0';
}

std::ostream & operator<<(std::ostream & os, const lacksDMA & ls)
{
    // 通过将派生类引用强制转换为基类引用
    // 从而调用基类的友元函数
    os << (baseDMA &)ls;
    os << "Color: " << ls.color << std::endl;
    return os;
}

// hasDMA
// 使用了成员列表初始化
hasDMA::hasDMA(const char *s, const char *l, int r)
    : baseDMA(l, r)
{
    style = new char[strlen(s)+1];
    strcpy(style, s);
}

// 使用了成员列表初始化
// baseDMA(rs)使用了基类的复制构造函数
hasDMA::hasDMA(const char *s, const baseDMA & rs)
    : baseDMA(rs)
{
    style = new char[strlen(s)+1];
    strcpy(style, s);
}

// 使用了成员列表初始化
// baseDMA(rs)使用了基类的复制构造函数
hasDMA::hasDMA(const hasDMA & hs)
    : baseDMA(hs)
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
    baseDMA::operator=(hs);
    delete [] style;
    style = new char[strlen(hs.style)+1];
    strcpy(style, hs.style);
    return *this;
}

std::ostream & operator<<(std::ostream & os, const hasDMA & hs)
{
    // 通过将派生类引用强制转换为基类引用
    // 从而调用基类的友元函数
    os << (baseDMA &)hs;
    os << "Style: " << hs.style << std::endl;
    return os;
}

