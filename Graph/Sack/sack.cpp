#include <bits/stdc++.h>

using namespace std;

#define max 100007

vector<int> tree[max];
int weight[max];
vector<int> *nos[max];

void dfs(int u, int p){
    weight[u] = 1;
    for(auto v: tree[u]){
        if(v != p){
            dfs(v, u);
            weight[u] += weight[v];
        }
    }
}

void sack(int u, int p, bool keep){
    int heavy_child = -1;
    for(auto son: tree[u]){
        if(son != p){
            if(heavy_child == -1 || weight[son] > weight[heavy_child]) heavy_child = son;
        }
    }
    for(auto son: tree[u]){
        if(son != p && son != heavy_child) sack(son, u, false);
    }
    if(heavy_child == -1) nos[u] = new vector<int> ();
    else{
        sack(heavy_child, u, true);
        nos[u] = nos[heavy_child];
    } 
    nos[u]->push_back(u);
    //Operation
    for(auto son: tree[u]){
        if(son != p && son != heavy_child){
            for(auto x: *nos[son]){
                nos[u]->push_back(x);
            }
        }
    }

    // Output of sub tree u is ok

    /* Operation
    if(!keep){
        for(auto x: *nos[u]){
            
        }
    }
    */
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i=1; i<n; i++){
        int u, v;
        scanf("%d%d", &u, &v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1,1);
    sack(1,1,true);
}
