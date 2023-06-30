#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string ss;
    cin >> ss;

    stack<int> s;
    int count = 0;
    for (int i = 0; i < ss.length(); i++)
    {
        if (ss[i] == '(')
            s.push(i); // (의 위치를 인덱스로 저장.
        else           // ss[i] == ')' 일때
        {
            if (s.top() == i - 1) // (의 위치가 바로 전이라면
            {
                s.pop();
                count += s.size(); // 스택 s는 막대를 뜻함.
            }
            else // ss[i-1] == )고 ss[i]도 )거나, 첫 입력이 )인 경우
            // 즉 막대의 끝.
            {
                s.pop();
                count += 1;
            }
        }
    }

    cout << count;
    return 0;
}

// #include <iostream>
// #include <string>
// #include <stack>

// using namespace std;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     stack<char> S;
//     string input;
//     int total = 0;
//     cin >> input;
//     for (int i = 0; i < input.length(); i++)
//     {
//         if (input[i] == '(')
//         {
//             S.push(input[i]);
//         }
//         else if (input[i] == ')' and input[i - 1] == '(')
//         { // 레이저일때
//             S.pop();
//             total += S.size();
//         }
//         else
//         { // 마지막 자투리일때
//             total++;
//             S.pop();
//         }
//     }
//     cout << total << endl;
// }