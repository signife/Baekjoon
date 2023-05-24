// 정수가 "0"일 경우에 지울 수 있는 수가 있음을 보장할 수 있다.
// 이거의 뜻은 pop하기전에 empty의 계산을 안해도 된다는 것.

#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> s;
    int k = 0;
    cin >> k;
    while (k--)
    {
        int num;
        cin >> num;
        if (num == 0)
            s.pop();
        else
            s.push(num);
    }

    int total = 0; // 0으로 초기화 안하면 틀림
    while (!s.empty())
    {
        total += s.top();
        s.pop();
    }

    cout << total;

    return 0;
}