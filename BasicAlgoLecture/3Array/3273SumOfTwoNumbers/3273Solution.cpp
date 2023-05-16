#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> a(20000001, 0);
    int n, t, x, cnt = 0;

    cin >> n; // repeat
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        a[t] = 1;
    }

    cin >> x;
    for (int i = 1; i < (x + 1) / 2; i++)
    {
        if (a[i] == 1 && a[x - i] == 1)
            cnt++;
    }
    cout << cnt;
    return 0;
}