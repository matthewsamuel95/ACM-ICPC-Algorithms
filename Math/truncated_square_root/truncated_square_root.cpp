#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef long long int lli;

lli flrSqrt(lli n) { // using binary search to calculate square root
    if (n == 0 || n == 1) return n;
    lli start = 0, end = n/2, ans;
    while (start <= end) {
        lli mid = (start + end) >> 1;
        if (mid*mid == n) return mid;
        else if (mid*mid < n) {
            start = mid + 1;
            ans = mid;
        }
        else end = mid - 1;
    }
    return ans;
}

int main() {
    lli n;
    cout<<"Enter an integer: "<<endl;
    cin>>n;
    if (n < 0) return 0;
    printf("Square root of %lld is: %lld\n",n,flrSqrt(n));
    return 0;
}