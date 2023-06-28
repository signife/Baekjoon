#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    deque<int> dq;
    for (int i = 1; i <= n; i++)
    {
        dq.push_back(i);
    }

    int cnt = 0;
    while (m--)
    {
        int t;
        cin >> t;

        int idx = 0;
        for (int i = 0; i < dq.size(); i++)
        {
            if (dq[i] == t)
            {
                idx = i;
                break;
            }
        }
        if (idx <= dq.size() - idx - 1) // 입력 t가 전체크기의 반절보다 작다면
        {
            while (dq.front() != t)
            {
                dq.push_back(dq.front()); // 왼쪽으로 이동
                dq.pop_front();
                cnt++;
            }
        }
        else
        {
            while (*dq.begin() != t) // 이게 젤 중요한 문법인듯?
            {
                dq.push_front(dq.back());
                dq.pop_back();
                cnt++;
            }
        }

        dq.pop_front();
    }

    cout << cnt << endl;
    return 0;
}