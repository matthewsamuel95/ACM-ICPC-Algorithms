#include<bits/stdc++.h>

using namespace std;

#define ll long long
int main()
{
	ll n,w,i,j;
	cin>>n>>w;
	ll val[n],weight[n];
	for(i=0;i<n;i++)
	{
		cin>>weight[i]>>val[i];
	}
	ll dp[n+1][w+1];
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=w;j++)
		{
			if(i==0||j==0)
				dp[i][j]=0;
			else if(j>=weight[i-1])
			dp[i][j]=max(val[i-1]+dp[i-1][j-weight[i-1]],dp[i-1][j]);
			else
			dp[i][j]=dp[i-1][j];
		}
	}
	cout<<dp[n][w];
	return 0;
}