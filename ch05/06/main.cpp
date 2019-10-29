#include <iostream>

using namespace std;

int main(void)
{
    const int monthInYear = 12;
    const char *months[monthInYear] = {
        "Jan.", "Feb.", "Mar.", "Apr.", "May.", "June.",
        "July.", "Aug.", "Sept.", "Oct.", "Nov.", "Dec.",
    };
    unsigned int nums[3][monthInYear] = {0};

    for (int year=0; year<3; year++) {
        cout << "Year: " << year+1 << endl;
        for (int month=0; month<monthInYear; month++) {
            cout << "Input " << months[month] << " : ";
            cin >> nums[year][month];
        }
    }

    unsigned int sums[3] = {0};
    for (int year=0; year<3; year++) {
        for (int month=0; month<monthInYear; month++) {
            sums[year] += nums[year][month];
        }
        cout << "Year " << year+1 << " : " << sums[year] << endl;
    }

    cout << "All : " << sums[0] + sums[1] + sums[2] << endl;

    return 0;
}
