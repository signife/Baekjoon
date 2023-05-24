#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int repeat;
    cin >> repeat;

    stack<int> s;

    int cnt = 1;
    string ans;

    while (repeat--)
    {
        int t;
        cin >> t;
        while (cnt <= t)
        {
            s.push(cnt++); // 오름차순으로 1부터.cnt는 한번 오르면
            //-는 없는 걸로 중복된 숫자 피하기 = 각 수는 한번만 등장
            ans += "+\n";
        }
        // 스택의 top 값이 주어진 수열의 숫자와 같아질때까지 해야 됨.
        if (s.top() != t)
        {
            cout << "NO\n";
            return 0;
        }
        // 1 2 5 3 4의 경우. 5까진 입력이 되나, 3 > 4에서 조건 충족 불가능.
        s.pop();
        ans += "-\n";
    }

    cout << ans;
    return 0;
}