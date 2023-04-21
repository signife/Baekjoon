#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    vector<int> card(20);
    int num = 1;
    for (int &x : card) // 참조자 활용
    {
        x = num++;
    }
    // vector<int> v;
    // for (int i = 1; i <= n; i++)
    // {
    //     v.push_back(i);
    // }
    for (int i = 0; i < 10; i++)
    {
        int start, end;
        cin >> start >> end;
        reverse(card.begin() + start - 1, card.begin() + end);
    }

    for (int &x : card)
    {
        cout << x << ' ';
    }

    return 0;
}