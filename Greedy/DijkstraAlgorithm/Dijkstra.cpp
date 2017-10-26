#include<iostream>
#include<set>
#include<utility>
#include<vector>
#include<climits>

using namespace std;

vector<pair<int,int> > adj[1001];

void init(int dist[],int nodes)
{
	for(int i=0;i<=nodes;++i)
	dist[i]=INT_MAX;
}

int dijkstra(int start,int end,int nodes)
{
	multiset<pair<int,int> > ms;
	int dist[nodes+1];
	init(dist,nodes);
	dist[start]=0;
	int vis[nodes+1]={0};
	ms.insert({dist[start],start});
	while(!ms.empty())
	{
		pair<int,int> temp=*ms.begin();
		ms.erase(ms.begin());
		if(vis[temp.second])continue;
		vis[temp.second]=1;
		for(int i=0;i<adj[temp.second].size();++i)
		{
			pair<int,int> p=adj[temp.second][i];
			if(vis[p.first])continue;
			
			if(dist[p.first]>dist[temp.second]+p.second )
			{
				dist[p.first]=dist[temp.second]+p.second;
				ms.insert({dist[p.first],p.first});
			}
		}		
	}
	ms.clear();
	return dist[end];
}

int main()
{
	int nodes,edges;
	cout<<"Enter no of nodes : "; 
	cin>>nodes;
	cout<<"Enter no of edges : "; 
	cin>>edges;
	cout<<"Enter the edges with weight: \n";
	
	for(int i=0;i<edges;++i)
	{
		int x,y,weight;
		cin>>x>>y>>weight;
		adj[x].push_back({y,weight});
		adj[y].push_back({x,weight});
	}
	cout<<"Enter two nodes to find minimum distance between them : ";
	int start,end;
	cin>>start>>end;
	cout<<dijkstra(start,end,nodes);
	
	return 0;
}
