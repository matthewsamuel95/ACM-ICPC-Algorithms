#include <iostream>

/**
 * nextpow2 - Implementation of Next Power of 2
 */
int nextpow2(int n)
{
    int c = 0;
    if (n < 1)
        return 1;
    --n;
    while (n)
    {
        ++c;
        n >>= 1;
    }
    return 1 << c;
}

int main()
{
    int n;
    std::cin >> n;
    std::cout << nextpow2(n) << '\n';
    return 0;
}