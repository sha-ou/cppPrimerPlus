#include <iostream>
#include <string>

using namespace std;

struct Pizz {
    string corpuration;
    double d;
    double weight;
};

int main(void)
{
    struct Pizz aPizz;

    cout << "Enter the corpu: ";
    getline(cin, aPizz.corpuration);
    cout << "Enter the d: ";
    cin >> aPizz.d;
    cout << "Enter the weight: ";
    cin >> aPizz.weight;

    cout << "Cor: " << aPizz.corpuration << endl;
    cout << "d: " << aPizz.d << endl;
    cout << "weight: " << aPizz.weight << endl;

    return 0;
}
