#include <iostream>

using namespace std;

int SumArange(int minVal, int maxVal);
int main(void)
{
    int minVal, maxVal;

    cout << "Enter the min value: ";
    cin >> minVal;
    cout << "Enter the max value: ";
    cin >> maxVal;

    cout << "Sum: " << SumArange(minVal, maxVal) << endl;

    return 0;
}

int SumArange(int minVal, int maxVal)
{
    int sum = 0;

    for (int i=minVal; i<=maxVal; i++) {
        sum += i;
    }

    return sum;
}
