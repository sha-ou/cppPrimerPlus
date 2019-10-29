#include <iostream>

using namespace std;

int main(void)
{
    const int monthInYear = 12;
    const char *months[monthInYear] = {
        "Jan.", "Feb.", "Mar.", "Apr.", "May.", "June.",
        "July.", "Aug.", "Sept.", "Oct.", "Nov.", "Dec.",
    };
    unsigned int nums[monthInYear] = {0};

    for (int i=0; i<monthInYear; i++) {
        cout << "Input " << months[i] << " : ";
        cin >> nums[i];
    }

    unsigned int sum = 0;
    for (int i=0; i<monthInYear; i++) {
        sum += nums[i];
    }

    cout << "All : " << sum << endl;

    return 0;
}
