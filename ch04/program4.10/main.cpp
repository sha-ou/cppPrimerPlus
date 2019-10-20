#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main(void)
{
    char charr[20];
    string str;

    cout << "Length of string in charr before input: "
         << strlen(charr) << endl;
    cout << "Length of string in str before input: "
         << str.size() << endl;

    cout << "Enter a line of text:" << endl;
    cin.getline(charr, 20);
    cout << "You entered: " << charr << endl;

    cout << "Enter a line of text:" << endl;
    getline(cin, str);
    cout << "Your entered: " << str << endl;

    return 0;
}
