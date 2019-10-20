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
    struct CandyBar snack = {
        "Mocha Munch",
        2.3,
        350
    };

    cout << "Type: " << snack.type << endl;
    cout << "Weight: " << snack.weight << endl;
    cout << "Cal: " << snack.cal << endl;

    return 0;
}
