#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<bool>> a(100, vector<bool>(100, false));

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;

        for (int j = x; j < x + 10; j++)
        {
            for (int k = y; k < y + 10; k++)
            {
                a[j][k] = true;
            }
        }
    }

    int area = 0;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (a[i][j] == 1)
                area++;
        }
    }
    cout << area << endl;

    return 0;
}