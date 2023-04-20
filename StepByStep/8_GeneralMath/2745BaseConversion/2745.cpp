#include <iostream>
#include <string>

using namespace std;

int main()
{
    string n; // input number in base B
    int b;    // base B
    cin >> n >> b;

    int result = 0;
    int power = 1;
    for (int i = n.size() - 1; i >= 0; i--)
    {
        int digit;
        if (n[i] >= '0' && n[i] <= '9')
        {
            digit = n[i] - '0';
        }
        else
        {
            digit = n[i] - 'A' + 10;
        }
        result += digit * power;
        power *= b;
    }

    cout << result << endl;

    return 0;
}