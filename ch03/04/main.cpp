#include <iostream>

using namespace std;

void ShowTime(long secs);
int main(void)
{
    long secs;

    cout << "Enter the number of seconds: ";
    cin >> secs;
    ShowTime(secs);

    return 0;
}

void ShowTime(long secs)
{
    const int dayInHours = 24;
    const int hourInMinutes = 60;
    const int minuteInSeconds = 60;

    long tmp = secs;
    int days = tmp / (dayInHours*hourInMinutes*minuteInSeconds);
    tmp = tmp % (dayInHours*hourInMinutes*minuteInSeconds);

    int hours = tmp / (hourInMinutes*minuteInSeconds);
    tmp = tmp % (hourInMinutes*minuteInSeconds);

    int minutes = tmp / minuteInSeconds;
    int seconds = tmp % minuteInSeconds;

    cout << secs << " seconds = ";
    cout << days << " days, ";
    cout << minutes << " minutes, ";
    cout << seconds << " seconds" << endl;

    return;
}
