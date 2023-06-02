#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<int> s;

    int n;
    cin >> n;
    while (n--)
    {
        string c;
        cin >> c;
        if (c == "push")
        {
            int t;
            cin >> t;
            s.push(t);
        }
        else if (c == "pop")
        {
            if (s.empty())
                cout << -1 << '\n';
            else
            {
                cout << s.front() << '\n';
                s.pop();
            }
        }
        else if (c == "size")
            cout << s.size() << '\n';
        else if (c == "empty")
            cout << (int)s.empty() << '\n';
        else if (c == "front")
        {
            if (s.empty())
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << s.front() << '\n';
            }
        }
        else
        {
            if (s.empty())
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << s.back() << '\n';
            }
        }
    }

    return 0;
}
