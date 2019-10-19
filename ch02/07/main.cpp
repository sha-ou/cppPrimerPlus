#include <iostream>

using namespace std;

void ShowTime(int hours, int mins);
int main(void)
{
    int hours, mins;

    cout << "Enter the number of hours: ";
    cin >> hours;
    cout << "Enter the number of minutes: ";
    cin >> mins;

    ShowTime(hours, mins);

    return 0;
}

void ShowTime(int hours, int mins)
{
    cout << "Time: " << hours << ":" << mins << endl;
}
