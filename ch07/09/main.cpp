#include <iostream>
#include <string.h>

using namespace std;

const int SLEN = 30;
struct student {
    char fullname[SLEN];
    char hobby[SLEN];
    int ooplevel;
};

int getinfo(student pa[], int n);
void display1(student st);
void display2(const student *ps);
void display3(const student pa[], int n);

int main(void)
{
    cout << "Enter class size: ";
    int class_size;
    cin >> class_size;

    while (cin.get() != '\n') {
        continue;
    }

    student * ptr_stu = new student [class_size];
    int entered = getinfo(ptr_stu, class_size);
    for (int i=0; i<entered; i++){
        display1(ptr_stu[i]);
        display2(&ptr_stu[i]);
    }
    display3(ptr_stu, entered);
    delete [] ptr_stu;
    cout << "Done" << endl;

    return 0;
}

int getinfo(student pa[], int n)
{
    cout << "Enter students' information (total size ";
    cout << n << "):" << endl;

    int i = 0;
    char name[SLEN] = {0};
    char hobby[SLEN] = {0};

    for (i=0; i<n; i++) {
        cout << "Name: ";
        cin.getline(pa[i].fullname, SLEN);
        if (strcmp(pa[i].fullname, " ") == 0) {
            break;
        }
        cout << "Hobby: ";
        cin.getline(pa[i].hobby, SLEN);
        cout << "OOPLevel: ";
        cin >> pa[i].ooplevel;
    }

    return i;
}

void display1(student st)
{
    cout << __FUNCTION__ << endl;
    cout << "Full Name: " << st.fullname << endl;
    cout << "Hobby: " << st.hobby << endl;
    cout << "OOPLevel: " << st.ooplevel << endl;
}

void display2(const student *ps)
{
    cout << __FUNCTION__ << endl;
    cout << "Full Name: " << ps->fullname << endl;
    cout << "Hobby: " << ps->hobby << endl;
    cout << "OOPLevel: " << ps->ooplevel << endl;
}

void display3(const student pa[], int n)
{
    cout << __FUNCTION__ << endl;
    for (int i=0; i<n; i++) {
        display2(&pa[i]);
    }
}
