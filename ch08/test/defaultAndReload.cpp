#include <iostream>

using namespace std;

void func1(int a);
void func1(int a, int b);

int main(void)
{
    func1(1);
    func1(2, 3);
    return 0;
}

void func1(int a)
{
    cout <<  __FUNCTION__ << " : " << __LINE__ << endl;
}
void func1(int a, int b)
{
    cout <<  __FUNCTION__ << " : " << __LINE__ << endl;
}
