#include <iostream>
#include <string>
using namespace std;

// 대문자 65~90, 소문자 97~122
int main()
{

    string s;
    cin >> s;

    int alpha[26] = {0};
    int cnt = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] < 97)
            alpha[s[i] - 65]++; // 현재 문자가 대문자인 경우
        else
            alpha[s[i] - 97]++; // 현재 문자가 소문자인 경우

        // 소문자
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

// 내가 지금 작성한 코드를 깃허브에 올리고싶음