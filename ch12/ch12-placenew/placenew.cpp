#include <iostream>
#include <string>
#include <new>

using namespace std;
const int BUF = 512;

class Justtesting {
    private:
        string m_words;
        int m_num;
    public:
        Justtesting(const string & s = "Juest Testing", int n = 0) {
            m_words = s;
            m_num = n;
            cout << m_words << " constructed" << endl;
        }
        ~Justtesting(void) {
            cout << m_words << " destroyed" << endl;
        }
        void show(void) const {
            cout << m_words << ", " << m_num << endl;
        }
};

int main(void)
{
    char *buff = new char[BUF];

    Justtesting *pc1, *pc2;

    pc1 = new (buff) Justtesting;
    pc2 = new Justtesting("Heap1", 20);

    cout << "Memory block address:" << endl;
    cout << "\tbuff: " << (void *)buff <<endl;
    cout << "\tpc1 : " << (void *)pc1 << endl;
    cout << "\tpc2 : " << (void *)pc2 << endl;

    cout << "Memory contents:" << endl;
    cout << "\tpc1 : ";
    pc1->show();
    cout << "\tpc2 : ";
    pc2->show();

    Justtesting *pc3, *pc4;
    pc3 = new (buff+sizeof(Justtesting)) Justtesting("Bad idea", 6);
    pc4 = new Justtesting("Heap2", 10);

    cout << "Memory block address:" << endl;
    cout << "\tbuff: " << (void *)buff <<endl;
    cout << "\tpc3 : " << (void *)pc3 << endl;
    cout << "\tpc4 : " << (void *)pc4 << endl;

    cout << "Memory contents:" << endl;
    cout << "\tpc3 : ";
    pc3->show();
    cout << "\tpc4 : ";
    pc4->show();

    cout << "After new pc3" << endl;
    cout << "Memory contents:" << endl;
    cout << "\tpc1 : ";
    pc1->show();
    cout << "\tpc2 : ";
    pc2->show();

    delete pc2;
    delete pc4;
    pc1->~Justtesting();
    pc3->~Justtesting();
    delete [] buff;

    cout << "Done" << endl;

    return 0;
}
