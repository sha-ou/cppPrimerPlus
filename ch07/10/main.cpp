#include <iostream>

using namespace std;

double calculate(double a, double b, double (*pfunc)(double, double));
double add(double a, double b);

int main(void)
{
    cout << calculate(1, 2, add) << endl;
    return 0;
}

double calculate(double a, double b, double (*pfunc)(double, double))
{
    cout << "Call " << __FUNCTION__ << endl;
    return pfunc(a, b);
}

double add(double a, double b)
{
    cout << "Call " << __FUNCTION__ << endl;
    return a + b;
}
