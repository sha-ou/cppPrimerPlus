#include <iostream>

using namespace std;

int main(void)
{
    const int arSize = 20;
    char name[arSize];
    char dessert[arSize];

    cout << "Enter your name:" << endl;
    cin.getline(name, arSize);
    cout << "Enter your favorite dessert:" << endl;
    cin.getline(dessert, arSize);

    cout << "I have some delicious " << dessert;
    cout << " for you, " << name << "." << endl;

    cout << "Enter your name: ";
    cin.getline(name, arSize);
    cout << "Enter your favorite dessert: ";
    cin.getline(dessert, arSize);

    cout << "name: " << name << "." << endl;
    cout << "dessert: " << dessert << endl;

    return 0;
}
