#include <string>
#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;

    // bool* alphabet = new bool[24];
    int alphabet[26];
    for (int &value : alphabet)
    { //&�� ���۷���
        value = -1;
    }

    for (int i = 0; i < s.length(); i++)
    {
        // for (int j = 0; j < 24; j++) {
        //	if (s[i] == j + 97) {
        //		alphabet[j] = i;
        //	}
        int idx = s[i] - 97;     // �̷��� idx�� a�� 0 b�� 1 c�� 2�� ��. 97�� �ƽ�Ű�ڵ�
        if (alphabet[idx] == -1) // �ش� ��ġ�� �ѹ��� �������� ���ٸ� ����. �� ����� ó�� �����ϴ� ��ġ�� ����
        {
            alphabet[idx] = i; // �ش� ���ĺ��� �ش��ϴ� ���� ��ġ i�� ����
        }
    }
    for (int i = 0; i < 26; i++)
    {
        if (alphabet[i] != -1)
            cout << alphabet[i] << ' ';
        else
            cout << "-1 ";
    }

    return 0;
}