#include <iostream>
#include <string>
using namespace std;

int main()
{
    int num;

    cin >> num;

    // for (int i = 0; i < num; i++)
    // {
    //     cin >> repeat >> s;
    //     for (int i = 0; i < repeat; i++)
    //     {
    //         for (int j = 0; j < repeat; j++)
    //             cout << s[j];
    //     }
    // }

    for (int i = 0; i < num; i++)
    {
        int repeat;
        string s;
        cin >> repeat >> s;
        for (int k = 0; k < s.length(); k++)
        {
            // s.length가 repeat이였던게 문제였음
            for (int j = 0; j < repeat; j++)
                cout << s[k]; // s[j]면 abcabcabc s[k]면 aaabbbccc
        }                     // 이중 FOR문을 돌리는데 바깥 FOR문의 IDX가 안에서 돌게 하면
        cout << endl;
    }
    return 0;
}
