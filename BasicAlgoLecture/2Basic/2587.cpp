#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num;
    vector<int> c(5);

    for (auto &num : c)
    {
        cin >> num;
    }

    sort(c.begin(), c.end());

    cout << accumulate(c.begin(), c.end(), 0.0) / c.size() << endl;
    cout << c[2] << endl;

    return 0;
}