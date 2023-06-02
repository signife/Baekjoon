// 키가 큰 사람이 있으면 안되니 내림 차순 정렬.
// 큰게 스택의 젤 아래루
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    stack<pair<int, int>> s;

    cin >> n;
    long long ans = 0;

    for (int i = 1; i <= n; i++)
    {
        int height;
        cin >> height;
        int cnt = 1; // 같은 키인 경우
        while (!s.empty() && s.top().X <= height)
        {
            ans += s.top().Y;        // 즉
            if (s.top().X == height) // 같은 키인 경우;
                cnt += s.top().Y;
            s.pop();
        }
        if (!s.empty()) // 스택을 내림 차순으로 추가한 경우 한 쌍을 추가하는 역할. 만약 기존보다 큰 숫자가 들어왔다면, 스택을 제거하는 과정에서 27번째 줄에서
            // 정답을 더함. 여기는 스택이 비지 않았을 경우 한쌍의 정답이 있음을 추가할때 필요.
            ans++;
        s.push({height, cnt});
    }
    cout << ans;

    return 0;
}
