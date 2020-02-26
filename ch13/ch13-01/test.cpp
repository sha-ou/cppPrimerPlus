#include <iostream>
using namespace std;
#include "classic.h"

void Bravo(const Cd & disk);

int main()
{
    Cd c1("Beatles", "Captiol", 14, 35.5);
    Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C",
            "Alfred Brendel", "Philips", 2, 57.17);
    Cd * pcd = &c1;

    cout << "Using object directly:" << endl;
    c1.Report();
    c2.Report();

    cout << "Using type cd * pointer to objects:" << endl;
    pcd->Report();
    pcd = &c2;
    pcd->Report();

    cout << "Calling a function with a Cd reference argument:" << endl;
    Bravo(c1);
    Bravo(c2);

    cout << "Testing assignment:" << endl;
    Classic copy;
    copy = c2;
    copy.Report();

    return 0;
}

void Bravo(const Cd & disk)
{
    disk.Report();
}

