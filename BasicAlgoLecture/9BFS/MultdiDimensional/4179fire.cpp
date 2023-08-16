#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int f_visited[1002][1002]; //불
int j_visited[1002][1002]; //지훈
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
string board[1002]; //입력
int r, c; //n, m대신 row column

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        fill(f_visited[i], f_visited[i] + c, -1);
        fill(j_visited[i], j_visited[i] + c, -1);
    } // 전부 -1로 초기화.

    for (int i = 0; i < r; i++)
        cin >> board[i];

    queue<pair<int, int>> q1;
    queue<pair<int, int>> q2;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (board[i][j] == 'F')
            {
                q1.push({i, j});
                f_visited[i][j] = 0;
            }
            if (board[i][j] == 'J')
            {
                q2.push({i, j});
                j_visited[i][j] = 0;
            }
        }
    }

    //불
    while (!q1.empty())
    {
        auto cur = q1.front();
        q1.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= r || ny < 0 || ny >= c)
                continue;
            if (f_visited[nx][ny] >= 0 || board[nx][ny] == '#')
                continue; // 불이이미 지나갔거나 벽이면
            f_visited[nx][ny] = f_visited[cur.X][cur.Y] + 1;
            q1.push({nx, ny});
        }
    }

    //지훈이
    while (!q2.empty())
    {
        auto cur = q2.front();
        q2.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= r || ny < 0 || ny >= c)
            { //범위를 벗어난 것은 탈출을 의미. 큐에 거리순으로 들어가니 최초 탈출시간.
                cout << j_visited[cur.X][cur.Y] + 1;
                return 0;
            }
            if (j_visited[nx][ny] >= 0 || board[nx][ny] == '#')
                continue; // 지훈이가 이미 지나갔거나, 벽이 있다면 처음부터
            if (f_visited[nx][ny] != -1 && f_visited[nx][ny] <= j_visited[cur.X][cur.Y] + 1)
                continue; // 불이 이미 지나갔으며,(&&) 지훈이+1이 불보다 시간이 크다면
            // 탈출할 수 없으므로 처음부터.
            j_visited[nx][ny] = j_visited[cur.X][cur.Y] + 1;
            q2.push({nx, ny});
        }
    }

    cout << "IMPOSSIBLE"; //여기 도달한 것은 WHILE문 나오고도 지훈이 탈출X
    return 0;
}