#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    // vector<vector<int>> a(n, vector<int>(m));
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cin >> a[i][j];
    //     }
    // }
    // vector<vector<int>> b(n, vector<int>(m));
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cin >> b[i][j];
    //     }
    // }

    std::vector<std::vector<int>> a(n, std::vector<int>(m));
    for (auto &row : a)
    {
        for (auto &column : row)
        {
            std::cin >> column;
        }
    }

    std::vector<std::vector<int>> b(n, std::vector<int>(m));
    for (auto &row : b)
    {
        for (auto &column : row)
        {
            std::cin >> column;
        }
    }

    vector<vector<int>> c(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }

    for (const auto &row : c)
    {
        for (const auto &column : row)
        {
            cout << column << ' ';
        }
        cout << endl;
    }

    return 0;
}