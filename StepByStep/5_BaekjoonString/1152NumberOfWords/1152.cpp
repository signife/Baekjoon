#include <iostream>
#include <string>
#include <map>

using namespace std;

// i love you �ܾ 3��. ������ 2��
int main()
{
    string str;
    getline(cin, str); // ���ڿ� �Է�

    int num = 1; // �׷��� 1�� ����.

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
            num++;
    }

    if (str[0] == ' ')
        num--; // ù ���ڰ� ������ ����� ����ó��
    if (str[str.length() - 1] == ' ')
        num--; // �������� �������� ������ ����� ����ó��
    cout << num;
    return 0;
}