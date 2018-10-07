#include<iostream>
#include<vector>
#include<queue>

using namespace std;



struct Graph{
	int v;
	bool **adj;
	public:
		Graph(int vcount);
		void addEdge(int u,int v);
		void deleteEdge(int u,int v);
		vector<int> BFS(int s);
		vector<int> DFS(int s);
		void DFSUtil(int s,vector<int> &dfs,vector<bool> &visited);
		int countComponents();
		bool isSameComponent(int v1, int v2);
};

Graph::Graph(int vcount){
	this->v = vcount;
	this->adj=new bool*[vcount];
	for(int i=0;i<vcount;i++)
		this->adj[i]=new bool[vcount];
	for(int i=0;i<vcount;i++)
		for(int j=0;j<vcount;j++)
			adj[i][j]=false;
}

void Graph::addEdge(int u,int w){
	this->adj[u][w]=true;
	this->adj[w][u]=true;
}

void Graph::deleteEdge(int u,int w){
	this->adj[u][w]=false;
	this->adj[w][u]=false;
}

vector<int> Graph::BFS(int s){
	vector<bool> visited(this->v);
	vector<int> bfs;
	queue<int> que;
	que.push(s);
	visited[s]=true;
	while(!que.empty()){
		bfs.push_back(que.front());
		for(int i=0;i<this->v;i++){
			if(adj[que.front()][i]==true && visited[i]==false){
				visited[i]=true;
				que.push(i);
			}
		}
		que.pop();
	}
	return bfs;
}

void Graph::DFSUtil(int s, vector<int> &dfs, vector<bool> &visited){
	visited[s]=true;
	dfs.push_back(s);
	for(int i=0;i<this->v;i++){
		if(this->adj[s][i]==true && visited[i]==false)
			DFSUtil(i,dfs,visited);
	}
}

vector<int> Graph::DFS(int s){
	vector<bool> visited(this->v);
	vector<int> dfs;
	DFSUtil(s,dfs,visited);
	return dfs;
}


int Graph::countComponents(){
//write this function using either BFS or DFS
	vector<bool> visited(this->v);
	vector<int> dfs;
	int count=0;
	int source;
	while(true)
	{
		source=-1;
		for (int i = 0; i < visited.size(); ++i)
		{
			if(visited[i]!=true)
			{
				source=i;
				break;
			}
		}

		if(source!=-1)
		{
			count++;
			DFSUtil(source,dfs,visited);
		}
		else if(source==-1)
			break;
	}

    return count;
}



bool Graph::isSameComponent(int v1, int v2){
//write this function using either BFS or DFS
	vector<int> Bfs=this->BFS(v1);
	for(int i=0;i<Bfs.size();i++)
	{
		if(Bfs[i]==v2)
			return(true);
	}
return(false);
}


