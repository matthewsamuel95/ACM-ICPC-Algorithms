#include <bits/stdc++.h>
using namespace std;

#define maxn 1009

int _parent[maxn];
int _rank[maxn];
int n;

void init(){
	for(int i=0;i<n;i++){
		_parent[i]=i;
		_rank[i]=0;
	}
}

int _find(int x){
	if(x!=_parent[x]){
		_parent[x] = _find(_parent[x]);
	}
	return _parent[x];
}

void _union(int x, int y){
	int px = _parent[x];
	int py = _parent[y];
	if(px==py)return;
	if(_rank[px]<_rank[py])
		_parent[px]=py;
	else{
		_parent[py]=px;
		if(_rank[px]==_rank[py])
			_rank[px]++;
	}
}

