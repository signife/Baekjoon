#include <string>
#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;

    // bool* alphabet = new bool[24];
    int alphabet[26];
    for (int &value : alphabet)
    { //&는 레퍼런스
        value = -1;
    }

    for (int i = 0; i < s.length(); i++)
    {
        // for (int j = 0; j < 24; j++) {
        //	if (s[i] == j + 97) {
        //		alphabet[j] = i;
        //	}
        int idx = s[i] - 97;     // 이러면 idx에 a면 0 b면 1 c면 2가 들어감. 97이 아스키코드
        if (alphabet[idx] == -1) // 해당 위치가 한번도 나온적이 없다면 갱신. 이 방식은 처음 등장하는 위치만 포함
        {
            alphabet[idx] = i; // 해당 알파벳에 해당하는 곳에 위치 i를 대입
        }
    }
    for (int i = 0; i < 26; i++)
    {
        if (alphabet[i] != -1)
            cout << alphabet[i] << ' ';
        else
            cout << "-1 ";
    }

    return 0;
}