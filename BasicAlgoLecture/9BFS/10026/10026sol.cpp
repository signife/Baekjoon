#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

char board[101][101];
bool vis[101][101];

int n;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

queue<pair<int, int>> q;

void bfs(int i, int j)
{
    // queue<pair<int, int>> q;
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
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) // 범위를 벗어났거나
                continue;
            if (vis[nx][ny] == 1 || board[i][j] != board[nx][ny]) // 방문한적이 있거나,
                // i,j(current)가 nx,ny(다음노드)와 같지 않은 경우
                continue;
            // 그게 아니라면
            vis[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}

// area 함수???
int area()
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        // 이중포문
        for (int j = 0; j < n; j++)
        {
            if (!vis[i][j]) // 처음 방문해본다면.
                cnt++;
            bfs(i, j);
        }
    }

    return cnt; // int형 함수라 리턴값 있어야댐
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cin.ignore(); // 빠트리면 런타임

    for (int i = 0; i < n; i++)
    {
        string s;
        getline(cin, s);
        for (int j = 0; j < n; j++) // 걍 이중포문.
        {
            board[i][j] = s[j];
        }
    }

    int normal = area(); // 정상인

    memset(vis, false, sizeof(vis)); // 적록 색약 전에 방문 배열 초기화.

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 'G') // 초록은 빨강으로 치환.
                board[i][j] = 'R';
        }
    }

    int abnormal = area(); // 색약인 사람.
    cout << normal << " " << abnormal << endl;
    return 0;
}