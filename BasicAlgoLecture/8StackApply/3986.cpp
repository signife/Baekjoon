#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string ss;
    // stack<char> s; 스택 바깥에서 선언하면 이전 결과가 남아있음..
    int n;
    int cnt = 0;
    cin >> n;
    cin.ignore(); // 중요

    while (n--)
    {
        getline(cin, ss);
        stack<char> s;
        for (auto const &word : ss)
        {
            if (!s.empty() && s.top() == word)
                s.pop();
            else
                s.push(word);
        }

        if (s.empty())
            cnt++;
    }

    cout << cnt;
}