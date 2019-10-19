#include <iostream>

using namespace std;

int AgeMounths(int age);
int main(void)
{
    int age;

    cout << "Enter your age: ";
    cin >> age;
    cout << "Mounths: " << AgeMounths(age) << endl;
    return 0;
}

int AgeMounths(int age)
{
    return 12 * age;
}
