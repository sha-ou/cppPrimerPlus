#include <iostream>
#include <string.h>
#include "cd.h"

Cd::Cd()
{
    performers[0] = '\0';
    label[0] = '\0';
    selections = 0;
    playtime = 0.0;
}

Cd::Cd(char * perf, char * lab, int sel, double time)
{
    strncpy(performers, perf, 49);
    performers[49] = '\0';
    strncpy(label, lab, 19);
    label[19] = '\0';
    selections = sel;
    playtime = time;
}

Cd::Cd(const Cd & d)
{
    strcpy(performers, d.performers);
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
}

Cd::~Cd()
{
}

void Cd::Report() const
{
    using std::cout;
    using std::endl;

    cout << "Performers: " << performers << endl;
    cout << "Label: " << label << endl;
    cout << "Selections: " << selections << endl;
    cout << "PlayTime: " << playtime << endl;
}

Cd & Cd::operator=(const Cd & d)
{
    if (this == &d) {
        return *this;
    }

    strcpy(performers, d.performers);
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
    return *this;
}












