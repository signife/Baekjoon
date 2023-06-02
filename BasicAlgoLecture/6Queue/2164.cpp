#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (i <= n)
        {
            q.push(i);
        }
    }

    while (q.size() > 1)
    {
        q.pop();
        int temp = q.front();
        q.push(temp);
        q.pop();
    }

    cout << q.front() << endl;

    return 0;
}