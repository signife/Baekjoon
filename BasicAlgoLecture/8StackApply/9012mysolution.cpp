#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // stack<char> s; 스택 바깥에서 선언하면 이전 결과가 남아있음..
    int n;
    cin >> n;

    while (n--)
    {

        string ss;
        cin >> ss;
        stack<char> s;
        for (auto const &word : ss)
        {
            if (word == '(')
                s.push(word);
            else if (s.empty() && word == ')')
                s.push(word);

            if (!s.empty() && s.top() == '(' && word == ')')
                s.pop();
        }
        // bool 함수를 이용하면 모든 문자를  순회 안하더라도, 중간에 틀린 쌍이 나오면 바로
        // 틀렸다고 판별!

        if (s.empty())
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}