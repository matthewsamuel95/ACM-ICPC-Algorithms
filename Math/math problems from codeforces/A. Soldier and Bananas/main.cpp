//codeforces.com/problemset/problem/546/A

#include <iostream>

using namespace std;

int main()
{
    int k,i,w;
    long n,sum=0;
    cin>>k>>n>>w;
    for(i=0;i<=w;i++)
    {
        sum+=i;
    }
    sum*=k;
    if(sum<n)
        cout << 0;
    else
        cout << sum-n;
    return 0;
}
