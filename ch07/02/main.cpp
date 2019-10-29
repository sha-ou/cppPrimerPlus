#include <iostream>

using namespace std;

void input(double *pdArray, int & size);
void show(double *pdArray, int size);
double avg(double *pdArray, int size);

int main(void)
{
    double array[10] = {0.0};
    int size = 0;
    input(array, size);
    show(array, size);
    cout << "Avg: " << avg(array, size) << endl;
    return 0;
}

void input(double *pdArray, int & size)
{
    int count = 0;
    cout << "Enter num #" << count+1 << " : ";
    for (count=1; count<10 && cin >> pdArray[count-1]; count++) {
        cout << "Enter num #" << count << " : ";
    }
    size = count;
}

void show(double *pdArray, int size)
{
    for (int i=0; i<size; i++) {
        cout << pdArray[i] << " ";
    }
    cout << endl;
}

double avg(double *pdArray, int size)
{
    double sum = 0.0;
    for (int i=0; i<size; i++) {
        sum += pdArray[i];
    }
    return sum/size;
}
