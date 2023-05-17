#include <iostream>
#include <list>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    list<char> o;
    auto cursor = o.begin(); // 커서를 리스트의 첫 번째 원소로 초기화

    int n;
    cin >> n;
    cin.ignore(); // 개행 문자 처리를 위해 버퍼 비우기

    while (n--)
    {
        getline(cin, s);
        for (char c : s)
        {
            if (c == '<')
            {
                if (cursor != o.begin())
                {
                    --cursor; // 커서를 왼쪽으로 이동
                }
            }
            else if (c == '>')
            {
                if (cursor != o.end())
                {
                    ++cursor; // 커서를 오른쪽으로 이동
                }
            }
            else if (c == '-')
            {
                if (cursor != o.begin())
                {
                    cursor = o.erase(prev(cursor)); // 커서 왼쪽의 원소 삭제
                }
            }
            else
            {
                o.insert(cursor, c); // 커서 왼쪽에 문자 삽입
            }
        }
        if (n > 0)
        {
            o.insert(cursor, '\n'); // 개행 문자 삽입
        }
    }

    for (char &c : o)
    {
        cout << c; // 리스트의 모든 원소 출력
    }
    cout << '\n';

    return 0;
}
