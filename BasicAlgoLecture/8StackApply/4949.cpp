#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string ss;
    // stack<char> s; 스택 바깥에서 선언하면 이전 결과가 남아있음..

    while (true)
    {
        getline(cin, ss);
        if (ss == ".")
            break;

        bool bumzi = true;

        stack<char> s;
        for (auto const &word : ss)
        {
            if (word == '(' || word == '[')
                s.push(word);
            else if (word == ')')
            {
                if (s.empty() || s.top() != '(')
                {
                    bumzi = false;
                    break;
                }
                s.pop();
            }
            else if (word == ']')
            {
                if (s.empty() || s.top() != '[')
                {
                    bumzi = false;
                    break;
                }
                s.pop();
            }
        }

        if (!s.empty()) // 이 문구가 없으면, A rope may form )( a trail in a maze. 이런 문장 대처 안됨.
            bumzi = false;

        if (bumzi)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
}