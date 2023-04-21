#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num;
    vector<int> c(3);

    for (auto &num : c)
    {
        cin >> num;
    }

    sort(c.begin(), c.end());

    for (auto &num : c)
    {
        cout << num << ' ';
    }
    return 0;
}