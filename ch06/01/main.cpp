#include <iostream>
#include <ctype.h>

using namespace std;

int main(void)
{
    char ch;

    cout << "Enter letters (to stop, enter @): " << endl;

    cin.get(ch);
    while (ch != '@') {
        if (isdigit(ch)) {
            continue;
        } else if (islower(ch)) {
            cout.put(ch-32);
        } else if (isupper(ch)) {
            cout.put(ch+32);
        } else {
            cout << ch;
        }
        cin.get(ch);
    }

    return 0;
}
