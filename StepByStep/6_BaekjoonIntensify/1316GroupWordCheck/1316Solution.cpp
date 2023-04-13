
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
        bool used[26] = {false}; // 알파벳 사용 여부를 저장할 배열 초기화

        for (int j = 0; j < s.length(); j++) // 문자를 순회하면서
        {
            if (used[s[j] - 'a'])
            { // 이미 사용한 알파벳이면 그룹 단어가 아님
                pass = 0;
                break;
            }
            if (j < s.length() - 1 && s[j] != s[j + 1]) //&&의 왼쪽 식은 j+1때문에 최대 인덱스 넘어 갈 수 있으므로 추가
            {                                           // 현재 문자와 다음 문자가 다르면
                used[s[j] - 'a'] = true;                // 현재 문자를 사용한 것으로 체크. 이렇게하면 aaaa << 이렇게 나온거는 체킹안해도 됨
            }
        }
        count += pass;
        pass = 1;
    }

    cout << count << endl;

    return 0;
}
