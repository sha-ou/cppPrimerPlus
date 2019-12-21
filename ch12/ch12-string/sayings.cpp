#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "string.h"

const int ArSize = 10;
const int MaxLen = 81;

int main(void)
{
    using std::cout;
    using std::cin;
    using std::endl;

    String name;
    cout << "Hi, what's your name?" << endl;
    cout << ">> ";
    cin >> name;

    cout << name << ", please enter up to " << ArSize
        << " short sayings <empty line to quit>: " << endl;
    String sayings[ArSize];
    char temp[MaxLen];
    int i;
    for (i=0; i<ArSize; i++) {
        cout << i+1 << ": ";
        cin.get(temp, MaxLen);
        while (cin && cin.get()!='\n');
        if (!cin || temp[0] == '\0') {
            break;
        } else {
            sayings[i] = temp;
        }
    }

    int total = i;
    if (total > 0) {
        cout << "Here are your sayings: " << endl;
        for (i=0; i<total; i++) {
            cout << sayings[i] << endl;
        }

        String *shortest = &sayings[0];
        String *first = &sayings[0];
        for (i=1; i<total; i++) {
            if (sayings[i].length() < shortest->length()) {
                shortest = &sayings[i];
            }
            if (*first < sayings[i]) {
                first = &sayings[i];
            }
        }

        cout << "Shortest saying: " << endl << *shortest << endl;
        cout << "First alphabetically: " << endl << *first << endl;

        srand(time(0));
        int choice = rand() % total;
        String *favorite = new String(sayings[choice]);
        cout << "My favorite saying: " << endl << *favorite << endl;
        cout << "This program used " << String::HowMany() << " String objects. Bye." << endl;
    } else {
        cout << "No Input! Bye." << endl;
    }

    return 0;
}
