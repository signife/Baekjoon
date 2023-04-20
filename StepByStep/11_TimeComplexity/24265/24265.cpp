#include <iostream>

using namespace std;
int main()
{
    // 외부 반복문은 n-1번. 내부 반복문은 i의 증가에 따라 n-1.
    //  시간 복잡도는 n^2
    //  n-1 + n-2 + n-3 .... +2 + 1
    // n(n-1)/2
    long long c;
    cin >> c;

    long long k = c * (c - 1) / 2;
    cout << k << '\n';

    cout << 2 << endl;

    return 0;
}