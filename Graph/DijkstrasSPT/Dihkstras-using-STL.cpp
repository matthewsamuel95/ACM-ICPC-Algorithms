// Author - Yash Deshpande 
// (yvdyash)

#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int> > > g(100005);
//vector<bool> vis(100005);
vector<long long> dist(100005,LLONG_MAX);

void shortestpath(int src)
{
	set<pair<long long,int> > s;
	s.insert({0,src});
	dist[src]=0;
	while(!s.empty())
	{
		pair<long long,int> cur_node=*(s.begin());
		s.erase(s.begin());
		int parent=cur_node.second;
		for(int i=0;i<g[parent].size();i++)
		{
			int child=g[parent][i].first;
			long long weight=g[parent][i].second;
			if(dist[child]>dist[parent]+weight)
			{
				if(dist[child]!=LLONG_MAX)
					s.erase(s.find({dist[child],child}));
					
				dist[child]=dist[parent]+weight;
				s.insert({dist[child],child});
			}
		}
	}
}

int main()
{
	int tc;cin>>tc;
	while(tc--){
		int n,e,src,dest;
		cin>>n>>e>>src>>dest;
		for(int i=0;i<=n;i++){
			g[i].clear();
			dist[i]=LLONG_MAX;
		}
		
		while(e--)
		{
			int a,b,c;
			cin>>a>>b>>c;
			g[a].push_back({b,c});
			g[b].push_back({a,c});
		}
		shortestpath(src);
	}
}
