#include "queue.h"
#include <stdlib.h>

Queue::Queue(int qs) : m_qsize(qs)
{
    m_front = m_rear = NULL;
    m_items = 0;
}

Queue::~Queue(void)
{
    Node * temp;
    while (m_front != NULL) {
        temp = m_front;
        m_front = m_front->next;
        delete temp;
    }
}

bool Queue::isempty(void) const
{
    return m_items == 0;
}

bool Queue::isfull(void) const
{
    return m_items == m_qsize;
}

int Queue::queuecount(void) const
{
    return m_items;
}

bool Queue::enqueue(const Item & item)
{
    if (isfull()) {
        return false;
    }

    Node *pstNewNode = new Node;
    pstNewNode->item = item;
    pstNewNode->next = NULL;
    m_items++;
    if (m_front) {
        m_rear->next = pstNewNode;
    } else {
        m_front = pstNewNode;
    }
    m_rear = pstNewNode;
    return true;
}

bool Queue::dequeue(Item & item)
{
    if (isempty()) {
        return false;
    }

    item = m_front->item;
    m_items--;
    Node *temp = m_front;
    m_front = m_front->next;
    delete  temp;

    if (m_items==0) {
        m_rear = NULL;
    }
    return true;
}

void Customer::set(long when)
{
    m_processtime = std::rand() % 3 + 1;
    m_arrive = when;
}
