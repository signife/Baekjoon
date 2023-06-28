#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    deque<int> d;

    while (n--)
    {
        string s;
        cin >> s;

        if (s == "push_front")
        {
            int t;
            cin >> t;
            d.push_front(t);
        }
        else if (s == "push_back")
        {
            int t;
            cin >> t;
            d.push_back(t);
        }
        else if (s == "pop_front")
        {
            if (!d.empty())
            {
                cout << d.front() << '\n';
                d.pop_front();
            }
            else
                cout << -1 << '\n';
        }
        else if (s == "pop_back")
        {
            if (!d.empty())
            {
                cout << d.back() << '\n';
                d.pop_back();
            }
            else
                cout << -1 << '\n';
        }
        else if (s == "size")
        {
            cout << d.size() << '\n';
        }
        else if (s == "empty")
        {
            cout << d.empty() << '\n';
        }
        else if (s == "front")
        {
            if (!d.empty())
                cout << d.front() << '\n';
            else
                cout << -1 << '\n';
        }
        else
        {
            if (!d.empty())
                cout << d.back() << '\n';
            else
                cout << -1 << '\n';
        }
    }

    return 0;
}