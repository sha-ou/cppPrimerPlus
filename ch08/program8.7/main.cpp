#include <iostream>
#include <string>

using namespace std;

string version1(const string & s1, const string & s2);
const string & version2(string & s1, const string & s2);
const string & version3(string & s1, const string & s2);
int main(void)
{
    string input;
    string copy;
    string result;

    cout << "Enter a string: ";
    getline(cin, input);
    copy = input;
    cout << "Input: " << input << " ADDR: " << &input << endl;

    cout << endl;
    result = version1(input, "***");
    // cout << "Your string enhanced: " << result << endl;
    // cout << "Your original string: " << input << endl;

    cout << endl;
    result = version2(input, "###");
    // cout << "Your string enhanced: " << result << endl;
    // cout << "Your original string: " << input << endl;

    cout << endl;
    cout << "Resetting original string" << endl;
    input = copy;
    result = version3(input, "@@@");
    // cout << "Your string enhanced: " << result << endl;
    // cout << "Your original string: " << input << endl;

    return 0;
}

string version1(const string & s1, const string & s2)
{
    string temp;

    temp = s2 + s1 + s2;

    cout << "s1 at " << &s1 << " s2 at " << &s2 << endl;
    return temp;
}

const string & version2(string & s1, const string & s2)
{
    s1 = s2 + s1 + s2;
    cout << "s1 at " << &s1 << " s2 at " << &s2 << endl;
    return s1;
}

const string & version3(string & s1, const string & s2)
{
    string temp;

    temp = s2 + s1 + s2;
    cout << "s1 at " << &s1 << " s2 at " << &s2 << endl;
    return temp;
}
