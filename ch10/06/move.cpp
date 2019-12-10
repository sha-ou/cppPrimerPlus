#include "move.h"
#include <iostream>

Move::Move(double a, double b)
{
    x = a;
    y = b;
}

void Move::showmove(void) const
{
    using namespace std;

    cout << "x: " << x << "y: " << y << endl;

    return;
}

Move Move::add(const Move & m) const
{
    double newx = x + m.x;
    double newy = y + m.y;

    return Move(newx, newy);
}

void Move::reset(double a, double b)
{
    x = a;
    y = b;
}
