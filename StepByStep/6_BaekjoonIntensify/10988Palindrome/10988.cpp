#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    getline(cin, s);

    string temp;
    temp = s;
    reverse(s.begin(), s.end());

    if (temp == s)
    {
        cout << 1;
    }
    else
        cout << 0;

    return 0;
}