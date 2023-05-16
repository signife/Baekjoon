#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> n(2000001);
    for (auto &c : n)
    {
        c = -1;
    }

    int repeat;

    cin >> repeat;
    while (repeat--)
    {
        string s;
        cin >> s;
        for (int i = 0; i < s.length(); i++)
        {
            int idx = stoi(s);
            n[idx] = 1;
        }
    }

    int x;
    int cnt = 0;
    cin >> x;

    for (int i = 0; i < x; i++)
    {
        if (n[i] == 1 && n[x - i] == 1)
        {

            cnt++;
            n[x - i] = 0;
        }
    }

    cout << cnt;

    return 0;
}