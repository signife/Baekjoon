#include <iostream>
#include <string>
using namespace std;

string change(string &a);
int main()
{
    string a, b;
    cin >> a >> b;
    change(a);
    change(b);

    if (a > b)
        cout << a;
    else if (a < b)
        cout << b;
    else
        cout << "same";

    return 0;
}

string change(string &a)
{
    string temp = a;
    for (int i = 0; i < a.length(); i++)
    {
        a[i] = temp[a.length() - i - 1];
    }

    return a;
}