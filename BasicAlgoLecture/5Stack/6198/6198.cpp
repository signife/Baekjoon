
// 그런데 자신이 위치한 빌딩보다 높거나 같은 빌딩이 있으면 그 다음에 있는 모든 빌딩의 옥상은 보지 못한다.
// 스택으로 풀어야하는 이유. 만약 다음 입력이 top()보다 크다면
// top을 pop해버림 이게중요.
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    long long ans;
    stack<int> s;

    cin >> n;
    long long height;
    while (n--)
    {
        cin >> height;
        while (!s.empty() && s.top() <= height)
            s.pop();
        ans += s.size(); // 어차피 우리는 정답으로 총 합을 제출함으로.
        s.push(height);
    }

    cout << ans;
    return 0;
}
// https://bunnnybin.tistory.com/entry/%EB%B0%B1%EC%A4%80-6198-%EC%98%A5%EC%83%81-%EC%A0%95%EC%9B%90-%EA%BE%B8%EB%AF%B8%EA%B8%B0-C-with-monotone-stack
// 생각해보기 >> 만약 건물 보는 방향이 반대라면??
// 만약 내가 구해야하는 정답이 총 합이 아니라, 각 건물이 몇개의 건물을 볼 수 있는지 라면??