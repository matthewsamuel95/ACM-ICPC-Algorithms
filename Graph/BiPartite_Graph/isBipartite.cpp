// sandeep_007	

#include <bits/stdc++.h>
 
using namespace std;
 
#define PI acos(-1)
#define mod 1000000007
#define ll long long
#define nitro std::ios_base::sync_with_stdio (false); cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define INV 333333336
#define arr(a,n) for(ll i=0;i<n;i++) cin >> a[i];
#define all(v) (v).begin(),(v).end()
#define br cout<<endl

vector < int > adj[100005];
bool vis[100005];
int dist[100001];

int bfs(int u,int n){
	queue < int > q;
	q.push(u);
	vis[u]=true;
	dist[u]=0;
	while(!q.empty()){
		int a = q.front();
		q.pop();
		vis[a]=true;
		for(auto v:adj[a]){
			if(dist[v] == INT_MAX)
				dist[v] = !dist[a];
			if(dist[v] != INT_MAX and dist[v] != (!dist[a]))
				return 0;
			if(!vis[v]){
				q.push(v);	
			}
		}		
	}
	return 1;
}

bool isBipartite(int n){
	for(int i=1;i<=n;i++){
		if(!vis[i] and bfs(i,n) == 0){
			return 0;
		}
	}
	return 1;
}

int main(){
	nitro;

	#ifdef DBG
		freopen("in","r",stdin);
	#endif
	
	int n,m; cin >> n >> m;
	int a,b;	
	for(int i=0;i<m;i++){
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}	
	for(int i=0;i<=n;i++) vis[i]=false;
	for(int i=1;i<=n;i++) dist[i]=INT_MAX;
	
	
	cout << isBipartite(n); br;	
	return 0;	
}