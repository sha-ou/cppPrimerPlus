#include <iostream>
#include <string.h>

using namespace std;

int main(void)
{
    char firstName[20];
    cout << "Enter your first name: ";
    cin.getline(firstName, 20);

    char lastName[20];
    cout << "Enter your last name: ";
    cin.getline(lastName, 20);

    cout << "Here's the information in a single string: " << lastName << ", ";
    cout << firstName << endl;

    return 0;
}
