#include <iostream>

using namespace std;

int main(void)
{
    long populationOfWorld, populationOfChina;

    cout << "Enter the world's population: ";
    cin >> populationOfWorld;
    cout << "Enter the population of China: ";
    cin >> populationOfChina;

    cout << "The population of China is ";
    cout << (double)populationOfChina/(double)populationOfWorld*100.0;
    cout << "% of the world population" << endl;

    return 0;
}
