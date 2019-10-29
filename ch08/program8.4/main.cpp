#include <iostream>

using namespace std;

void swapr(int &a, int &b);
void swapp(int *a, int *b);
void swapv(int  a, int  b);
int main(void)
{
    int w1 = 300;
    int w2 = 500;

    cout << "w1 = " << w1 << " at " << &w1 << endl;
    cout << "w2 = " << w2 << " at " << &w2 << endl;

    w1 = 300;
    w2 = 500;
    cout << "After swapr:" << endl;
    swapr(w1, w2);
    cout << "w1 = " << w1 << " at " << &w1 << endl;
    cout << "w2 = " << w2 << " at " << &w2 << endl;

    w1 = 300;
    w2 = 500;
    cout << "After swapp:" << endl;
    swapp(&w1, &w2);
    cout << "w1 = " << w1 << " at " << &w1 << endl;
    cout << "w2 = " << w2 << " at " << &w2 << endl;

    w1 = 300;
    w2 = 500;
    cout << "After swapv:" << endl;
    swapv(w1, w2);
    cout << "w1 = " << w1 << " at " << &w1 << endl;
    cout << "w2 = " << w2 << " at " << &w2 << endl;

    return 0;
}

void swapr(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
    cout << "a = " << a << " at " << &a << endl;
    cout << "b = " << b << " at " << &b << endl;
}

void swapp(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
    cout << "a = " << *a << " at " << a << endl;
    cout << "b = " << *b << " at " << b << endl;
}

void swapv(int  a, int  b)
{
    int t = a;
    a = b;
    b = t;
    cout << "a = " << a << " at " << &a << endl;
    cout << "b = " << b << " at " << &b << endl;
}
