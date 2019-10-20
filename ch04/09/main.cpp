#include <iostream>
#include <string>

using namespace std;

struct CandyBar {
    string type;
    float weight;
    int cal;
};

int main(void)
{
    struct CandyBar *pstCandys = new struct CandyBar [3];
    pstCandys[0] = {"type1", 1.1, 100};
    pstCandys[1] = {"type2", 2.2, 200};
    pstCandys[2] = {"type3", 3.3, 300};

    cout << "Type: " << pstCandys[0].type << endl;
    cout << "Weight: " << pstCandys[0].weight << endl;
    cout << "Cal: " << pstCandys[0].cal << endl;

    cout << "Type: " << pstCandys[1].type << endl;
    cout << "Weight: " << pstCandys[1].weight << endl;
    cout << "Cal: " << pstCandys[1].cal << endl;

    cout << "Type: " << pstCandys[2].type << endl;
    cout << "Weight: " << pstCandys[2].weight << endl;
    cout << "Cal: " << pstCandys[2].cal << endl;

    delete [] pstCandys;

    return 0;
}
