#include <iostream>

using namespace std;

template <typename T>
void ShowArray(T arr[], int n);

template <typename T>
void ShowArray(T *arr[], int n);

template <typename T>
T SumArray(T arr[], int n);

template <typename T>
T SumArray(T *arr[], int n);

struct debts {
    char name[50];
    double amount;
};

int main(void)
{
    int things[6] = {13, 31, 103, 301, 310, 130};
    struct debts mr_E[3] = {
        {"Ima Wolfe", 2400.0},
        {"Ura Foxe", 1300.0},
        {"Iby Stout", 1800.0}
    };
    double *pd[3];

    for (int i=0; i<3; i++) {
        pd[i] = &mr_E[i].amount;
    }

    cout << "Listing Mr. E's debts: " << endl;
    ShowArray(things, 6);
    cout << "Sum : " << SumArray(things, 6) << endl;
    cout << "Listing Mr. E's debts: " << endl;
    ShowArray(pd, 3);
    cout << "Sum : " << SumArray(pd, 3) << endl;

    return 0;
}

template <typename T>
T SumArray(T arr[], int n)
{
    T sum = 0;
    for (int i=0; i<n; i++) {
        sum += arr[i];
    }
    return sum;
}

template <typename T>
T SumArray(T *arr[], int n)
{
    T sum = 0;
    for (int i=0; i<n; i++) {
        sum += *arr[i];
    }
    return sum;
}

template <typename T>
void ShowArray(T arr[], int n)
{
    cout << "template A" << endl;
    for (int i=0; i<n; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

template <typename T>
void ShowArray(T *arr[], int n)
{
    cout << "template B" << endl;
    for (int i=0; i<n; i++) {
        cout << *arr[i] << ' ';
    }
    cout << endl;
}
