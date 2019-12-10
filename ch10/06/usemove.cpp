#include "move.h"
#include <iostream>

int main(void)
{
    Move move1 = Move(0, 0);
    Move move2 = Move(1, 1);
    Move move3 = move1.add(move2);

    move1.showmove();
    move2.showmove();
    move3.showmove();

    return 0;
}
