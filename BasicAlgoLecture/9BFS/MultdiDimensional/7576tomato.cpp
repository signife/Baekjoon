#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[1002][1002];
int dist[1002][1002];
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
// 전역 변수로 잡은 int나 int 배열은 따로 초기화를 안하면 0임.

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    queue<pair<int, int>> Q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];   // 토마토 판 입력
            if (board[i][j] == 1) // 익은 토마토라면
                Q.push({i, j});   // 큐에 집어넣기
            if (board[i][j] == 0) // 익지 않았다면,
                dist[i][j] = -1;  // 거리를 -1로.
        }                         // 아따 그럼 dist 나머지들은 초기화 안하나요?? >> 전역변수로 해서
        // 0으로 초기화 되어있음.
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << dist[i][j];
    //     }
    //     cout << endl;
    // }

    // cout << endl;
    while (!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;          // 범위를 벗어나지 않은경우에만 계속
            if (dist[nx][ny] >= 0) // 0보다 크다는 것은, 빈칸이거나, 이미 익었거나.
            {

                continue;
            }
            dist[nx][ny] = dist[cur.X][cur.Y] + 1; // 주변 바로 한 칸(좌측)을 1로 만들어 줌
            Q.push({nx, ny}); // 그 주변 한 칸은 새로운 익은 토마토가 됨.
            // -1 이였어도, 0+1이 대입되서 한번에 1로 승격.
        }
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < m; j++)
        //     {
        //         cout << dist[i][j];
        //     }
        //     cout << endl;
        // }
        // cout << endl;
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << dist[i][j];
    //     }
    //     cout << endl;
    // }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (dist[i][j] == -1) // 안 익은 토마토가 남아있다면.
            { // 0에 가로 막힌 케이스임.
                cout << -1;
                return 0;
            }
            ans = max(ans, dist[i][j]);
        }
    }
    cout << ans;
}

//-1로 초기화 하는 이유는 결과에서 -1을 하지 않기 위함.