#include <iostream>
#include <limits.h>

using namespace std;

int main(void)
{
    cout << "sizeof xxx: " << endl;
    cout << "sizeof int = " << sizeof(int) << endl;
    cout << "sizeof short = " << sizeof(short) << endl;
    cout << "sizeof long = " << sizeof(long) << endl;
    cout << "sizeof long long = " << sizeof(long long) << endl << endl;

    cout << "Max:" << endl;
    cout << "max int = " << INT_MAX << endl;
    cout << "max short = " << SHRT_MAX << endl;
    cout << "max long = " << LONG_MAX << endl;
    cout << "max long long = " << LLONG_MAX << endl << endl;

    cout << "Min:" << endl;
    cout << "min int = " << INT_MIN << endl;
    cout << "min short = " << SHRT_MIN << endl;
    cout << "MIN long = " << LONG_MIN << endl;
    cout << "MIN long long = " << LLONG_MIN << endl << endl;

    return 0;
}
