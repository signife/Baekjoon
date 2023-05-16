#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> n(10);
    for (auto &c : n)
    {
        c = 0;
    }

    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        int idx = s[i] - 48;
        n[idx] += 1;
    }

    if (0 == ((n[9] + n[6]) % 2))
    {
        n[9] = (n[9] + n[6]) / 2;
    }
    else
    {
        n[9] = ((n[9] + n[6]) / 2) + 1;
    }

    n[6] = 0;

    int max = -1;
    for (int i = 0; i < n.size(); i++)
    {
        if (max < n[i])
        {
            max = n[i];
        }
    }

    cout << max;

    // for (auto &c : n)
    // {
    //     cout << c;
    // }

    return 0;
}