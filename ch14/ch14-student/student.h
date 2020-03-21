#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <iostream>
#include <string>
#include <valarray>

class Student {
    private:
        typedef std::valarray<double> ArrayDb;
        std::string name;
        ArrayDb scores;
        std::ostream & arr_out(std::ostream & os) const;
    public:
        Student() : name("Null"), scores() {}
        // explicit关键字：关闭隐式转换
        // --> 可以用一个参数调用的构造函数可以用作从参数类型到类类型的隐式转换函数
        // 例如：Student(int n) : name("Null"), scores(n)这个构造函数
        // 如果有一个Student对象doh
        // doh = 5;这句话将调用上面的构造函数，生成一个name为Null、scores(5)的临时对象
        // 并通过赋值语句将临时对象赋值给doh
        // 使用explicit关键字声明后，编译器将认为上述语句是错误的
        explicit Student(const std::string & s) : name(s), scores() {}
        explicit Student(int n) : name("Null"), scores(n) {}
        Student(const std::string & s, int n) : name(s), scores(n) {}
        Student(const std::string & s, const ArrayDb & a) : name(s), scores(a) {}
        Student(const char *str, const double *pd, int n) : name(str), scores(pd, n) {}
        ~Student() {}
        double Average() const;
        const std::string & Name() const;
        double & operator[](int i);

        friend std::istream & operator>>(std::istream & is, Student & stu);
        friend std::istream & getline(std::istream & is, Student & stu);
        friend std::ostream & operator<<(std::ostream & os, const Student & stu);
};

#endif
