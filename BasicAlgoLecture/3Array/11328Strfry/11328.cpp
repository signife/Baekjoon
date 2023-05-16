#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    // unordered_map<char, int> f1, f2;

    while (n--)
    {
        string s, ss;
        cin >> s >> ss;

        unordered_map<char, int> f1, f2; // 여기다 넣어야 초기화
        for (char c : s)
        {
            f1[c]++;
        }
        for (char c : ss)
        {
            f2[c]++;
        }
        sort(s.begin(), s.end());
        sort(ss.begin(), ss.end());

        if (s == ss)
            // if (s.length() == ss.length() && f1 == f2)
            cout << "Possible" << '\n';
        else
            cout << "impossible" << '\n';
    }

    return 0;
}