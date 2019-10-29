#include <iostream>

using namespace std;

const int Seasons = 4;
const char *seasonNames[Seasons] = {
    "Spring", "Summer", "Fall", "Winter"
};

struct expenses {
    double expensesArr[Seasons];
};

void Fill(struct expenses *pstExp);
void Show(struct expenses expens);

int main(void)
{
    struct expenses expens;
    Fill(&expens);
    Show(expens);
    return 0;
}

void Fill(struct expenses *pstExp)
{
    for (int i=0; i<Seasons; i++) {
        cout << "Enter " << seasonNames[i] << " expenses: ";
        cin >> pstExp->expensesArr[i];
    }
}

void Show(struct expenses expens)
{
    double total = 0.0;
    cout << "\nEXPENSES\n";
    for (int i=0; i<Seasons; i++) {
        cout << seasonNames[i] << " : $" << expens.expensesArr[i] << endl;
        total += expens.expensesArr[i];
    }
    cout << "Total Expenses: $" << total << endl;
}
