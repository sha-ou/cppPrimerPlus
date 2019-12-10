#ifndef __LIST_H__
#define __LIST_H__

typedef int Item;

class List {
    private:
        static const int LEN = 5;
        Item m_array[LEN];
        int m_top;
    public:
        List(void);
        int isfull(void) const;
        int isempty(void) const;
        void visit(void (*pf)(Item &));
        int add(Item & item);
};

#endif
