#include <iostream>

using namespace std;

const int MAX = 5;

int FillArray(double *pdStart, double *pdStop);
void ShowArray(double *pdStart, double *pdStop);
void RevalArray(double factor, double *pdStart, double *pdStop);

int main(void)
{
    double properties[MAX];
    int size = FillArray(properties, properties+MAX-1);
    ShowArray(properties, properties+MAX-1);

    if (size>0) {
        cout << "Enter revaluation factor: ";
        double factor;
        while (!(cin>>factor)) {
            cin.clear();
            while (cin.get() != '\n') {
                continue;
            }
            cout << "Bad input; Please enter a number: ";
        }
        RevalArray(factor, properties, properties+MAX-1);
        ShowArray(properties, properties+MAX-1);
    }
    cout << "Done" << endl;
    cin.get();
    cin.get();

    return 0;
}

int FillArray(double *pdStart, double *pdStop)
{
    double temp;
    int i;

    for (i=0; pdStart+i<=pdStop; i++) {
        cout << "Enter value #" << (i+1) << " : ";
        cin >> temp;
        if (!cin) {
            cin.clear();
            while (cin.get() != '\n') {
                continue;
            }
            cout << "Bad input; Input process terminated." << endl;
            break;
        } else if (temp<0) {
            break;
        }
        pdStart[i] = temp;
    }
    return i;
}

void ShowArray(double *pdStart, double *pdStop)
{
    for (int i=0; pdStart+i<=pdStop; i++) {
        cout << "Property #" << (i+1) << " : $"
             << pdStart[i] << endl;
    }
}

void RevalArray(double factor, double *pdStart, double *pdStop)
{
    for (int i=0; i+pdStart<=pdStop; i++) {
        pdStart[i] *= factor;
    }
}
