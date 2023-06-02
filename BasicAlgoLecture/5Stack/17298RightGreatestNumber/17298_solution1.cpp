#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    stack<int> s;
    vector<int> ans;
    vector<int> seq;

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> seq[i];

    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() <= seq[i])
            s.pop();
        if (s.empty())
            ans[i] = -1;
        else
            ans[i] = s.top();

        s.push(seq[i]);
    }

    // 정답 출력
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
}