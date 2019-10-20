#include <iostream>

using namespace std;

int main(void)
{
    const int arSize = 20;
    char name[arSize];
    char dessert[arSize];

    cout << "Enter your name: ";
    cin.get(name, arSize).get();
    cout << "Enter your favorite dessert: ";
    cin.get(dessert, arSize).get();

    cout << "I have some delicious " << dessert;
    cout << " for you, " << name << "." << endl;

    return 0;
}
