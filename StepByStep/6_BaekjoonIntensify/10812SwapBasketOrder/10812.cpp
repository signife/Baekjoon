#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> basket(n);
    int num = 1;
    for (int &x : basket) // 참조자 활용
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
        int start, end, mid;
        cin >> start >> end >> mid;
        rotate(basket.begin() + (start - 1), basket.begin() + (mid - 1), basket.begin() + end);
    }

    for (int &x : basket)
    {
        cout << x << ' ';
    }

    return 0;
}