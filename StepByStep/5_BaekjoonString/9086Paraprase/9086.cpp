#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int put;

    cin >> put;
    string s;

    for (int i = 0; i < put; i++)
    {
        cin >> s;
        cout << s[0] << s[s.length() - 1] << endl;
        // cout << str.at(0)
    }

    return 0;
}