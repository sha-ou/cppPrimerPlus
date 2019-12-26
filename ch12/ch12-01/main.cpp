#include <iostream>
#include "cow.h"

void call(Cow c);

int main(void)
{
    using namespace std;
    Cow cow1 = Cow("cow1", "I am cow1", 20);
    Cow cow2;
    cow2 = cow1;
    cow1.ShowCow();
    cow2.ShowCow();
    call(cow2);
    return 0;
}

void call(Cow c)
{
    c.ShowCow();
}
