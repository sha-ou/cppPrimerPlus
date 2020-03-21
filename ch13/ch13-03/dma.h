#ifndef __DMA_H__
#define __DMA_H__

#include <iostream>

class abcDMA {
    private:
        char *label;
        int rating;
    public:
        abcDMA(const char *l="null", int r=0);
        abcDMA(const abcDMA & as);
        abcDMA & operator=(const abcDMA & as);
        virtual ~abcDMA();
        virtual void View() const = 0;
        friend std::ostream & operator<<(std::ostream & os,
                const abcDMA & as);
};

class baseDMA : public abcDMA {
    public:
        baseDMA(const char *l="null", int r=0) : abcDMA(l, r) {}  // 构造函数
        virtual ~baseDMA() {}  // 析构函数
        baseDMA & operator=(const baseDMA & rs); // 赋值构造函数
        virtual void View() const;
        friend std::ostream & operator<<(std::ostream & os,
                const baseDMA & rs);  // 友元函数
};

class lacksDMA : public abcDMA {
    private:
        enum { COL_LEN=40 };
        char color[COL_LEN];
    public:
        lacksDMA(const char *c="blank", const char *l="null",
                int r=0);  // 构造函数
        lacksDMA(const char *c, const baseDMA & rs);  // 构造函数重载
        virtual void View() const;
        friend std::ostream & operator<<(std::ostream & os,
                const lacksDMA & ls);  // 友元函数
};

class hasDMA : public abcDMA {
    private:
        char *style;
    public:
        hasDMA(const char *s="none", const char *l="null",
                int r=0);  // 构造函数
        hasDMA(const char *s, const baseDMA & rs);  // 构造函数重载
        hasDMA(const hasDMA & hs);  // 复制构造函数
        ~hasDMA();  // 析构函数
        hasDMA & operator=(const hasDMA & hs);  // 赋值构造函数
        virtual void View() const;
        friend std::ostream & operator<<(std::ostream & os,
                const hasDMA & hs);  // 友元函数
};

#endif
