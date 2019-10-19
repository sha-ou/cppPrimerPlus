#include <iostream>
#include <math.h>

using namespace std;

int GetFoots(int inche, int foot);
double Foot2Meter(double foots);
double Pound2Kg(double pound);
double GetBMI(double weight, double higheit);
int main(void)
{
    int inche, foot;
    double pound;

    cout << "Enter the inche part of your higheit: ";
    cin >> inche;
    cout << "Enter the foot part of your higheit: ";
    cin >> foot;
    cout << "Enter your weight in pound: ";
    cin >> pound;

    int higheit = GetFoots(inche, foot);
    double higheitMeters = Foot2Meter(higheit);
    double weightKg = Pound2Kg(pound);
    double BMI = GetBMI(weightKg, higheitMeters);

    cout << "Your BMI is : " << BMI << endl;

    return 0;
}

int GetFoots(int inche, int foot)
{
    const int factor = 12;
    return inche * factor + foot;
}

double Foot2Meter(double foots)
{
    const float factor = 0.254f;
    return foots * factor;
}

double Pound2Kg(double pound)
{
    const float factor = 0.45359;
    return pound * factor;
}

double GetBMI(double weight, double higheit)
{
    return pow(weight, 2)/higheit;
}
