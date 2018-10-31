#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
#define ms(a, n) memset(a,n,sizeof(a)) 
#define pb push_back
#define mp make_pair
#define f first
#define se second
#define prec(n) fixed<<setprecision(n)

vector<vector<pair<ll,ll> > >gr(200001);
vector<bool>vis(200001,0);
vector<ll>dist(200001,0);          // distance of the index from the source
void dfs(ll cur)
{
	vis[cur]=1;
    for(auto i:gr[cur])
	{
        if(!vis[i.f])
		{
            dist[i.f]=dist[cur]+i.se;
        	dfs(i.f);
		}
	}
}

int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		ll a,b,c;
		cin>>a>>b>>c;
		gr[a].pb(mp(b,c));
		gr[b].pb(mp(a,c));  //comment if directed graph
	}
	dfs(1);
	for(int i=1;i<n+1;i++)
	cout<<dist[i]<<" ";
}
