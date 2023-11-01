#include <bits/stdc++.h>
using namespace std;

string board[1002]; // string 자체가 배열이라 2차원 배열로 선언 안해도 됨.
int sangun_visited[1002][1002];
int fire_vistied[1002][1002];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int h, w;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        cin >> w >> h; // 너비, 높이 순 ///너비 가로 = 열/ 높이 세로 =행(의번지수)
        memset(sangun_visited, 0, sizeof(sangun_visited));
        memset(fire_vistied, 0, sizeof(fire_vistied)); // 0으로 초기화 해야
        // fire_visated[nx][ny] 문장 이용 가능

        for (int i = 0; i < h; i++)
        { // 행의 개수만큼 board임. w가 아니라 h면 틀려.
            cin >> board[i];
        }

        queue<pair<int, int>> sq, fq;

        for (int i = 0; i < h; i++) // i는 높이만큼
        {
            for (int j = 0; j < w; j++) // j는 w 너비만큼
            {
                if (board[i][j] == '#')
                    board[i][j] = -1;
                else
                {
                    if (board[i][j] == '@')
                    {
                        sangun_visited[i][j] = 1;
                        sq.push({i, j});
                    }
                    else if (board[i][j] == '*')
                    {
                        fire_vistied[i][j] = 1;
                        fq.push({i, j});
                    }
                    board[i][j] = 0; // 이게 없을거면 위에 memset에 visit 말고 board 배열도 추가.
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
                if (nx < 0 || ny < 0 || nx >= h || ny >= w) // 범위 벗어난다면. 범위 w h 행열구분조심
                    continue;
                if (board[nx][ny] == -1)
                    continue; // 벽이라면
                if (fire_vistied[nx][ny])
                    continue; // 시간과 관계없이 값이 0이 아니라면 다시
                fire_vistied[nx][ny] = fire_vistied[cur.first][cur.second] + 1;
                fq.push({nx, ny});
            }
        }
        while (!sq.empty())
        {
            auto cur = sq.front();
            sq.pop();
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if (nx < 0 || ny < 0 || nx >= h || ny >= w)
                {
                    cout << sangun_visited[nx][ny] << endl;
                    goto tryAgain;
                }
                if (board[nx][ny] == -1)
                    continue;
                if (sangun_visited[nx][ny])
                    continue;
                if (fire_vistied[nx][ny] != 0 && fire_vistied[nx][ny] <= sangun_visited[nx][ny] + 1)
                    continue; // 불이 지나갔고, 그 불이 상군이가 지나간 시간보다 적지않다면 처음부터
                sangun_visited[nx][ny] = sangun_visited[cur.first][cur.second] + 1;
                sq.push({nx, ny});
            }
        }
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}