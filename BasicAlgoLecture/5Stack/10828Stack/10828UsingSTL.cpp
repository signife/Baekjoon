#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    stack<int> s;

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
                cout << -1 << endl;
            else
            {
                cout << s.top() << endl;
                s.pop();
            }
        }
        else if (c == "size")
            cout << s.size() << endl;
        else if (c == "empty")
            cout << (int)s.empty() << endl;
        else
        {
            if (s.empty())
                cout << -1 << endl;
            else
                cout << s.top() << endl;
        }
    }

    return 0;
}
