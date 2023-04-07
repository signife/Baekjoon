#include <iostream>
#include <string>
#include <map>

using namespace std;

// i love you 단어가 3개. 공백은 2개
int main()
{
    string str;
    getline(cin, str); // 문자열 입력

    int num = 1; // 그래서 1로 시작.

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
            num++;
    }

    if (str[0] == ' ')
        num--; // 첫 문자가 공백인 경우의 예외처리
    if (str[str.length() - 1] == ' ')
        num--; // 마지막이 공백으로 끝나는 경우의 예외처리
    cout << num;
    return 0;
}