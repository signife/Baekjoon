#include <bits/stdc++.h>
using namespace std;

// #define X first
// #define Y second 우리는 pair가 아닌 tuple을 쓸 거 기 때문 tie명려엉

int board[103][103][103];
int dist[103][103][103];
int n, m, h;

int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {1, -1, 0, -0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

queue<tuple<int, int, int>> q;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n >> h;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                int tmp;
                cin >> tmp;
                board[j][k][i] = tmp; // j는 x, k는 y, i는 z
                if (tmp == 1)         // 익은 토마토는 큐에 추가
                    q.push({j, k, i});
                if (tmp == 0) // 익지 않은 토마토는 거리를 -1로 조정
                    dist[j][k][i] = -1;

                // 전역변수로 잡았으니 -1의 입력의 경우 0으로 초기화.
            }
        }
    }

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        int curX, curY, curZ;
        tie(curX, curY, curZ) = cur; // tuple 문법
        for (int dir = 0; dir < 6; dir++)
        {
            int nx = curX + dx[dir];
            int ny = curY + dy[dir];
            int nz = curZ + dz[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) // 여기도 보면 입력은 m n h로 받았으나
                                                                             // 연결은 y가 m x가 n이므로 x y z 순으로 입력 받아도 실제 처리는 y z x 순으로 처리중.
                continue;                                                    // 범위를 벗어나지 않은경우에만 계속
            if (dist[nx][ny][nz] >= 0)                                       // 0보다 크다는 것은, 빈칸이거나, 이미 익었거나.
            {
                continue;
            }
            dist[nx][ny][nz] = dist[curX][curY][curZ] + 1; // 주변 바로 한 칸(좌측)을 1로 만들어 줌
            q.push({nx, ny, nz});                          // 그 주변 한 칸은 새로운 익은 토마토가 됨.
            // -1 이였어도, 0+1이 대입되서 한번에 1로 승격.
        }
    }

    int ans = 0;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                if (dist[j][k][i] == -1) // 안 익은 토마토가 남아있다면.
                {                        // 0에 가로 막힌 케이스임.
                    cout << -1 << endl;
                    return 0;
                }
                ans = max(ans, dist[j][k][i]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}

//-1로 초기화 하는 이유는 결과에서 -1을 하지 않기 위함.