#include <iostream>

using namespace std;

int main(void)
{
    char firstName[20];
    char lastName[20];
    int age = 0;
    char grade;

    cout << "What is your first name? ";
    cin.getline(firstName, 20);

    cout << "What is your last name? ";
    cin.getline(lastName, 20);

    cout << "What letter grade do you deserve? ";
    grade = cin.get()+1;
    cin.get();

    cout << "What is your age? ";
    cin >> age;

    cout << "Name: " << lastName << ", " << firstName << endl;
    cout << "Grage: " << grade << endl;
    cout << "Age: " << age << endl;

    return 0;
}
