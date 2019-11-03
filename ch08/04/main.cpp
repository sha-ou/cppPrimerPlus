#include <iostream>
#include <string.h>

using namespace std;

struct stringy {
    char * str;
    int ct;
};

void set(stringy & str, char *src);
void show(const stringy & str, int cnt=1);
void show(const char *str, int cnt=1);

int main(void)
{
    stringy beany;
    char testing[] = "Reality isn't what it used to be.";

    set(beany, testing);
    show(beany);
    show(beany, 2);
    testing[0] = 'D';
    testing[1] = 'u';
    show(testing);
    show(testing, 3);
    show("Done!");

    return 0;
}

void set(stringy & str, char *src)
{
    char *newstr = new char [strlen(src) + 1];
    str.str = newstr;
    strcpy(str.str, src);
    str.ct = strlen(newstr);
}

void show(const char *str, int cnt)
{
    for (int i=0; i<cnt; i++) {
        cout << str << endl;
    }
}

void show(const stringy & str, int cnt)
{
    for (int i=0; i<cnt; i++) {
        cout << str.str << endl;
    }
}
