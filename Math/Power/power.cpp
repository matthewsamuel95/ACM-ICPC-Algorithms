#include <iostream>
using namespace std;

double power(double x, int n)
{
    if (n == 0)
        return 1.00;
    if (n == 1)
        return x;
    double ans = power(x, n / 2);
    if (n % 2 == 0)
        return ans * ans;
    else if (n < 0)
        return ans * ans / x;
    else
        return ans * ans * x;
}

int main()
{
    double n, p;
    // n is the number and p is the power...
    cin >> n >> p;

    double ans = power(n, p);
    cout << ans << endl;

    return 0;
}
