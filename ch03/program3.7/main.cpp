#include <iostream>

using namespace std;

int main(void)
{
    cout << "\aOperation \"HyperHype\" is now activated!" << endl;
    cout << "Enter your agent code:________\b\b\b\b\b\b\b\b";

    long code;
    cin >> code;

    cout << "\aYou entered " << code << " ..." << endl;
    cout << "\aCode verified! proceed with plan z3!" << endl;

    return 0;
}
