#include <iostream>
#include "tabtenn.h"

void Show(const TableTennisPlayer & rt);

int main(void)
{
    using std::cout;
    using std::endl;

    TableTennisPlayer player1("Tara", "Boomdea", false);
    RatePlayer rplayer1(1140, "Mallory", "Duck", true);

    rplayer1.Name();
    if (rplayer1.HasTable()) {
        cout << ": has a table." << endl;
    } else {
        cout << ": hasn't a table." << endl;
    }

    player1.Name();
    if (player1.HasTable()) {
        cout << ": has a table." << endl;
    } else {
        cout << ": hasn't a table." << endl;
    }

    cout << "Name: ";
    rplayer1.Name();
    cout << "; Rating: " << rplayer1.Rating() << endl;

    RatePlayer rplayer2(1212, player1);
    Show(rplayer2);
    cout << "Name: ";
    rplayer2.Name();
    cout << "; Rating: " << rplayer2.Rating() << endl;

    return 0;
}

void Show(const TableTennisPlayer & rt)
{
    using std::cout;
    using std::endl;

    rt.Name();
    cout << endl << "\tTable: ";
    if (rt.HasTable()) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
