#include <stdio.h>
#include <vector>
 using namespace std;
 #define max 100
#define lg_max 7
 vector<int> graph[max];
int parent[max][lg_max], level[max], lg[max];
int n;
 void log(){
    for(int i=2; i<max; i++) lg[i] = lg[i/2] + 1;
}
 void dfs(int u, int p){
    for(auto v: graph[u]){
        if(v != p){
            level[v] = level[u] + 1;
            parent[v][0] = u;
            dfs(v,u);
        }
    }
}
 void build(){
    for(int j=1; j<=lg[n]; j++){
        for(int i=1; i<=n; i++){
            parent[i][j] = parent[parent[i][j-1]][j-1];
        }
    }
}
 int lca(int u, int v){
    if(level[u] < level[v]) return lca(v, u);
    for(int i=lg[n]; i>=0; i--){
        if(level[u] - (1<<i) >= level[v]){
            u = parent[u][i];
        }
    }
    if(u == v) return u;
    for(int i=lg[n]; i>=0; i--){
        if(parent[u][i] != parent[v][i]){
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}
 int main(){
    log();
    int x, y;
    scanf("%d", &n);
    for(int i=0; i<n-1; i++){
        scanf("%d%d", &x, &y);
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs(1,1);
    build();
    scanf("%d%d", &x, &y);
    printf("%d\n", lca(x, y));
}
