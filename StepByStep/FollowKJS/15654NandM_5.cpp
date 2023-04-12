#include <iostream>
#define MAX 9
using namespace std;

int n, m;

int arr[MAX];
int num[MAX];
bool visited[MAX];

void dfs(int count)
{
    if (count == m) // 길이가 m
    {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << std::endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            visited[i] = true;
            arr[count] = i;
            dfs(count + 1); // 재귀
            visited[i] = false;
        }
    }

    /*  for (int i = 0; i < n; i++)
      {
          if (visited[i] == 0)
          {
              visited[i] = true;
              arr[count] = i;
              dfs(count + 1); // 재귀
              visited[i] = false;
          }
      }*/
    // 여기에 만약 반복문을 1부터 시작해서 <= n까지 하지 않으면, num[max를 또 선언해야됨.]
