//#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <climits>
#define SZ(x) (int)((x).size())
#define PII pair<int,int>
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long LL;
const int INF=1000006;
char s[1005],t[1005];	// string s,t
int dp[1005][1005];		// dp chart
void input () {
	scanf("%s",s);
	scanf("%s",t);
}
int solve () {
	int n=strlen(s);
	int m=strlen(t);
	for ( int i=0; i<=n; i++ ) dp[i][0]=1;
	for ( int i=0; i<=m; i++ ) dp[0][i]=INF;
	for ( int i=1; i<=n; i++ ) {
		for ( int j=1; j<=m; j++ ) {
			char x=s[i-1];
			int k;
			for ( k=j-1; k>=0; k-- ) 
				if ( t[k]==x ) break;
			if ( k==-1 ) dp[i][j]=1;
			else dp[i][j]=min(dp[i-1][j],dp[i-1][k]+1);
		}
	}
	if ( dp[n][m]==INF ) return -1;
	else return dp[n][m];
}
int main ()
{
	input();
	printf("%d\n",solve());
	return 0;
}

