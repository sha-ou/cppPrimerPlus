#include <iostream>

using namespace std;

double GetDegrees(int degree, int minute, int second);
int main(void)
{
    int degree, minute, second;

    cout << "Enter a latitude in degress, minutes, seconds:" << endl;
    cout << "Enter the degress: ";
    cin >> degree;
    cout << "Enter the minutes of arc: ";
    cin >> minute;
    cout << "Enter the seconds of arc: ";
    cin >> second;

    cout << degree << " degrees, " << minute << " minutes, " << second;
    cout << " seconds = " << GetDegrees(degree, minute, second) << " degrees";
    cout << endl;

    return 0;
}

double GetDegrees(int degree, int minute, int second)
{
    return (double)degree + (double)minute/60.0 + (double)second/3600.0;
}
