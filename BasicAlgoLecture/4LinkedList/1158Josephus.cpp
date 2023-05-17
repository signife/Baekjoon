#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main()
{

    int n, k; // n == maxnumber;
    cin >> n >> k;
    list<int> l;
    vector<int> output(n);

    for (int i = 1; i <= n; ++i)
        l.push_back(i);

    auto iter = l.begin();

    for (int i = 0; i < n; i++)
    {
        for (int v = 0; v < k - 1; v++)
        {
            ++iter;
            if (iter == l.end())
            {
                iter = l.begin();
            }
        }
        output[i] = *iter;
        iter = l.erase(iter);
        if (iter == l.end())
        { // 예외처리 여기서 오류?
            iter = l.begin();
        }
    }

    cout << '<';
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i];
        if (i != output.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << '>';

    return 0;
}