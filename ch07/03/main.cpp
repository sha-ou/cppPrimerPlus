#include <iostream>
#include <string.h>

using namespace std;

struct box {
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

void ShowBox(struct box boxparam);
void SetBox(struct box *pstBox);

int main(void)
{
    struct box aBox;
    strncpy(aBox.maker, "China", 40);
    aBox.height = 5.0;
    aBox.width = 5.0;
    aBox.length = 5.0;

    SetBox(&aBox);
    ShowBox(aBox);

    return 0;
}


void ShowBox(struct box boxparam)
{
    cout << "Maker: " << boxparam.maker << endl;
    cout << "Height: " << boxparam.height << endl;
    cout << "Width: " << boxparam.width << endl;
    cout << "Length: " << boxparam.length << endl;
    cout << "Volume: " << boxparam.volume << endl;
}

void SetBox(struct box *pstBox)
{
    pstBox->volume = pstBox->height * pstBox->width * pstBox->length;
}
