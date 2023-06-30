// #include <bits/stdc++.h>
// using namespace std;
// int main(void)
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     int n, m;

//     cin >> n >> m;

//     vector<int> d;
//     int cnt = 0;
//     int sum = 0;
//     int start = 0;
//     int end = 0;

//     for (int i = 0; i < n; i++)
//     {
//         int num;
//         cin >> num;
//         d.push_back(num);
//     }

//     while (start <= end)
//     {
//         if (sum < m)
//         {
//             sum += d[++end];
//         }
//         else if (sum == m)
//         {
//             cnt++;
//             sum += d[++end];
//         }
//         else if (sum > m)
//         {
//             sum -= d[start++];
//         }

//         if (start > end)
//         {
//             end = start;
//             sum = d[start];
//         }
//     }
//     cout << cnt << endl;

//     return 0;
// }