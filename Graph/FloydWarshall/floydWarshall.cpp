#include <bits/stdc++.h>
using namespace std;

#define maxn 1009
#define inf 10000009

int graph[maxn][maxn];
int dist[maxn][maxn];

void floydWarshall(int v){
	for(int k=0;k<v;k++){
		for(int i=0;i<v;i++){
			for(int j=0;j<v;j++){
				dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
			}
		}
	}
}

int main(){
	
	int numV, numE;
	cin>>numV>>numE;	
	
	for(int i=0;i<numV;i++){
		for(int j=0;j<numV;j++){			
			dist[i][j]=inf;
			if(i==j)dist[i][j]=0;
		}
	}

	for(int i=0;i<numE;i++){
		int u,v,w;
		// Assuming 0-based indexing
		cin>>u>>v>>w;
		graph[u][v]=w;
		dist[u][v]=w;
		// undirected graph
		graph[v][u]=w;		
		dist[v][u]=w;
	}	
	

	floydWarshall(numV);

	for(int i=0;i<numV;i++){
		for(int j=0;j<numV;j++){
			if(dist[i][j]==inf){
				cout<<"inf\t";continue;
			}
			cout<<dist[i][j]<<"\t";
		}cout<<endl;
	}	

}
