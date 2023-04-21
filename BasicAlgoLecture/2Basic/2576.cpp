#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num;
    int total = 0;
    int max = 100;

    for (int i = 0; i < 7; i++)
    {
        cin >> num;
        if (num % 2 != 0)
        {
            total += num;
            if (max > num)
                max = num;
        }
    }

    if (total == 0)
    {
        cout << -1;
    }
    else
    {
        cout << total << '\n';
        cout << max << endl;
    }

    return 0;
}