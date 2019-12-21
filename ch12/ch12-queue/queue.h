#ifndef __QUEUE_H__
#define __QUEUE_H__

class Customer {
    private:
        long m_arrive;
        int m_processtime;
    public:
        Customer(void) {
            m_arrive = m_processtime = 0;
        }
        void set(long when);
        long when(void) const {
            return m_arrive;
        }
        int ptime(void) const {
            return m_processtime;
        }
};

typedef Customer Item;

class Queue {
    private:
        struct Node {Item item; struct Node *next;};
        enum {QSIZE = 10};
        Node *m_front;
        Node *m_rear;
        int m_items;
        const int m_qsize;
        Queue(const Queue & q) : m_qsize(0) {}
        Queue & operator=(const Queue & q) {return *this}
    public:
        Queue(int qs = QSIZE);
        ~Queue(void);
        bool isempty(void) const;
        bool isfull(void) const;
        int queuecount(void) const;
        bool enqueue(const Item & item);
        bool dequeue(Item & item);
};

#endif
