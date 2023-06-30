#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, l;
    cin >> n >> l;

    deque<pair<int, int>> dq; // 해당 배열의 값, 해당 배열의 인덱스 값
    // 배열의 값은 최솟값 찾는데 필요하지만, 인덱스는 왜?
    // 바로 덱이 현재 구간을 탐색할때 영향을 미칠 수 있는가를 판단하기 위함.

    int num;
    for (int i = 0; i < n; i++)
    {
        while (dq.size() && dq.front().second <= i - l)
            dq.pop_front();
        // 만약 덱이 비어있지 않고, 덱에 남아있는 원소의 인덱스가 i-l보다 크다면
        // 팝해!(프론트부터 팝하는 이유는 앞에 있을 수록 인덱스가 당연히 작기 때문)
        //  "인덱스 번호를 통해서 현재 탐색 구간에 영향을 미칠 수 있는 데이터인지 아닌지" 를 판단하는 조건문

        cin >> num;
        while (dq.size() && dq.back().first >= num)
            dq.pop_back();
        // 만약 덱이 비어있지 않고, 니가 입력한 숫자가, 가장 최근(덱의 가장 뒤)에 들어온
        //  숫자보다 작다면, 덱의 원소를 뒤에부터 팝해.
        //  현재 구간에서의 최솟값이 되는지와 다음 구간에서의 최솟값의 후보가 될 수 있는지 " 에 대해서 판단하는 조건문

        dq.push_back({num, i});
        cout << dq.front().first << ' ';
    }

    return 0;
}