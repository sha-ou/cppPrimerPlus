#include <iostream>

using namespace std;

int FillArray(double *paArr, int size);
void ShowArray(double *paArr, int size);
void ReverseArray(double *paArr, int size);

int main(void)
{
    const int SIZE = 10;
    double array[SIZE] = {0.0};
    int len;

    len = FillArray(array, SIZE);
    ShowArray(array, len);
    ReverseArray(array, len);
    ShowArray(array, len);
    ReverseArray(array+1, len-2);
    ShowArray(array, len);

    return 0;
}

int FillArray(double *paArr, int size)
{
    int i = 0;
    for (i=0; i<size; i++) {
        cout << "Enter num #" << i+1 << " : ";
        if (!(cin>>paArr[i])) {
            return i;
        }
    }
    return i;
}

void ShowArray(double *paArr, int size)
{
    for (int i=0; i<size; i++) {
        cout << paArr[i] << " ";
    }
    cout << endl;
}

void ReverseArray(double *paArr, int size)
{
    int half = size/2;
    double temp;

    for (int i=0; i<half; i++) {
        temp = paArr[i];
        paArr[i] = paArr[size-1-i];
        paArr[size-1-i] = temp;
    }
}
