#include <bits/stdc++.h>
using namespace std;

int dist[100002];
int n, k;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k; // n부터 k까지의 깊이를 잴거야

    fill(dist, dist + 100001, -1); // distance 배열 전부 -1로 초기값
    dist[n] = 0;                   // 내가 출발하는 node는 0으로 세팅

    queue<int> q; // bfs를 위한 큐 선언
    q.push(n);

    while (dist[k] == -1) // q가 비어있는 동안 아님. 내가 도착해야하는 k노드가 -1인경우 무한반복
    {
        int cur = q.front();
        q.pop();

        for (int nxt : {cur - 1, cur + 1, 2 * cur}) // ranged based for문
        {
            if (nxt < 0 || nxt > 100000)
                continue; // 범위 초과면 포문 다시
            if (dist[nxt] != -1)
                continue; // 이미 방문한 곳이라면  for문 다시
            // 둘다 아니라면
            dist[nxt] = dist[cur] + 1; // 거리 1추가
            q.push(nxt);
        }
    }

    cout << dist[k];

    return 0;
}