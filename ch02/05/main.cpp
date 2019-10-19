#include <iostream>

using namespace std;

double Celsius2Fahrenheit(double inCelsius);
int main(void)
{
    double inCelsius;

    cout << "Please enter a Celsius value: ";
    cin >> inCelsius;
    cout << inCelsius << " degrees Celsius is " << Celsius2Fahrenheit(inCelsius)
         << " degrees Fahrenheit." << endl;
    return 0;
}

double Celsius2Fahrenheit(double inCelsius)
{
    return 1.8*inCelsius+32.0;
}
