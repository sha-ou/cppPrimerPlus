#include <iostream>

using namespace std;

void FirstFunc(void);
void SecFunc(void);
int main(void)
{
    FirstFunc();
    FirstFunc();
    SecFunc();
    SecFunc();
    return 0;
}

void FirstFunc(void)
{
    cout << "Three bind mice" << endl;
}

void SecFunc(void)
{
    cout << "See how they run" << endl;
}
