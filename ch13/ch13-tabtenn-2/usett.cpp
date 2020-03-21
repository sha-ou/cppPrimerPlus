#include <iostream>
#include "tabtenn.h"

// 派生类可以调用基类非私有接口
// 基类指针可以不进行显示类型转换直接指向派生类对象
// 基类引用可以不进行显示类型转换直接引用派生类对象
// 基类指针或引用指向或引用派生类对象时，只能调用基类方法

int main(void)
{
    using std::cout;
    using std::endl;

    TableTennisPlayer player1("Tara", "Boomdea", false);
    RatePlayer rplayer1(1140, "Mallory", "Duck", true);

    rplayer1.Name();
    if (rplayer1.HasTable()) {
        cout << ": has a table\n";
    } else {
        cout << ": hasn't a table\n";
    }

    player1.Name();
    if (player1.HasTable()) {
        cout << ": has a table\n";
    } else {
        cout << ": hasn't a table\n";
    }

    cout << "Name: ";
    rplayer1.Name();
    cout << "; Rating: " << rplayer1.Rating() << endl;

    RatePlayer rplayer2(1212, player1); // 调用的是第二个构造函数
    cout << "Name: ";
    rplayer2.Name();
    cout << "; Rating: " << rplayer1.Rating() << endl;

    return 0;
}
