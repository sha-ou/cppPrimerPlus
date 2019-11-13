#include <iostream>
#include "golf.h"

using namespace std;

int main(void)
{
    golf aGolf;

    cout << "Set by void setgolf" << endl;
    setgolf(aGolf, "A", 1);
    showgolf(aGolf);

    cout << "Set by int setgolf" << endl;
    setgolf(aGolf);
    showgolf(aGolf);

    return 0;
}
