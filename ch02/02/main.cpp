#include <iostream>

using namespace std;

double trans(double inLong);
int main(void)
{
    double inLong = 0.0;

    cout << "Input (in long): ";
    cin >> inLong;
    cout << trans(inLong) << endl;

    return 0;
}

double trans(double inLong)
{
    return 220*inLong;
}
