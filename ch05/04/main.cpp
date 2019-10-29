#include <iostream>
#include <math.h>

using namespace std;

double Daphne(int year);
double Cleo(int year);
int main(void)
{
    int i = 1;

    while (Cleo(i) < Daphne(i)) {
        i++;
    }
    cout << i << endl;

    return 0;
}

double Daphne(int year)
{
    return 100.0 + year*10.0;
}

double Cleo(int year)
{
    return 100.0*pow(1.05, year);
}
