#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
int main()
{
    string s, spl;
    vector<string> nums;
    vector<int> n;

    getline(cin, s);

    stringstream ss(s);
    while (getline(ss, spl, ' '))
    {
        nums.push_back(spl);
    }

    for (const auto &i : nums)
    {
        n.push_back(stoi(i));
    }

    // string result;
    // for (int i = 1; i < n.size(); i++)
    // {
    //     if (n[i] - 1 == n[i - 1])
    //     {
    //         result = "ascending";
    //     }
    //     else if (n[i] == n[i - 1] - 1)
    //     {
    //         result = "descending";
    //     }
    //     else
    //         result = "mixed";
    //     break; // break 없으면 1234 8765 이런거면 ㅈ된다
    // }
    // for (int i = 0; i < n.size(); i++)
    // {
    //     if (n[i] == i + 1)
    //     {
    //         result = "ascending";
    //     }
    //     else if (n[i] == 8 - i)
    //     {
    //         result = "descending";
    //     }
    //     else
    //         result = "mixed";
    //     break; // break 없으면 1234 8765 이런거면 ㅈ된다
    // }
    string result;
    bool is_ascending = true;
    bool is_descending = true;

    for (int i = 1; i < n.size(); i++)
    {
        if (n[i] - 1 != n[i - 1])
        {
            is_ascending = false;
        }
        if (n[i] + 1 != n[i - 1])
        {
            is_descending = false;
        }
    }

    if (is_ascending)
    {
        result = "ascending";
    }
    else if (is_descending)
    {
        result = "descending";
    }
    else
    {
        result = "mixed";
    }

    cout << result << endl;

    return 0;
}
