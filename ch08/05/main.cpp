#include <iostream>

using namespace std;

template <typename T>
T max5(T array[]);

int main(void)
{
    int arrInt[5] = {1,2,3,4,5};
    double arrDouble[5] = {1.0, 2.0, 3.0, 4.0, 5.0};

    cout << "Int Max : " << max5(arrInt) << endl;
    cout << "Double Max : " << max5(arrDouble) << endl;

    return 0;
}

template <typename T>
T max5(T array[])
{
    T maxVal = array[0];
    for (int i=0; i<5; i++) {
        if (maxVal < array[i]) {
            maxVal = array[i];
        }
    }
    return maxVal;
}
