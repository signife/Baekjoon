// 건물을 볼 수 있는 방향이 반대라면??
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    stack<pair<long long, int>> s; // 높이와 인덱스 저장.
    vector<int> ans;               // 각 건물마다 볼 수 있는 건물의 개수 저장

    cin >> n;
    long long height;
    for (int i = 0; i < n; i++)
    {
        cin >> height;
        int count = 0;                            // 현재 볼 수있는 건물의 개수 저장하는 변수
        while (!s.empty() && s.top().X <= height) // 현재 건물 top보다 크다면
        {
            count += s.top().Y; // 스택 top에 해당하는 건물은
            // 현재 건물의 옥상으로 볼 수 있으므로 count+
            s.pop();
        }
        ans.push_back(count); // 현재 건물 옥상으로 볼 수 있는개수
        s.push({height, count + 1});
    }

    for (const int num : ans)
    {
        cout << num << ' ';
    }

    return 0;
}

// 스택의 변화 10,1 ans 0
//  10,1 3,1         ans 0 0
//  10,1 7,2 (3,1은 팝했고 스택에 없어진걸 7에 index 2를 페어로 달아줌) ans  0 0 1.
//  10,1 7,2 4,1 ans 0 0 1 0
//  12에서 10,1 7,2 4,1 전부 팝 대고 ,그들이 가지고 있던 index 1,2,1전부 더해서 count =4. ans 는 0 0 1 0 4.