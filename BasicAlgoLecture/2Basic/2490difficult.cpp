// 배는 0 등은 1
//  도는 0이 1개           총합 3 a
//  개는 0이 2개 1도 2개   총합 2 b
//  걸은 0이 3개           총합 1 c
//  윷은 0 4개             총합 0 d
//  모는 0이 0개 1이 4개  총합 4  e

#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int result, num;
    string res = "DCBAE"; // 각 배의 개수가 01234

    for (int i = 0; i < 3; i++)
    {
        result = 0;
        for (int j = 0; j < 4; j++)
        {
            cin >> num;
            result += num;
        }
        cout << res[result] << '\n';
    }

    return 0;
}
