// 각 수는 한번만 등장
#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> s;

    int n;
    cin >> n;
    vector<bool> bumzi(n, false);
    vector<int> mol(n);

    while (n--)
    {
        int k;
        cin >> k;
        bool found = false;
        for (int j = 1; j <= k; j++)
        {
            if (!bumzi[j - 1])
            {
                s.push(j);
                cout << "+\n";
                bumzi[j - 1] = true;
                found = true;
            }
        }
        if (!found || s.top() != k)
        {
            cout << "NO\n";
            return 0;
        }
        else if (k == s.top())
        {
            mol.push_back(s.top());
            s.pop();
            cout << "-\n";
        }
    }

    return 0;
}