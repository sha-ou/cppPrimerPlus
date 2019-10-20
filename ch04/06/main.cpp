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
    struct CandyBar candys[3] = {
        {"type1", 1.1, 100},
        {"type2", 2.2, 200},
        {"type3", 3.3, 300},
    };

    cout << "Type: " << candys[0].type << endl;
    cout << "Weight: " << candys[0].weight << endl;
    cout << "Cal: " << candys[0].cal << endl;

    cout << "Type: " << candys[1].type << endl;
    cout << "Weight: " << candys[1].weight << endl;
    cout << "Cal: " << candys[1].cal << endl;

    cout << "Type: " << candys[2].type << endl;
    cout << "Weight: " << candys[2].weight << endl;
    cout << "Cal: " << candys[2].cal << endl;

    return 0;
}
