#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[51][51];
bool vis[51][51]; // 해당 칸을 방문했는지 여부를 저장
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1}; // 상하좌우 네 방향을 의미

int t, m, n, k;          // m과 n은 bfs 함수에서 써야되서 전역변수.
queue<pair<int, int>> q; // 얘도 전역

void bfs(int i, int j)
{
    vis[i][j] = true; // 방문한 노드는 true
    q.push({i, j});
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) // board[y][x] 와 같은 이유
                continue;
            if (vis[nx][ny] || board[nx][ny] != 1) // 이미 방문했거나, 배추를안심었다면
                continue;                          // 처음으로
            vis[nx][ny] = true;
            q.push({nx, ny});
        }
    }
};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--)
    {

        cin >> m >> n >> k;
        int x, y;

        for (int i = 0; i < k; i++)
        {
            // int x, y; 틀림. 앞에서 선언해야됨
            cin >> x >> y;
            board[y][x] = 1; // 중요 xy아님 yx임.
        }

        int count = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 1 && !vis[i][j])
                {              // 배추가 심어져있으면서, 방문을 안했다면
                    bfs(i, j); // 즉 모든 심어져있는 배추에 대해서 bfs를 진행하지만, 한번
                    /// 진행하게 되면, 십자에 위치해있는 배추는 vis가 true가 되므로 문제없.
                    // 이중 포문 자체가 문제.
                    count++;
                }
            }
        }
        cout << count << endl;
        // t번 시행해야하니 다음 번 전에
        // for (int i = 0; i < n; i++)
        // {
        //     fill(board[i], board[i] + m, 0);
        //     fill(vis[i], vis[i] + m, false);
        // }
        memset(board, 0, sizeof(board)); // 위의 fill문 대체가능
        memset(vis, false, sizeof(vis));
    }

    return 0;
}