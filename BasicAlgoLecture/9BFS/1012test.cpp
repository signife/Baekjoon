#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[51][51];
bool vis[51][51]; // 해당 칸을 방문했는지 여부를 저장
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1}; // 상하좌우 네 방향을 의미

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int, int>> q;

    int t;
    cin >> t;
    while (t--)
    {
        int m, n, k;
        cin >> m >> n >> k;
        int x, y;

        for (int i = 0; i < k; i++)
        {
            // int x, y; 틀림. 앞에서 선언해야됨
            cin >> x >> y;
            board[x][y] = 1;
        }

        int jirung = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 1 & !vis[i][j]) // 배추가 심어져있고, 이전에 안왔었다면
                {
                    vis[i][j] = true;
                    q.push({i, j});
                    while (!q.empty())
                    {
                        auto cur = q.front();
                        q.pop();

                        for (int dir = 0; dir < 4; dir++)
                        {
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir];
                            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                                continue;
                            if (vis[nx][ny] || board[nx][ny] != 1)
                                continue;
                            vis[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                    jirung++;
                }
            }
            cout << jirung << "\n";
            for (int i = 0; i < n; i++)
            {
                fill(board[i], board[i] + m, 0);
                fill(vis[i], vis[i] + m, false);
            }
        }
    }

    return 0;
}