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

    // 잘못된 코드
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

    // 잘못된 코드
    // for (const int &i : nums)
    // {
    //     cout << nums[i] << endl;
    // }
    int total = 0; // 변수 선언하면서 동시초기화 할때 += 연산자 사용 불가능
    for (const int &i : nums)
    {
        total += i;

    } // 테스트 코드

    cout << total % 10 << endl;

    return 0;
}