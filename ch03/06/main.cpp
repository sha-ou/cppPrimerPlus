#include <iostream>

using namespace std;

int main(void)
{
    double s, oil;

    cout << "输入里程（英里）：";
    cin >> s;
    cout << "输入耗油（加仑）：";
    cin >> oil;

    cout << "汽车每消耗1加仑油跑过" << s/oil << "英里" << endl;
    return 0;
}
