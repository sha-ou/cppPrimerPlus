#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string firstName;
    cout << "Enter your first name: ";
    getline(cin, firstName);

    string lastName;
    cout << "Enter your last name: ";
    getline(cin, lastName);

    cout << "Here's the information in a single string: ";
    cout << lastName << ", " << firstName << endl;

    return 0;
}
