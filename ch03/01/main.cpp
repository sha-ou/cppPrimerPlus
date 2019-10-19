#include <iostream>

using namespace std;

double Foot2Inche(double foots);
int main(void)
{
    double higheitInFoots;

    cout << "Enter your higheit in foots:________\b\b\b\b\b\b\b\b";
    cin >> higheitInFoots;
    cout << "Your higheit in foots: " << higheitInFoots << endl;
    cout << "Your higheit in inches: " << Foot2Inche(higheitInFoots) << endl;

    return 0;
}

double Foot2Inche(double foots)
{
    const double factor = 12.0;
    return foots/factor;
}
