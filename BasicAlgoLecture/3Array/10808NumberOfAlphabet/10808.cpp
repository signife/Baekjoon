#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    // bool* alphabet = new bool[24];
    int alphabet[26];
    for (int &value : alphabet)
    { //&는 레퍼런스
        value = 0;
    }

    for (int i = 0; i < s.length(); i++)
    {
        // for (int j = 0; j < 24; j++) {
        //	if (s[i] == j + 97) {
        //		alphabet[j] = i;
        //	}
        int idx = s[i] - 97; // 이러면 idx에 a면 0 b면 1 c면 2가 들어감. 97이 아스키코드
        alphabet[idx]++;
    }
    for (int i = 0; i < 26; i++)
    {

        cout << alphabet[i] << ' ';
    }

    return 0;
}