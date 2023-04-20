#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int i = 1;

    while (n > i) // n = 5 // n = 4 // n = 2 , i = 3
    {
        n -= i; // n = 4 // n = 2 //
        i++;    // i = 2 // i = 3 //
    }           // i번째 대각선에는 i개의 원소가 있음 n이 몇번째 대각선인지. i를 순차적으로 증가시켜주며 빼줌.
    // n이 i보다 작아지면,  i번째 대각선에 n 원소 존재.

    if (i % 2 == 1)                            // 대각선의 홀짝 고려.
        cout << i + 1 - n << '/' << n << endl; // 대각선이 홀수인 경우
    else
        cout << n << '/' << i + 1 - n << endl; // 대각선이 짝수인 경우

    return 0;
}
