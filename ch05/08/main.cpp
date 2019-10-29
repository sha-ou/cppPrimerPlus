#include <iostream>
#include <string.h>

using namespace std;

int main(void)
{
    char word[200] = {0};
    unsigned int cnt = 0;

    cout << "Enter words (to stop, type the word done):" << endl;
    while (1) {
        cin >> word;
        if (strcmp(word, "done") == 0) {
            break;
        }
        cnt++;
    }
    cout << "You entered a total of " << cnt << " words." << endl;

    return 0;
}
