#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    unsigned int cnt = 0;
    string word;

    cout << "Enter words (to stop, type in the word done):" << endl;
    while (1) {
        cin >> noskipws >> word;
        cout << word;
    }

    return 0;
}
