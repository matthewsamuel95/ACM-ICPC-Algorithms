#include <bits/stdc++.h>

typedef long long int lli;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(50);
    lli n,m;
    cin >> n >> m;
    lli a[n][m];
    lli dp[n][m];
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            cin >> a[i][j];
            dp[i][j] = 1e18;
        }
    }
    dp[0][0] = a[0][0];
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            if(j-1 >= 0)
            {
                dp[i][j] = min(dp[i][j],dp[i][j-1] + a[i][j]);
            }
            if(i-1 >= 0)
            {
                dp[i][j] = min(dp[i][j],dp[i-1][j] + a[i][j]);
            }
            if(i-1 >= 0 && j-1 >= 0)
            {
                dp[i][j] = min(dp[i][j],dp[i-1][j-1] + a[i][j]);
            }
        }
    }
    cout << dp[n-1][m-1] << endl;
}
