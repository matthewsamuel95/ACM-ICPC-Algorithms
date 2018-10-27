#include <bits/stdc++.h>
using namespace std;
 
#define INF 0x3f3f3f3f
#define MOD 1000000007

#define ll long long
#define pb push_back
#define nl printf("\n");
#define vint vector<int>

vector<pair<int,int>>g[100005];
int n;
int dist[100005];
void shortest_path(int s)
{
	for(int i=0;i<100001;i++)
		dist[i]=INF;
	set<pair<int,int>> setds;

	setds.insert({0,s});
	dist[s]=0;
	while(!setds.empty())
	{
		pair<int,int> temp;
		temp=*(setds.begin());
		setds.erase(setds.begin());

		int u=temp.second;
		vector<pair<int,int>>::iterator it;
		for(it=g[u].begin();it!=g[u].end();it++)
		{
			int v = (*it).first;
			int weight = (*it).second;
			if(dist[v] > dist[u] + weight)
			{
				if(dist[v] != INF)
					setds.erase(setds.find({dist[v],v}));

				dist[v]=dist[u] + weight;
				setds.insert({dist[v],v});
			}
		}
	}

	// printf("Vertex   Distance from Source\n");
 //    for (int i = 0; i <= n ; ++i)
 //        printf("%d \t\t %d\n", i, dist[i]);

}

int main()
{
    ifstream myFile("task.in");
    if(!myFile.fail())
    {
        assert(freopen("task.in", "r", stdin));
    }
    int m;
	cin>>n>>m;
	n--;				//starting from 0
    int total=0;
    for(int i=0;i<m;i++)
    {
    	int x,y,w;
    	cin>>x>>y>>w;
    	g[x].pb({y,w});
    	g[y].pb({x,w});
    	total+=w;
    }
    shortest_path(0);
    int ma=0,ind; 
    for(int i=0;i<n;i++)
   		if(dist[i] > ma) 
   			ind=i,ma=dist[i];
   	for(int i=0;100001;i++)
   		dist[i]=INF;
   	shortest_path(ind);
   	for(int i=0;i<n;i++)
   		if(dist[i] > ma) 
   			ind=i,ma=dist[i];
   	cout<<(total - dist[ind]);
   	nl
	return 0;
}
