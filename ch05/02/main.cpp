#include <iostream>
#include <array>

using namespace std;

const int arrSize = 101;
int main(void)
{
    array<long double, arrSize> factorials;
    factorials[0] = 1;
    factorials[1] = 1;

    for (int i=2; i<arrSize; i++) {
        factorials[i] = i*factorials[i-1];
    }

    for (int i=0; i<arrSize; i++) {
        cout << i << "! = " << factorials[i] << endl;
    }

    return 0;
}
