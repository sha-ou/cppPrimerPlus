#include <iostream>

using namespace std;

const int Seasons = 4;
const char *seasonNames[Seasons] = {
    "Spring", "Summer", "Fall", "Winter"
};

void Fill(double *pa);
void Show(const double *pa);

int main(void)
{
    double expenses[Seasons];
    Fill(expenses);
    Show(expenses);
    return 0;
}

void Fill(double *pa)
{
    for (int i=0; i<Seasons; i++) {
        cout << "Enter " << seasonNames[i] << " expenses: ";
        cin >> pa[i];
    }
}

void Show(const double *pa)
{
    double total = 0.0;
    cout << "\nEXPENSES\n";
    for (int i=0; i<Seasons; i++) {
        cout << seasonNames[i] << " : $" << pa[i] << endl;
        total += pa[i];
    }
    cout << "Total Expenses: $" << total << endl;
}
