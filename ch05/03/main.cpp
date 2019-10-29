#include <iostream>

using namespace std;

void Add(long *pSum, long adder);
void Flush(long sum);
int main(void)
{
    long sum = 0;
    long adder = 0;

    do {
        cout << "Enter: ";
        cin >> adder;
        Add(&sum, adder);
        Flush(sum);
    } while (adder!=0);

    cout << "Bye" << endl;

    return 0;
}

void Add(long *pSum, long adder)
{
    *pSum += adder;
}

void Flush(long sum)
{
    cout << "Current sum: " << sum << endl;
}
