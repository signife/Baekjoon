// �Է¿� ��ĭ�� ����
// col <= 5, 1<=row<=15
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{

    vector<vector<char>> a(5, vector<char>(15, ' ')); // ���� �ʱ�ȭ�ϸ鼭 �����߰�
    string s;
    for (int i = 0; i < 5; i++)
    {
        getline(cin, s);
        for (int j = 0; j < s.size(); j++)
        {
            a[i][j] = s[j];
        }
    }

    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (a[j][i] != ' ')
                cout << a[j][i];
        }
    }

    return 0;
}
