#include <iostream>
#include <string>
using namespace std;

// �빮�� 65~90, �ҹ��� 97~122
int main()
{

    string s;
    cin >> s;

    int alpha[26] = {0};
    int cnt = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] < 97)
            alpha[s[i] - 65]++; // ���� ���ڰ� �빮���� ���
        else
            alpha[s[i] - 97]++; // ���� ���ڰ� �ҹ����� ���

        // �ҹ���
    }

    int max = 0;
    int max_index = 0;

    for (int i = 0; i < 26; i++)
    {
        if (max < alpha[i])
        {
            max = alpha[i];
            max_index = i;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        if (max == alpha[i])
            cnt++;
    }

    if (cnt > 1)
        cout << "?";
    else
        cout << (char)(max_index + 65);

    return 0;
}

// ���� ���� �ۼ��� �ڵ带 ����꿡 �ø������