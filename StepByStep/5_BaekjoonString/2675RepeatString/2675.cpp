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
            // s.length�� repeat�̿����� ��������
            for (int j = 0; j < repeat; j++)
                cout << s[k]; // s[j]�� abcabcabc s[k]�� aaabbbccc
        }                     // ���� FOR���� �����µ� �ٱ� FOR���� IDX�� �ȿ��� ���� �ϸ�
        cout << endl;
    }
    return 0;
}
