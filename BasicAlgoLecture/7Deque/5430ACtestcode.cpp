#include <bits/stdc++.h>
using namespace std;

void parse(string &s, deque<int> &v)
{
    int cur = 0;
    for (int i = 1; i + 1 < s.size(); i++) // 첫번째 문자와 마지막 문자 괄호이므로 무시
    {
        if (s[i] == ',')
        {
            v.push_back(cur); // 쉼표를 만났을대 여태 구했던 cur 을 더함
            cur = 0;          // 쉼표 만났으니 초기화
        }
        else
        {
            cur = 10 * cur + (s[i] - '0'); // 아니라면 자릿수 증가 시켜줌.
        }
    }
    // 우리의 입력은 1<= 변수 < = 100으로 정해져있으니 한번 생략??
    if (cur != 0)
        v.push_back(cur); // 쉼표를 만났을때 추가하는 방식이므로 이걸 통해 마지막 숫자 추가
}

void print(deque<int> &v)
{
    cout << '[';
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i];
        if (i + 1 != v.size()) // 마지막 원소에 ,를 출력 안하기 위한 방법
            cout << ',';
    }
    cout << "]\n";
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int test;
    cin >> test;

    // deque<int> v; // 전의 내용이 안 없어짐.

    while (test--)
    {
        deque<int> v;
        int num;
        string s, temp;

        cin >> s;
        cin >> num;
        cin >> temp;

        parse(temp, v);

        int rev = 0;
        bool isWrong = false;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'R')
                rev = 1 - rev; // 이러면 r나온 횟수만큼 순환,
            else               // S[i] == 'D'
            {
                if (v.empty())
                {
                    isWrong = true;
                    break;
                }
                if (!rev)          // R이 나온 횟수가 짝수라면
                    v.pop_front(); // 앞을 제거
                else               // R이 나온 횟수가 홀수라면
                    v.pop_back();  // 뒤를 제거
            }
        }

        if (isWrong)
            cout << "error\n";
        else
        {
            if (rev) // R이 홀수면
                reverse(v.begin(), v.end());
            print(v);
        }
    }
    return 0;
}
