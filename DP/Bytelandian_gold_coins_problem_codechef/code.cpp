#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long int
/*
Problem Statement:In Byteland they have a very strange monetary system.

Each Bytelandian gold coin has an integer number written on it. A coin n can be exchanged in a bank into three coins: n/2, n/3 and n/4.
But these numbers are all rounded down (the banks have to make a profit).

You can also sell Bytelandian coins for American dollars. The exchange rate is 1:1. But you can not buy Bytelandian coins.

You have one gold coin. What is the maximum amount of American dollars you can get for it?

Example: input = 12 output = 13
            -> you can change 12 into 6 , 4 , 3 which sums up to 13.

Explanation:
        let input = n
        so output = max(n,( (output of n/2) + (output of n/3) + (output of n/4) ))
        to store the output of n/2 , n/3 , n/4 , i use an array to reduce the time for multiple calculation of output of n/2 , n/3 , n/4 in sub steps.

*/

ull check(ull n,ull *a)
{
    if(n<12)
        return n;
    if(a[n])
        return a[n];
    return a[n]= max(n,check((n/2),a)+check((n/3),a)+check((n/4),a));

}
int main()
{
    ull n;
    while(cin>>n)
    {
        ull *a = new ull[n+1];
        ull ans= check(n,a);
        cout<<ans<<endl;
    }
    return 0;
}
