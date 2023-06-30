#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    stack<char> s;
    string ss;

    cin >> ss;

    int sum = 0;
    int stick = 0;

    for (auto const &word : ss)
    {
        if (word == '(')
        {
            s.push(word);
            stick++;
        }
        else if (!s.empty() && s.top() == '(' && word == ')')
        {
            stick--;
            s.pop();
            sum += stick;
        }
    }

    cout << sum;

    return 0;
}