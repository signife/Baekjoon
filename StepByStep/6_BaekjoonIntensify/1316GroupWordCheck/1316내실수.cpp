// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;

// vector<int> last_positions(const string &s);

// int main()
// {
//     int n;
//     string s;
//     int cnt = 0;
//     int pass = 0;

//     cin >> n;
//     while (n--)
//     {

//         cin >> s;
//         vector<int> p = last_positions(s);

//         // for (int k = 0; k < s.length(); k++)
//         // {
//         //     if (p[s[k]] == -1)
//         //     {
//         //         pass = 0;
//         //         break;
//         //     }
//         //     if (k != 0)
//         //     {
//         //         if (s[k] != s[k - 1])
//         //         {
//         //             continue;
//         //         }
//         //     }
//         //     cnt += pass;
//         // }
//         for (int i = 0; i < p.size(); i++)
//         {
//             if (p[i] != -1)
//             {
//                 for (int k = 1; k < s.length(); k++)
//                 {
//                     if (s[k] == s[k - 1])
//                         break;
//                     else
//                     {
//                         cnt++;
//                     }
//                 }
//             }
//         }
//     }
//     cout << cnt;

//     return 0;
// }

// vector<int> last_positions(const string &s)
// {
//     vector<int> alphabet(26, -1);
//     for (int i = 0; i < s.length(); i++)
//     {
//         int idx = s[i] - 97; //'a'
//         alphabet[idx] = i;
//     }

//     return alphabet;
// }