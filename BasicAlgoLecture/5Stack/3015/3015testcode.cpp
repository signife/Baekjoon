// 키가 큰 사람이 있으면 안되니 내림 차순 정렬.
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // int n;
    // cin >> n;
    // int n = 7;
    int n = 5;

    // // vector<int> seq(n);
    // vector<int> seq{2, 4, 1, 2, 2, 5, 1};
    vector<int> seq{5, 5, 2, 1, 5}; // 정답은 7쌍
    vector<pair<int, int>> v;
    stack<int> s;

    // for (int i = 0; i < n; i++)
    // {
    //     int num;
    //     cin >> num;
    //     seq[i] = num;
    // }

    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && s.top() <= seq[i])
        {
            v.push_back({seq[i], s.top()});
            s.pop();
        }
        s.push(seq[i]);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() <= seq[i])
        {
            v.push_back({seq[i], s.top()});
            s.pop();
        }
        s.push(seq[i]);
    }

    while (!s.empty())
    {
        cout << s.top() << ' ';
        s.pop();
    }

    cout << endl;
    cout << v.size();
    return 0;
}