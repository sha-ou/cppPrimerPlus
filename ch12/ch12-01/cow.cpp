#include <iostream>
#include <string.h>
#include "cow.h"

Cow::Cow()
{
    name[0] = '\0';
    hobby = NULL;
    weight = 0;
}

Cow::Cow(const char *nm, const char *ho, double wei)
{
    strncpy(name, nm, 20);
    int len = strlen(ho);
    hobby = (char *)malloc(sizeof(char)*(len + 1));
    strncpy(hobby, ho, len);
    hobby[len] = '\0';
    weight = wei;
}

Cow::Cow(const Cow & c)
{
    strncpy(name, c.name, 20);
    int len = strlen(c.hobby);
    hobby = (char *)malloc(sizeof(char)*(len + 1));
    strncpy(hobby, c.hobby, len);
    hobby[len] = '\0';
    weight = c.weight;
}

Cow::~Cow()
{
    if (!hobby) {
        return;
    }

    free(hobby);
}

Cow & Cow::operator=(const Cow & c)
{
    if (&c == this) {
        return *this;
    }

    strncpy(name, c.name, 20);
    int len = strlen(c.hobby);
    hobby = (char *)malloc(sizeof(char)*(len + 1));
    strncpy(hobby, c.hobby, len);
    hobby[len] = '\0';
    weight = c.weight;

    return *this;
}

void Cow::ShowCow() const
{
    using std::cout;
    using std::endl;

    cout << "My name is " << name << endl;
    cout << "My hobby is " << hobby << endl;
}
