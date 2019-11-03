#include <iostream>
#include <string.h>

using namespace std;

template <typename T>
T maxn(T array[], int n);

template <> char * maxn(char *str[], int n);

int main(void)
{
    int arrInt[6] = {1, 2, 3, 4, 5, 6};
    double arrDouble[4] = {1.0, 2.0, 3.0, 4.0};
    char *strs[5] = {
        "Hello",
        "Hello world",
        "How are you?",
        "How old are you?",
        "I'am fine, thanks. And you?",
    };

    cout << "Int Max : " << maxn(arrInt, 6) << endl;
    cout << "Double Max : " << maxn(arrDouble, 4) << endl;
    cout << "String Max : " << maxn(strs, 5) << endl;

    return 0;
}

template <typename T>
T maxn(T array[], int n)
{
    T maxVal = array[0];
    for (int i=0; i<n; i++) {
        if (maxVal < array[i]) {
            maxVal = array[i];
        }
    }
    return maxVal;
}

template <> char * maxn(char *str[], int n)
{
    char *maxLenStr = str[0];
    for (int i=0; i<n; i++) {
        if (strlen(maxLenStr) < strlen(str[i])) {
            maxLenStr = str[i];
        }
    }
    return maxLenStr;
}
