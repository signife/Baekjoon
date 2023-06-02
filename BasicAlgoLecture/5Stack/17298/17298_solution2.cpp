#include <cstdio>
#include <stack>

using namespace std;
int n, numbers[1000001], ans[1000001];

int main()
{

    stack<int> st = stack<int>();

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &numbers[i]);

    st.push(numbers[n - 1]); // 가장 오른쪽에 있는 수는 stack에 push
    ans[n - 1] = -1;         // 가장 오른쪽의 있는 수는 오큰수가 없으므로 -1
    for (int i = n - 2; i >= 0; i--)
    {                           // 거꾸로 for문
        int value = numbers[i]; // stack의 top과 비교할 숫자
        while (!st.empty() && value >= st.top())
        {             // 스택이 비어있지 않고, 스택의 top이 value보다 작거나 같으면
            st.pop(); // 그 수는 버린다.
        }
        // 이렇게 되면 두가지 상황이 발생하는데,
        // 스택이 비어있으면 value 오른쪽에 오큰수가 없다는 것으로 value의 오큰수는 -1
        // 숫자가 남아있다면 value보다 큰 수가 있는 것으로 오큰수는 st.top
        ans[i] = st.empty() ? -1 : st.top();

        // 그리고 value를 stack에 push
        st.push(value);
    }

    for (int i = 0; i < n; i++)
        printf("%d\n", ans[i]);
    printf("\n");
}