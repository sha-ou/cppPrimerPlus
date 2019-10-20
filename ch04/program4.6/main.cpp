#include <iostream>

using namespace std;

int main(void)
{
    int year;
    cout << "What year was your house built?" << endl;
    cin >> year;

    char addr[80];
    cout << "What is its street address?" << endl;
    cin.getline(addr, 80);

    cout << "Year built: " << year << endl;
    cout << "Address: " << addr << endl;
    cout << "Done!" << endl;

    cout << "What year was your house built?" << endl;
    (cin >> year).get();

    cout << "What is its street address?" << endl;
    cin.getline(addr, 80);

    cout << "Year built: " << year << endl;
    cout << "Address: " << addr << endl;
    cout << "Done!" << endl;

    return 0;
}
