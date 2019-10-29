#include <iostream>

using namespace std;

int fun(int a);
int fun(int a, int b=1);

int main(void)
{
    fun(1);
    fun(1, 2);
    return 0;
}

int fun(int a)
{
    cout << __FUNCTION__ << " : " << __LINE__ << endl;
}

int fun(int a, int b)
{
    cout << __FUNCTION__ << " : " << __LINE__ << endl;
}
