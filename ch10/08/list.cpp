#include "list.h"
#include <iostream>

List::List(void)
{
    m_top = 0;
}

int List::isfull(void) const
{
    if (m_top >= LEN) {
        return 1;
    }

    return 0;
}

int List::isempty(void) const
{
    if (m_top < 0) {
        return 1;
    }

    return 0;
}

void List::visit(void (*pf)(Item &))
{
    if (isempty()) {
        return;
    }

    for (int i=0; i<m_top; i++) {
        pf(m_array[i]);
    }
}

int List::add(Item & item)
{
    if (isfull()) {
        return 0;
    }

    m_array[m_top++] = item;
    return 1;
}
