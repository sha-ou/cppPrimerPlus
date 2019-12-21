#include <iostream>
#include "stringbad.h"

using std::cout;

void callme1(Stringbad &);
void callme2(Stringbad);

int main(void)
{
    using std::endl;
    {
        cout << "Starting an inner block." << endl;
        Stringbad headline1("Celery Stalks at Midnight");
        Stringbad headline2("Lettuce Prey");
        Stringbad sports("Spinach Leaves Bowl for Dollars");

        cout << "headline1: " << headline1 << endl;
        cout << "headline2: " << headline2 << endl;
        cout << "sports: " << sports << endl;

        callme1(headline1);
        cout << "headline1: " << headline1 << endl;
        callme2(headline2);
        cout << "headline2: " << headline2 << endl;

        cout << "Initialize one object to another: " << endl;
        Stringbad sailor = sports;
        cout << "sailor: " << sailor << endl;

        cout << "Assign one object to another: " << endl;
        Stringbad knot;
        knot = headline1;
        cout << "knot: " << knot << endl;

        cout << "Exiting the block" << endl;
    }
    return 0;
}

void callme1(Stringbad & rsb)
{
    cout << "String passed by refernce: " << std::endl;
    cout << "        \"" << rsb << "\"" << std::endl;
}

void callme2(Stringbad sb)
{
    cout << "String passwd by value: " << std::endl;
    cout << "        \"" << sb << "\"" << std::endl;
}
