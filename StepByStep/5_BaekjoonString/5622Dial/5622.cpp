#include <iostream>
#include <string>

using namespace std;
int main()
{
    string phone;
    int result = 0, time;
    cin >> phone;
    int alphabet[26] = {
        0,
    };
    for (char c : phone)
    {
        alphabet[c - 'A']++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (i == 'S' - 'A' || i == 'V' - 'A')
        {
            result += (i / 3 + 2) * alphabet[i];
            continue;
        }
        if (alphabet[i])
        {
            time = i / 3 + 3;
            result += (time > 9) ? 10 * alphabet[i] : time * alphabet[i];
        }
    }
    cout << result;

    return 0;
}