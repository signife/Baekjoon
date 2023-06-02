// // 오름차순으로 스택쌓기 top이 가장작고 bottom이 큼
// #include <bits/stdc++.h>
// using namespace std;

// int main(void)
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     int n;
//     cin >> n;
//     // vector<int> ans;
//     vector<int> ans(n);
//     stack<int> s;
//     int height;
//     // for (int i = n; i >= 1; i--) // 내가 벡터의 크기를 정해주지 않았기 때문에 메모리 참조 오류임.
//     for (int i = n - 1; i >= 0; i--)
//     {
//         cin >> height;
//         while (!s.empty() && s.top() <= height)
//         {
//             s.pop();
//         }
//         if (s.empty())
//             ans[i] = -1;
//         else
//             ans[i] = (s.top());
//         s.push(height);
//     }

//     for (int &num : ans)
//     {
//         cout << num << " ";
//     }
//     return 0;
// }