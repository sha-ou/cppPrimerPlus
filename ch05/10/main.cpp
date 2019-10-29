#include <iostream>

using namespace std;

void PutPoint(unsigned int cnt);
void PutStar(unsigned int cnt);

int main(void)
{
    unsigned int rows;
    cout << "Enter number of rows: ";
    cin >> rows;

    for (int i=0; i<rows; i++) {
        PutPoint(rows-i-1);
        PutStar(i+1);
        cout << endl;
    }
    return 0;
}

void PutPoint(unsigned int cnt)
{
    for (int i=0; i<cnt; i++) {
        cout << ".";
    }
}

void PutStar(unsigned int cnt)
{
    for (int i=0; i<cnt; i++) {
        cout << "*";
    }
}
