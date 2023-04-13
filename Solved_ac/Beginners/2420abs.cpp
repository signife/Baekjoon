#include <iostream>
#include <cmath>

int main()
{
    long long N, M;
    std::cin >> N >> M;

    long long diff = std::abs(N - M);

    std::cout << diff << std::endl;

    return 0;
}