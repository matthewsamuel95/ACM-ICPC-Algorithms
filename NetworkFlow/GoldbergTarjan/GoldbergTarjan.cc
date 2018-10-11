#include <bits/stdc++.h>
using namespace std;

const int N = 100 , INF = (int)2e9; // Max nodes and flow

int nodes,        // number of nodes
    F[N+2][N+2],  // flow
    C[N+2][N+2],  // edge cap
    xf[N+2],      // excess flow
    ht[N+2],      // height
    nxt[N+2];     // adjacent node pointer

inline void pushExcess(int u, int v) {
  int df = min(xf[u] , C[u][v] - F[u][v]);
  F[u][v] += df , F[v][u] -= df;
  xf[u] -= df, xf[v] += df;
}

inline void relabelNode(int u){
  int min_ht = 2*nodes;
  for(int v = 0; v < nodes; v++)
    if( C[u][v] > F[u][v] ) min_ht = min(min_ht,ht[v]);
  ht[u] = min_ht+1;
}

void discharge(int u) {
  while( xf[u] > 0 ) {
    int v = nxt[u];
    if( v < nodes ) { // push excess flow downhill
      if( C[u][v] > F[u][v] and ht[u] > ht[v] ) pushExcess(u,v);
      else ++nxt[u];
    } else { // relabel and rewind
      relabelNode(u); nxt[u] = 0;
    }
  }
}

int GoldbergTarjan(int src=0, int sink=nodes-1) {
  fill(xf,xf+nodes,0);
  fill(ht,ht+nodes,0);
  fill(nxt,nxt+nodes,0);

  int list[nodes-2];
  for(int i=0,j=0;i<nodes;i++) {
    if( i==src or i==sink ) continue;
    list[j++] = i;
  }

  ht[src] = nodes; xf[src] = INF;
  for(int i=0;i<nodes;i++)
    if(i != src) pushExcess(src,i);

  int index = 0;
  while( index < nodes-2 ) {
    int u = list[index];
    int prev_ht = ht[u];
    discharge(u);
    if( ht[u] > prev_ht ) { // move to front
      for(int j=index-1;index>0;index--,j--)
        list[index] = list[j];
      list[0] = u;
    } else {
      index++;
    }
  }

  int maxFlow = 0;
  for(int v = 0; v < nodes; v++)
    maxFlow += F[src][v];
  return maxFlow;
}



int main() {

  cin >> nodes;
  for(int i=0; i<nodes; i++) {
    for(int j=0; j<nodes; j++) {
      cin >> C[i][j];
      F[i][j] = 0;
    }
  }

  int max_flow = GoldbergTarjan(0, nodes-1);
  cout << max_flow << endl;

  return 0;
}
