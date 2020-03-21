#ifndef __DMA_H__
#define __DMA_H__

#include <iostream>

class baseDMA {
    private:
        char *label;
        int rating;
    public:
        baseDMA(const char *l="null", int r=0);  // 构造函数
        baseDMA(const baseDMA & rs);  // 复制构造函数
        virtual ~baseDMA();  // 析构函数
        baseDMA & operator=(const baseDMA & rs);  // 赋值构造函数
        friend std::ostream & operator<<(std::ostream & os,
                const baseDMA & rs);  // 友元函数
};

class lacksDMA : public baseDMA {
    private:
        enum { COL_LEN=40 };
        char color[COL_LEN];
    public:
        lacksDMA(const char *c="blank", const char *l="null",
                int r=0);  // 构造函数
        lacksDMA(const char *c, const baseDMA & rs);  // 构造函数重载
        friend std::ostream & operator<<(std::ostream & os,
                const lacksDMA & ls);  // 友元函数
};

class hasDMA : public baseDMA {
    private:
        char *style;
    public:
        hasDMA(const char *s="none", const char *l="null",
                int r=0);  // 构造函数
        hasDMA(const char *s, const baseDMA & rs);  // 构造函数重载
        hasDMA(const hasDMA & hs);  // 复制构造函数
        ~hasDMA();  // 析构函数
        hasDMA & operator=(const hasDMA & hs);  // 赋值构造函数
        friend std::ostream & operator<<(std::ostream & os,
                const hasDMA & hs);  // 友元函数
};

#endif
