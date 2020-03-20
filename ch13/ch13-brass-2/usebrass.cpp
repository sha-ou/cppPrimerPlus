#include <iostream>
#include <string>
#include "brass.h"

const int CLIENTS = 4;

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;

    Brass *p_clients[CLIENTS];
    std::string temp;
    long tempnum;
    double tempbal;
    char kind;

    for (int i=0; i<CLIENTS; i++) {
        cout << "Enter client's name: ";
        getline(cin, temp);
        cout << "Enter client's account number";
        cin >> tempnum;
        cout << "Enter opening balance: $";
        cin >> tempbal;
        cout << "Enter 1 for Brass account or 2 for BrassPlus account: ";
        while (cin>>kind && (kind!='1' && kind!='2')) {
            cout << "Enter either 1 or 2: ";
        }
        if (kind=='1') {
            p_clients[i] = new Brass(temp, tempnum, tempbal);
        } else {
            double tmax, trate;
            cout << "Enter the overdraft limit: $";
            cin >> tmax;
            cout << "Enter the interest rate as a decimal fraction: ";
            cin >> trate;
            p_clients[i] = new BrassPluss(temp, tempnum, tempbal, tmax, trate);
        }
        while (cin.get()!='\n');
    }

    cout << endl;

    for (int i=0; i<CLIENTS; i++) {
        // p_clients[i]是Brass指针
        // ViewAcct是虚方法
        // 因此这里，p_clients[i]指向什么对象
        // 就调用什么对象的ViewAcct方法的实现
        p_clients[i]->ViewAcct();
        cout << endl;
    }

    for (int i=0; i<CLIENTS; i++) {
        // 当p_clients[i]指向派生类对象时
        // 先调派生类对象的析构函数
        // 再调基类对象的析构函数
        // 因为基类中将析后函数声明为虚函数了
        delete p_clients[i];
    }

    cout << "done\n";
    return 0;
}
