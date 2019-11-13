#include "golf.h"
#include <string.h>
#include <iostream>

using namespace std;

void setgolf(golf &g, const char *name, int hc)
{
    strncpy(g.fullname, name, Len-1);
    g.handicap = hc;
}

int setgolf(golf &g)
{
    cout << "Enter fullname: ";
    cin >> g.fullname;

    cout << "Enter handicap: ";
    cin >> g.handicap;

    return 1;
}

void handicap(golf &g, int hc)
{
    g.handicap = hc;
}

void showgolf(const golf &g)
{
    cout << "fullname: " << g.fullname << endl;
    cout << "handicap: " << g.handicap << endl;
}
