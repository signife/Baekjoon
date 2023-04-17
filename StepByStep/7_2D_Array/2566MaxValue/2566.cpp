#include <iostream>
#include <vector>

using namespace std;

int main()
{

    std::vector<std::vector<int>> a(9, std::vector<int>(9));
    for (auto &row : a)
    {
        for (auto &column : row)
        {
            std::cin >> column;
        }
    }

    int max = -1;
    int max_row, max_col;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (max < a[i][j])
            {
                max = a[i][j];
                max_row = i + 1;
                max_col = j + 1;
            }
        }
    }
    cout << max << endl;
    cout << max_row << ' ' << max_col;

    return 0;
}