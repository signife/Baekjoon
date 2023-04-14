#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    string s, spl;
    vector<string> unique_identifier;
    vector<int> nums;

    getline(cin, s);
    stringstream ss(s);
    while (getline(ss, spl, ' '))
    {
        unique_identifier.push_back(spl);
    }

    for (const string &i : unique_identifier)
    {
        nums.push_back(stoi(i));
    }

    // �߸��� �ڵ�
    // for (const int &i : nums)
    // {
    //     int sex;
    //     sex = nums[i] * nums[i];
    //     nums[i] = sex;
    // }
    for (int &i : nums)
    {
        int temp = i * i;
        i = temp;
    }

    // �߸��� �ڵ�
    // for (const int &i : nums)
    // {
    //     cout << nums[i] << endl;
    // }
    int total = 0; // ���� �����ϸ鼭 �����ʱ�ȭ �Ҷ� += ������ ��� �Ұ���
    for (const int &i : nums)
    {
        total += i;

    } // �׽�Ʈ �ڵ�

    cout << total % 10 << endl;

    return 0;
}