#include <iostream>

using namespace std;
int main()
{
    long long c;
    cin >> c;

    long long k = c * (c - 1) * (c - 2) / 6; // 자연수의 거듭제곱의 합. 1^2 + 2^2 .... + n^2;
    cout << k << '\n';

    cout << 3 << endl;

    return 0;
}