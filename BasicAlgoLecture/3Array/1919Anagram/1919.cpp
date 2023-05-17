#include <bits/stdc++.h>
using namespace std;

int arr[2][26], res;
string s1, s2;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s1 >> s2;
    for (char c : s1)
        arr[0][c - 'a']++; // 이렇게 하면 중복된 알파벳의 개수도 정확하게

    for (char c : s2)
        arr[1][c - 'a']++;

    for (int i = 0; i < 26; i++)
        res += abs(arr[0][i] - arr[1][i]); // 알파뱃 개수 차이의 절대값을 누적

    cout << res;
}