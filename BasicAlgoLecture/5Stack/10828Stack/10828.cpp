#include <iostream>
#include <vector>
#include <map>
using namespace std;

void push(int value);
int pop();
int top();
int size();
bool empty();

int bumzi[1000005];
int pos = 0;

int main(void)
{
    int repeat;
    cin >> repeat;
    cin.ignore();

    // while (repeat--)
    // {
    //     string s;
    //     getline(cin, s);
    //     if (s == "pop")
    //     {
    //         cout << pop() << endl;
    //     }
    //     else if (s == "top")
    //     {
    //         cout << top() << endl;
    //     }
    //     else if (s == "size")
    //     {
    //         cout << size() << endl;
    //     }
    //     else if (s == "empty")
    //     {
    //         if (empty())
    //             cout << 1;
    //         else
    //             cout << 0;
    //     }
    //     else
    //     {
    //         int value = stoi(s.substr(5));
    //         push(value);
    //     }
    // }
    // return 0;
    while (repeat--)
    {
        string c;
        cin >> c;
        if (c == "push")
        {
            int t;
            cin >> t;
            push(t);
        }
        else if (c == "pop")
        {
            if (empty())
                cout << -1 << endl;
            else
            {
                cout << top() << endl;
                pop();
            }
        }
        else if (c == "size")
            cout << size() << endl;
        else if (c == "empty")
            cout << (int)empty() << endl;
        else
        {
            if (empty())
                cout << -1 << endl;
            else
                cout << top() << endl;
        }
    }
}

void push(int value)
{
    bumzi[pos++] = value;
}

int pop()
{
    if (!empty())
        return bumzi[--pos]; // pos--아님
    else
        return -1;
}

int top()
{
    if (!empty())
        return bumzi[pos - 1];
    else
        return -1;
}

int size()
{
    return pos;
}
bool empty()
{
    if (pos == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}