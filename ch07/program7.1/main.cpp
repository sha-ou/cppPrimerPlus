#include <iostream>

void simple(void);

int main(void)
{
    using namespace std;

    cout << "main() will call the simple() function: " << endl;
    simple();
    cout << "main() is finished with the simple() function: " << endl;

    return 0;
}

void simple(void)
{
    using namespace std;

    cout << "I'am but a simple function." << endl;
}
