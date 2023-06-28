// https://ji-musclecode.tistory.com/37
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n, x;
    cin >> n >> x;

    queue<int> q;
    int cnt = 0;
    int sum = 0;

    unordered_map<int, int> number;
    int m = 0;
    while (n--)
    {
        int visit;
        cin >> visit;
        sum += visit;
        q.push(visit);
        cnt++;

        if (cnt >= x)
        {
            m = max(m, sum); // 만약 순열 2개가 만들어 졌다면
            number[sum]++;
            sum -= q.front();
            q.pop();
            cnt--;
        }
    }

    if (m == 0)
    {
        cout << "SAD" << '\n';
    }
    else
    {
        cout << m << '\n';
        cout << number[m] << '\n';
    }
    return 0;
}