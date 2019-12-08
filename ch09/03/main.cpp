#include <iostream>
#include <string.h>

struct chaff {
    char dross[20];
    int slag;
};

int main(void)
{
    using namespace std;
    struct chaff buff[2];

    struct chaff *tmp = new struct chaff;
    struct chaff *buffpoint = new (buff) struct chaff [2];

    cout << "Enter dross1 : " << endl;
    cin.getline(tmp->dross, 20);
    cout << "Enter slag1 : " << endl;
    cin >> tmp->slag;
    strncpy(buffpoint[0].dross, tmp->dross, 20);
    buffpoint[0].slag = tmp->slag;

    cin.get();
    cout << "Enter dross2 : " << endl;
    cin.getline(tmp->dross, 20);
    cout << "Enter slag2 : " << endl;
    cin >> tmp->slag;
    strncpy(buffpoint[1].dross, tmp->dross, 20);
    buffpoint[1].slag = tmp->slag;

    for (int i=0; i<2; i++) {
        cout << "chaff " << i << ": " << endl;
        cout << "    dross = " <<  buffpoint[i].dross << endl;
        cout << "    slag = " << buffpoint[i].slag << endl;
    }

    delete tmp;
    return 0;
}
