#include <iostream>

const int ArSize = 10;

void strcount(std::string str);

int main(void)
{
    using namespace std;

    // char next;
    string input;

    cout << "Enter a line: " << endl;
    getline(cin, input);

    while (cin) {
        // cin.get(next);
        // while (next!='\n') {
            // cin.get(next);
        // }
        if (!input.length()) {
            break;
        }
        strcount(input);
        cout << "Enter next line (empty line to quit): " << endl;
        getline(cin, input);
    }

    cout << "Bye" << endl;

    return 0;
}

void strcount(std::string str)
{
    using namespace std;

    static int total = 0;
    int count = 0;

    cout << "\"" << str << "\" contains ";
    count = str.length();
    total += count;

    cout << count << " characters" << endl;
    cout << total << " characters total" << endl;
}
