#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    stack<pair<int, int>> tower;

    cin >> n;
    tower.push({100000001, 0});

    for (int i = 1; i <= n; i++)
    {
        int height;
        cin >> height;
        while (tower.top().X < height) // 나보다 높은 탑을 만날 때 까지
            tower.pop();               // pop
        // 만약 이를 if문으로 짜면 무한루프에 갇힐수도

        cout << tower.top().Y << " "; // y번째 출력
        tower.push({height, i});      // 높은 탑만나면 길이 긴거 push하고 위치 저장
    }

    return 0;
}
// 6 입력, 6은 100000000보다 작으므로 pop. 저장안됨. 출력은 0
// 9 입력.