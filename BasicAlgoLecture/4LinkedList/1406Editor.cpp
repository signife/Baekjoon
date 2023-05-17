#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string start;
    cin >> start;

    list<char> l;
    for (auto c : start)
    {
        l.push_back(c);
    }
    auto iter = l.end();

    int n;
    cin >> n;
    cin.ignore();

    string s;
    while (n--)
    {
        getline(cin, s);
        for (char c : s)
        {
            if (c == 'L')
            {
                if (iter != l.begin())
                    iter--;
            }
            else if (c == 'D')
            {
                if (iter != l.end())
                    iter++;
            }
            else if (c == 'B')
            {
                if (iter != l.begin())
                {
                    --iter;
                    iter = l.erase(iter);
                }
            }
            else if (s[0] == 'P' && s[1] == ' ') //  지금 내가 for char c: s 문을 했기때문에, p x 면 문자열의 길이가 3이라 3번 반복...
            {
                l.insert(iter, s[2]);
            }
            break; // 이거 없음 안된다.
        }
    }

    for (auto a = l.begin(); a != l.end(); a++)
        cout << *a;

    return 0;
}