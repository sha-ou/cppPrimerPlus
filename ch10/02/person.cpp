#include "person.h"
#include <iostream>
#include <string.h>

Person::Person(const std::string & ln, const char * fn)
{
    lname = ln;
    strncpy(fname, fn, LIMIT);
}

void Person::show(void) const
{
    using namespace std;

    cout << "My name is " << fname << "|" << lname << endl;

    return;
}

void Person::formalShow(void) const
{
    using namespace std;

    cout << "My last  name is: " << lname << endl;
    cout << "My first name is: " << fname << endl;

    return;
}
