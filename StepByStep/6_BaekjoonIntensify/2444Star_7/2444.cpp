#include <iostream>
using namespace std;

// int main()
// {
//     int i;
//     cin >> i;

//     for (int k = 0; k < i; k++)
//     {
//         for (int j = 0; j < i - k; j++) // 이러면 역순이 됨. 첫 루프일때는
//         {
//             cout << " ";
//         }
//         for (int s = 0; s < 2 * k - 1; s++)
//         {
//             cout << "*";
//         }
//         cout << endl;
//     }

//     for (int k = 0; k < i; k++) // 4번동안
//     {
//         for (int j = 0; j < k; j++) // 공백을 4 3 2 1
//         {
//             cout << " ";
//         }
//         for (int s = 2 * i - 1 - 2 * k; s > 0; s--)
//         {
//             cout << "*";
//         }
//         cout << endl;
//     }
// }

/*int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << " ";
        }
        for (int k = 0; k < 2 * i - 1; k++)
        {
            cout << "*";
        }
        cout << endl;
    }

    for (int i = n; i > 0; i--)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << " ";
        }
        for (int k = 0; k < 2 * i - 1; k++)
        {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}*/

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        for (int k = 1; k <= 2 * i - 1; k++)
        {
            cout << "*";
        }
        cout << endl;
    }

    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        for (int k = 1; k <= 2 * i - 1; k++)
        {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}