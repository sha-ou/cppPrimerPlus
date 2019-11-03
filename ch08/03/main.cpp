#include <iostream>
#include <ctype.h>

using namespace std;

void ToUpper(string & str);

int main(void)
{
    string str;

    while (1) {
        cout << "Enter string (q for quit): ";
        getline(cin, str);
        if (str == "q") {
            cout << "Bye." << endl;
            return 0;
        }
        ToUpper(str);
        cout << str << endl;
    }
    return 0;
}

void ToUpper(string & str)
{
    int len = str.length();
    for (int i=0; i<len; i++) {
        str[i] = toupper(str[i]);
    }
}
