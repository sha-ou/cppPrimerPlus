#include <iostream>

using namespace std;

struct CandyBar {
    string name;
    double weight;
    int cal;
};

void ShowCandy(const struct CandyBar &candyBar);
void SetCandy(struct CandyBar &candyBar, char *name="Millennium Munch",
              double weight=2.85, int cal=350);

int main(void)
{
    struct CandyBar candyBar;
    SetCandy(candyBar);
    ShowCandy(candyBar);
    return 0;
}

void ShowCandy(const struct CandyBar &candyBar)
{
    cout << "Call " << __FUNCTION__ << endl;
    cout << "Name: " << candyBar.name << endl;
    cout << "Weight: " << candyBar.weight << endl;
    cout << "Cal: " << candyBar.cal << endl;
}

void SetCandy(struct CandyBar &candyBar, char *name, double weight, int cal)
{
    cout << "Call " << __FUNCTION__ << endl;
    candyBar.name = name;
    candyBar.weight = weight;
    candyBar.cal = cal;
}
