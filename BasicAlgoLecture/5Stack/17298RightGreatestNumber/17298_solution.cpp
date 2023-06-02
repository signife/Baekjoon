// 내림차순
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> ans(n);
    stack<int> s;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() <= a[i])
            s.pop();
        if (s.empty())
            ans[i] = -1;
        else
            ans[i] = s.top();
        s.push(a[i]);
    }

    // 스택확인용 코드
    // while (!s.empty())
    // {
    //     cout << s.top() << ' ';
    //     s.pop();
    // }

    cout << endl;

    for (const int &num : ans)
    {
        cout << num << ' ';
    }

    return 0;
}