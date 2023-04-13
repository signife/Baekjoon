
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int count = 0;
    int pass = 1;

    while (n--)
    {
        string s;
        cin >> s;
        bool used[26] = {false}; // ���ĺ� ��� ���θ� ������ �迭 �ʱ�ȭ

        for (int j = 0; j < s.length(); j++) // ���ڸ� ��ȸ�ϸ鼭
        {
            if (used[s[j] - 'a'])
            { // �̹� ����� ���ĺ��̸� �׷� �ܾ �ƴ�
                pass = 0;
                break;
            }
            if (j < s.length() - 1 && s[j] != s[j + 1]) //&&�� ���� ���� j+1������ �ִ� �ε��� �Ѿ� �� �� �����Ƿ� �߰�
            {                                           // ���� ���ڿ� ���� ���ڰ� �ٸ���
                used[s[j] - 'a'] = true;                // ���� ���ڸ� ����� ������ üũ. �̷����ϸ� aaaa << �̷��� ���°Ŵ� üŷ���ص� ��
            }
        }
        count += pass;
        pass = 1;
    }

    cout << count << endl;

    return 0;
}
