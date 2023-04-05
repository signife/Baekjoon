#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char *argv[])
{
    string S;
    int i;
    ios_base::sync_with_stdio(false);

    cin >> S >> i;
    cout << S[i - 1] << endl;

    return 0;
}