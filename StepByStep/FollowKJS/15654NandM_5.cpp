#include <iostream>
#define MAX 9
using namespace std;

int n, m;

int arr[MAX];
int num[MAX];
bool visited[MAX];

void dfs(int count)
{
    if (count == m) // ���̰� m
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
            dfs(count + 1); // ���
            visited[i] = false;
        }
    }

    /*  for (int i = 0; i < n; i++)
      {
          if (visited[i] == 0)
          {
              visited[i] = true;
              arr[count] = i;
              dfs(count + 1); // ���
              visited[i] = false;
          }
      }*/
    // ���⿡ ���� �ݺ����� 1���� �����ؼ� <= n���� ���� ������, num[max�� �� �����ؾߵ�.]
