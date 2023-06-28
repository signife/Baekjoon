#include <bits/stdc++.h>
using namespace std;

void parse(string &s, vector<int> &v)
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

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int test;
    cin >> test;

    vector<int> v;

    while (test--)
    {
        string s;
        cin >> s;

        int num;
        cin >> num;

        string temp;
        cin >> temp;
        parse(temp, v);

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'R')
            {
                reverse(v.begin(), v.end());
            }
            else
                v.erase(v.begin());
        }

        if (v.empty())
            cout << "error" << endl;
        else
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
    }
    return 0;
}