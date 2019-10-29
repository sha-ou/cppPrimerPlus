#include <iostream>
#include <string>

using namespace std;

struct CarStruct {
    string maker;
    unsigned int year;
};

int main(void)
{
    int carNum = 0;

    cout << "How many cars do you wish to catalog? ";
    cin >> carNum;

    struct CarStruct *cars = new struct CarStruct [carNum];
    for (int i=0; i<carNum; i++) {
        cout << "Car #" << i+1 << ":" << endl;
        cout << "Please enter the maker: ";
        cin.get();
        getline(cin, cars[i].maker);
        cout << "Please enter the year make: ";
        cin >> cars[i].year;
    }

    cout << "Here is your collection:" << endl;
    for (int i=0; i<carNum; i++) {
        cout << cars[i].year << " " << cars[i].maker << endl;
    }
    return 0;
}
