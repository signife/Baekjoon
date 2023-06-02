#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v;
    vector<int> s;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }

    // for (const int num : v)
    // {
    //     cout << num;
    // }
    for (int i = n - 1; i >= 0; i--)
    {
        if (i == 0)
        {
            s.push_back(0);
        }
        else
        {
            for (int pos = 1; pos < n - 1; pos++)
            {
                if (i - 1 != 0 && v[i - pos] > v[i])
                {
                    s.push_back(i + 1 - pos);
                    break;
                }
            }
        }
    }

    reverse(s.begin(), s.end());
    cout << 0 << ' ';
    for (const int num : s)
    {
        cout << num << ' ';
    }

    return 0;
}