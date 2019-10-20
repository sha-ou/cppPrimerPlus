#include <iostream>
#include <array>

using namespace std;

int main(void)
{
    array<double, 3> grades;

    cout << "1st: ";
    cin >> grades[0];
    cout << "2nd: ";
    cin >> grades[1];
    cout << "3rd: ";
    cin >> grades[2];

    cout << "1st: " << grades[0] << endl;
    cout << "2nd: " << grades[1] << endl;
    cout << "3rd: " << grades[2] << endl;
    cout << "avg: " << (grades[0]+grades[1]+grades[2])/3.0 << endl;
    return 0;
}
