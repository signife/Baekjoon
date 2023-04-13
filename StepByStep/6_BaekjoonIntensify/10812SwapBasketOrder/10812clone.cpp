#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    int num = 1;
    for (int &x : v) // 참조자 활용
    {
        x = num++;
    }
    // vector<int> v;
    // for (int i = 1; i <= n; i++)
    // {
    //     v.push_back(i);
    // }

    while (m--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        rotate(v.begin() + (x - 1), v.begin() + (z - 1), v.begin() + y);
    }

    for (int &x : v)
    {
        cout << x << ' ';
    }

    return 0;
}