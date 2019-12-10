#include "list.h"
#include <iostream>

void visit(Item & item);

int main(void)
{
    List list;

    for (int i=0; i<5; i++) {
        list.add(i);
    }

    list.visit(visit);

    return 0;
}

void visit(Item & item)
{
    using namespace std;

    cout << "Item: " << item << endl;
}
