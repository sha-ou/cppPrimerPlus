#include <iostream>

using namespace std;

unsigned long fun(unsigned long num);

int main(void)
{
    for (int i=0; i<20; i++) {
        cout << i << "! = " << fun(i) << endl;
    }
    return 0;
}

unsigned long fun(unsigned long num)
{
    if (num==0) {
        return 1;
    } else {
        return num*fun(num-1);
    }
}
