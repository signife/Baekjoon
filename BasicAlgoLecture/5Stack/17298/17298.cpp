// //2493의 반대버전
// #include <bits/stdc++.h>
// using namespace std;
// int main(void)
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     int repeat;
//     cin >> repeat;

//     vector<int> v;
//     vector<int> ans;

//     for (int i = 0; i < repeat; i++)
//     {
//         int num;
//         cin >> num;
//         v.push_back(num);
//     }

//     stack<int> s;

//     for (int i = 0; i < repeat; i++)
//     {
//         while (!s.empty() && s.top() < v[i])
//         {
//             ans.push_back(v[i]);
//             s.pop();
//         }
//         s.push(v[i]);
//     }
//     while (!s.empty())
//     {
//         ans.push_back(-1);
//         s.pop();
//     }

//     for (const int &a : ans)
//     {
//         cout << a << " ";
//     }
//     return 0;
// }