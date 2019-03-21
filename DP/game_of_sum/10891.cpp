#include <iostream>
#include <string.h>
using namespace std;
#define inf 999999
#define max(a,b) a > b ? a : b
int n ;
int dp[105][105];
int a[105],sum[105];

int get_sum(int i , int j){
    return sum[j]-sum[i-1];
}
int solve(int l, int r)
{
    if(l > r) return 0;
    if(l == r) return a[l];
    int &ret = dp[l][r];
    if(ret != -1) return ret;
    ret = -inf ;
    for(int i = l; i <= r; i++)
    {
        ret = max(ret, get_sum(l,i) - solve(i+1, r));
        ret = max(ret, get_sum(i,r) - solve(l, i-1));
    }
    return ret;
}
int main()
{
    while(cin >> n && n){
        memset(sum,0,sizeof sum);
        for(int i = 1 ; i <= n ; i++ ) {
            cin >> a[i];
            sum[ i ] = sum[ i-1 ] + a[i] ;
        }
        memset(dp,-1,sizeof dp);
        int ret = solve(1,n);
        cout << ret << endl;
    }
}