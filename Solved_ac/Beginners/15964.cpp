#include <iostream>
using namespace std;

long long odd(long long a, long long b)
{
    return (a + b) * (a - b);
}

int main()
{
    long long a, b;
    cin >> a >> b;
    long long c = odd(a, b);

    cout << c << endl;
    return 0;
}
