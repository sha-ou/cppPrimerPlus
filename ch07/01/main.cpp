#include <iostream>

using namespace std;

double avg(double x, double y);
int main(void)
{
    double x = 0.0;
    double y = 0.0;

    cout << "Enter num#1: ";
    cin >> x;
    cout << "Enter num#2: ";
    cin >> y;
    while (x!=0.0 && y!=0.0) {
        cout << "Avg: " << avg(x,y) << endl;
        cout << "Enter num#1: ";
        cin >> x;
        cout << "Enter num#2: ";
        cin >> y;
    }

    return 0;
}

double avg(double x, double y)
{
    return 2.0*x*y/(x+y);
}
