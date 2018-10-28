#include <bits/stdc++.h>
#define MAXN 10000

using namespace std;

stack <int> order;
vector<int> adjlist[MAXN];
int visitados [MAXN];

void dfs(int u){
    visitados[u] = 1;
    for(int j = 0; j < (int)adjlist[u].size(); j++){
        int v = adjlist[u][j];
        if(visitados[v] == 0){
            dfs(v);
        }
    }
    order.push_back(u);
}
