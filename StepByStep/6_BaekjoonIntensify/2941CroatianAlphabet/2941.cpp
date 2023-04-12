#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<string> c = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
    int k;
    string s;

    cin >> s;
    for (int i = 0; i < c.size(); i++)
    {
        while (true)
        {
            k = s.find(c[i]);
            if (k == string::npos)
                break;
            s.replace(k, c[i].length(), "#");
        }
    }
    cout << s.length();

    return 0;
}