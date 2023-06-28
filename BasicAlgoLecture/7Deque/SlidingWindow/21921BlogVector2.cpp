#include <bits/stdc++.h>
using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, x;
    cin >> n >> x; // 5 2
    int sum = 0;

    vector<int> v(2500000);
    for (int i = 0; i < x; i++)
    {
        cin >> v[i]; //{1 4} x까지만
        sum += v[i]; // sum = 5
    }

    int answer = sum; // answer = 5;
    int cnt = 1;
    for (int i = x; i < n; i++) // 2~5까지
    {
        cin >> v[i];            //{1,4,(아까)// 2,5,1}
        sum += v[i] - v[i - x]; // i가 2일때, sum(5) += v[2] - v[2-2]//즉 맨 오른쪽의 원소를
        // 추가하고, 맨 앞의 원소를 없앰. deque로 풀 수 있겠지??
        if (sum >= answer) // 해서 sum이 기존의 maxsum보다 크다면
        {
            if (sum == answer) // 일단 같은 경우엔 카운트 횟수를 늘려
            {
                cnt++;
            }
            else // 그렇지 않다면, maxsum에 sum을 넣어서 새롭게 갱신을 하고
            {    // cnt는 1로 고정.
                answer = sum;
                cnt = 1;
            }
        }
    }
    if (answer == 0)
    {
        cout << "SAD";
    }
    else
        cout << answer << '\n'
             << cnt;
    return 0;
}