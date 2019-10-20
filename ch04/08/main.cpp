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
    struct Pizz *pstAPizz = new struct Pizz;

    cout << "Enter the corpu: ";
    getline(cin, pstAPizz->corpuration);
    cout << "Enter the d: ";
    cin >> pstAPizz->d;
    cout << "Enter the weight: ";
    cin >> pstAPizz->weight;

    cout << "Cor: " << pstAPizz->corpuration << endl;
    cout << "d: " << pstAPizz->d << endl;
    cout << "weight: " << pstAPizz->weight << endl;

    delete pstAPizz;

    return 0;
}
