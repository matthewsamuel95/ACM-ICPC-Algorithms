#include<bits/stdc++.h>
#define turbo() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define mod (1000000007)
#define inf ((ll)1e18)
#define eps (1e-9)
#define ff first
#define ss second
#define pb push_back
#define endl "\n"
using namespace std;

vector<vector<int>> adj;
vector<int> dfs_low , dfs_num , dfs_parent; 
vector<pair<int , int> > res;
int dfscnt = 1;
void dfs(int u)
{
	dfs_low[u] = dfs_num[u] = dfscnt++;
	for(int x : adj[u])
	{
		if(dfs_num[x] == 0)
		{
			dfs_parent[x] = u;
			dfs(x);
			if(dfs_low[x] > dfs_num[u])
				res.push_back({u , x});
			dfs_low[u] = min(dfs_low[u] , dfs_low[x]);
		}
		else if(x != dfs_parent[u])
			dfs_low[u] = min(dfs_low[u] , dfs_num[x]);

	}
}

int main()
{
	int n = 10 ; // number of vertices;
	// cin>>n;
	int m = 15 ; // number of edges;
	// cin>>m;
	adj.resize(n + 1);
	dfs_low.resize(n + 1);
	dfs_num.resize(n + 1);
	dfs_parent.resize(n + 1);
	// store the adj list int adj;
	for(int i = 0 ; i < m ; i++ )
	{
		int x , y;
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	dfs(1);
	cout<<"Bridges:\n";
	for(auto x : res)
	{
		cout<<x.ff<<" "<<x.ss<<endl;
	}
	return 0;
}