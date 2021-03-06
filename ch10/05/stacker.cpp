#include "stack.h"
#include <iostream>
#include <ctype.h>

int main(void)
{
    using namespace std;

    Stack st;
    char ch;
    Item po;
    double total = 0.0;

    cout << "Please enter A to add a purchase order, " << endl;
    cout << "P to process a PO, or Q to quit." << endl;

    while (cin >> ch && toupper(ch) != 'Q') {
        while (cin.get() != '\n');

        if (!isalpha(ch)) {
            cout << '\a';
            continue;
        }

        switch (ch) {
            case 'A':
            case 'a':
                cout << "Enter a PO number to add: " << endl;
                cout << "\tEnter fullname: ";
                cin.getline(po.fullname, 35);
                cout << "\tEnter payment: ";
                cin >> po.payment;
                while (cin.get() != '\n');

                if (st.isfull()) {
                    cout << "Stack already full" << endl;
                } else {
                    st.push(po);
                }
                break;

            case 'P':
            case 'p':
                if (st.isempty()) {
                    cout << "Stack already empty" << endl;
                } else {
                    st.pop(po);
                    total += po.payment;
                    cout << "Process PO:" << endl;
                    cout << "\tFullname: " << po.fullname << endl;
                    cout << "\tPayment: " << po.payment << endl;
                    cout << "\tTotal: " << total << endl;
                }
                break;
        }

        cout << "Please enter A to add a purchase order, " << endl;
        cout << "P to process a PO, or Q to quit." << endl;
    }

    cout << "Bye" << endl;

    return 0;
}
