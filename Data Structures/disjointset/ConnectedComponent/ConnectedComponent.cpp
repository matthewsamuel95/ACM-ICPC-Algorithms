#include<iostream>
#include<vector>
using namespace std;

class DSU{
	std::vector<int> parent;
	int connected_component;
public:
	DSU(int n){ parent = vector<int>(n,-1); connected_component = n; }
	int findParent(int n){
		if(parent[n] == -1)
			return n;
		parent[n] = findParent(parent[n]); //Path Compression
		return parent[n];
	}
	void unionSet(int a,int b){
		int x = findParent(a);
		int y = findParent(b);
		if(x!=y){
			parent[x] = y;
			connected_component--;
		}
	}
	int getConnectedComponent(){return connected_component;}
};

/*
Input Format:
First line consists of 2 integers, 'n' and 'e' denoting number of nodes and edges respectively.
The next 'e' lines each contain 2 integers x and y, where 1<=x,y<=n, denoting an edge between node x and node y
*/
int main(){
	int n,e;
	cin>>n>>e;
	DSU d(n);
	int x,y;
	while(e--){
		cin>>x>>y;
		d.unionSet(x,y);
	}
	cout<<"\nNumber of connected components : "<<d.getConnectedComponent()<<endl;
}
