#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    int cnt = 0;
    int sum = 0;

    cin >> n >> m;

    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            sum += v[j];

            if (sum == m)
            {
                cnt++;
                sum = 0;
                break;
            }
        }
        if (sum != 0)
            sum = 0;
    }

    cout << cnt;

    return 0;
}