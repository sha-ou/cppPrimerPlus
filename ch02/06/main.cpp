#include <iostream>

using namespace std;

double LightYears2AstroUnit(double lightYears);
int main(void)
{
    double lightYears;

    cout << "Enter the number of light years: ";
    cin >> lightYears;
    cout << lightYears << " light years = " << LightYears2AstroUnit(lightYears)
         << " astronomical unite" << endl;
    return 0;
}

double LightYears2AstroUnit(double lightYears)
{
    return lightYears*63240;
}
