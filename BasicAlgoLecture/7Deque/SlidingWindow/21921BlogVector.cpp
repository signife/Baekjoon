#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    vector<int> v;
    for (auto &num : v)
    {
        cin >> num;
        v.push_back(num);
    }
    int curValue = 0;
    int maxValue = 0;
    int maxCount = 0;

    for (int i = 0; i < n - x + 1; i++)
    {

        if (i == 0)
        {
            for (int j = 0; j < x; j++)
                curValue += v[j];

            maxValue = curValue;
            maxCount = 1;
        }
        else
        {
            curValue = curValue - v[i - 1] + v[i + x - 1];
            if (curValue == maxValue)
            {
                maxCount += 1;
            }
            else if (curValue > maxValue)
            {
                maxValue = curValue;
                maxCount = 1;
            }
        }
        cout << maxValue << '\n';
        cout << maxCount << '\n';
    }

    return 0;
}