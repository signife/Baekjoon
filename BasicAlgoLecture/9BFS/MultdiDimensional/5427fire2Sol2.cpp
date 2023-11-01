#include <bits/stdc++.h>
using namespace std;

int board[1002][1002];
int sangun_visited[1002][1002];
int fire_vistied[1002][1002];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int t, h, w;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        bool escape = false;
        queue<pair<int, int>> fq, sq;
        cin >> h >> w; // 열, 행 입력.( 입력 순서 자체는 행 열임.)
        memset(sangun_visited, 0, sizeof(sangun_visited));
        memset(fire_vistied, 0, sizeof(fire_vistied));

        for (int i = 0; i < w; i++)
        {                               // 행
            for (int j = 0; j < h; j++) // 열
            {
                char c;
                cin >> c;
                if (c == '#')
                    board[i][j] = -1;
                else // 벽이아니면
                {
                    if (c == '@') // 상군이면
                    {
                        sq.push({i, j});
                        sangun_visited[i][j] = 1;
                    }
                    else if (c == '*') // 불이면
                    {
                        fq.push({i, j});
                        fire_vistied[i][j] = 1;
                    }
                    // 어디에도 속하지 않고 이동할 수 있는 빈 공간이면 즉 "."
                    board[i][j] = 0; // 벽이 아니면 전부 board[i][j]  = 0;
                }
            }
        }

        while (!fq.empty())
        {
            auto cur = fq.front();
            fq.pop();
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if (nx < 0 || ny < 0 || nx >= w || ny >= h)
                    continue; // 범위를 벗어나면
                if (board[nx][ny] == -1)
                    continue;             // 벽에 닿으면
                if (fire_vistied[nx][ny]) // visted 값이 0이 아니라면 초기값은 memset 0임
                    continue;
                fire_vistied[nx][ny] = fire_vistied[cur.first][cur.second] + 1;
                fq.push({nx, ny});
            }
        }

        while ((!sq.empty()) && (!escape))
        {
            auto cur = sq.front();
            sq.pop();
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if (nx < 0 || ny < 0 || nx >= w || ny >= h)
                {
                    // 상군이가 맵밖으로 나간거면 탈출 한거임.
                    cout << sangun_visited[cur.first][cur.second] << endl;
                    escape = true;
                    break;
                }
                if (board[nx][ny] == -1)
                    continue;
                if (sangun_visited[nx][ny])
                    continue;
                if (fire_vistied[nx][ny] != 0 && fire_vistied[nx][ny] <= sangun_visited[cur.first][cur.second] + 1)
                    continue;
                // 불이 도착했었거나 &&  상군이의 현재위치+1을 한 값이 불이 도달한 시간보다 크거나 같다면
                // 상군이는 불보다 늦게 도착한것이므로 처음부터
                sangun_visited[nx][ny] = sangun_visited[cur.first][cur.second] + 1;
                sq.push({nx, ny});
            }
        }

        if (!escape)
            cout << "IMPOSSIBBLE" << endl;
    }

    return 0;
}