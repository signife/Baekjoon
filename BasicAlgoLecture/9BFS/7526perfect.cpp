// 정답 코드는 dx와 dy를 바꿈으로써 입력과 출력을 x y 로 받고 있음.
#include <bits/stdc++.h>
using namespace std;

int board[302][302];
int dist[302][302];

#define X first
#define Y second

int t, l;

int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int, int>> q;

    cin >> t;
    while (t--)
    {
        memset(dist, -1, sizeof(dist)); // dist 배열 -1로 초기화
        cin >> l;
        int x, y;
        cin >> x >> y;
        dist[y][x] = 0;
        q.push({y, x});
        cin >> x >> y;

        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();

            for (int dir = 0; dir < 8; dir++)
            {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || ny < 0 || nx >= l || ny >= l)
                    continue;          // 범위 밖일 경우
                if (dist[nx][ny] >= 0) //!= -1대신  //ny nx로 바꾸면 그건 틀림)
                    continue;          // 이미 방문했다면.
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                q.push({nx, ny});
            }
        }
        cout << dist[y][x] << endl; // dist[x][y]로 하면 틀려.
    }
}