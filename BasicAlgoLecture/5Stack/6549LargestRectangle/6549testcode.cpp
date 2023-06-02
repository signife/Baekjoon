#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 7;
    stack<pair<int, int>> s;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        int h; //{4,100,100,10,100,100,100}
        cin >> h;
        int idx = i; // 같은 높이 처리를 위해서
        while (!s.empty() && s.top().X >= h)
        { // 내림차순으로 현재 막대의 높이가 top보다 크다면
            ans = max(ans, static_cast<long long>(i - s.top().Y) * s.top().X);
            // 현재 막대보다 높은 막대가 나올때까지 pop하고, pop 할때마다
            // 가장 큰 직사각형의 넓이 계산.
            // X는 높이, Y는 해당 높이가 최초로 등장한 위치.//정확히는 최초는 아니고, 작은 숫자가 나왔다가 그보다 큰 숫자가 다시 나왔을때의 위치.
            // 즉 (i-최초 위치)*높이를 해야 답이 나옴.
            idx = s.top().Y; // 현재 막대 높이가 top보다 크거나 같으므로, 위치를 거기서 고정.
            s.pop();
        }
        // 쉽게 도식화하면 while(낫엠티&& 오름차순(top이 입력값보다 크거나 같은 경우))
        // 정답은 둘중 큰것 > 기존 정답 vs 인덱스 - 모노톤y 고정한값* 현재 최고 높이//(현재 최고 높이로 곱해도 되는 이유는 h가 top보다 작은경우는 제외했기 때문)
        // 인덱스는 가장 최근에 들어온 가장 큰 수로 변경.
        s.push({h, idx});
    } // 여기까지 최고 정답은 200;
    while (!s.empty())
    {
        ans = max(ans, static_cast<long long>(n - s.top().Y) * s.top().X); // 7 - 4 * 100 = 300/ 스택은 4.0 10.1 100.4 이렇게 저장
        s.pop();
    }
    // 앞의 max가 왼쪽에서부터의 넓이였다면 while !s.empty문은 오른쪽에서부터의 넓이 구해봄.
    cout << ans << '\n';
}