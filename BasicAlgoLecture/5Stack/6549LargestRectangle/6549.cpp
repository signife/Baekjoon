#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true)
    {
        int n;
        cin >> n;
        if (n == 0)
            break;               // 입력의 마지막에는 0이 주어진다.
        stack<pair<int, int>> s; // long long 으로 선언해도 된다.
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            int h;
            cin >> h;
            int idx = i; // 같은 높이 처리를 위해서
            while (!s.empty() && s.top().X >= h)
            { // 내림차순으로 현재 막대의 높이가 top보다 크다면
                ans = max(ans, static_cast<long long>(i - s.top().Y) * s.top().X);
                // 현재 막대보다 높은 막대가 나올때까지 pop하고, pop 할때마다
                // 가장 큰 직사각형의 넓이 계산.
                // X는 높이, Y는 해당 높이가 최초로 등장한 위치.
                // 즉 (i-최초 위치)*높이를 해야 답이 나옴.
                idx = s.top().Y; // 현재 막대 높이가 top보다 크므로,
                s.pop();
            }
            s.push({h, idx});
        }
        while (!s.empty())
        {
            ans = max(ans, static_cast<long long>(n - s.top().Y) * s.top().X);
            s.pop();
        }
        cout << ans << '\n';
    }
}
