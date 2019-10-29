#include <iostream>

using namespace std;

const int & clone(const int &ft);
int main(void)
{
    int t = 4;
    int &ft = clone(t);
    delete &ft;
    return 0;
}

const int & clone(const int &ft)
{
    int *pt = new int;
    *pt = ft;
    return *pt;
}
