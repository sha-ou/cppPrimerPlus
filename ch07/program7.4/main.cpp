#include <iostream>

long double probability(unsigned numbers, unsigned picks);

int main(void)
{
    using namespace std;

    double total, choices;
    cout << "Enter the total number of choices on the game card and\n";
    cout << "the number of picks allowed: \n";

    while ((cin >> total >> choices) && choices <= total) {
        cout << "You have one chance in ";
        cout << probability(total, choices);
        cout << " of winning.\n";
        cout << "Next two numbers (q to quit): ";
    }

    cout << "Bye." << endl;

    return 0;
}

