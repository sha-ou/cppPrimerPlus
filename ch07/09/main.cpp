#include <iostream>

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
        cout << "Hobby: ";
        cin.getline(pa[i].hobby, SLEN);
        cin >> pa[i].ooplevel;
    }
}

void display1(student st);
void display2(const student *ps);
void display3(const student pa[], int n);
