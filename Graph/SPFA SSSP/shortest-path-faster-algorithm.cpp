//This algorithm does the same thing as bellman ford and has the same time complexity but is constant time faster
//look idk how to do all he fancy struct stuff. so dont complain or just use the bellman ford
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
queue<int> q;
const int N=10003; // put number of nodes+3 here PLS CHANGE THIS ACCORDINGLY
int w[N],c2[N];//w is shortest path to a node, c2 is number of time a node has been relaxed
bool c[N];//c is to check whether a certain node is in the queue
vector<ii> data [N]; //adjacency list of graph
void edge(int x,int y, int l){ //there is a directed edge from x to y with length l
    data[x].push_back(ii (y,l));
}
void initialize(){//initialize variables, may not be the fastest
    memset(c2,0,sizeof(c2)); //i apologize for using memset
    memset(c,true,sizeof(c));
    memset(w,63,sizeof(w)); //depends on largest path from 1 node to another IMPORTANT
    for (int x=0;x<N;x++){
        data[x].clear();
    } //note that the algorithm until the queue is empty so there is no need to initialize queue
}
void setup(int s){//s is the source node
    q.push(s);
    w[s]=0;
}
void bfs(int x){ //this is no mark everything under the negative weight cycle as inf length
    int l=data[x].size(),a;
    for (int y=0;y<l;y++){ //for each of x neighbour
        a=data[x][y].first;
        if (c2[a]<N){ // if neighbour is not marked as -INF length
            c2[a]=N; //mark it as such
            bfs(a); //mark all its neighbours as such
        }
    }
}
void SPFA(){
    int n,l,u,d;
    while (!q.empty()){
    n=q.front(); // n is node to relax neighbours
    q.pop();
    if (c2[n]>=N) continue; // if n is part of negative weight cycle, ignore
    c[n]=true; //mark n is not in queue
    l=data[n].size(); //just for constant time improvement
    for (int x=0;x<l;x++){
        u=data[n][x].first;
        d=data[n][x].second;
        if (w[u]>w[n]+d){ // if u can be relaxed
            w[u]=w[n]+d; //relaxing u
            c2[u]++;// count number of time u has been relaxed. as u can only be relaxed N-1 times if its not in negative weight cycle
            if (c2[u]==N){ //if n in is negative wieght cycle
                bfs(u); //mark all of u neighbours as - INF weight
            }
            else if (c[u]){ //if u is not in queue
                c[u]=false; //mark u is in queue
                q.push(u); //push u into queue
            }
        }
    }
    }
}
void print(int n){ // print length of shortest path
    if (c2[n]>=N){
        printf("-Infinity\n"); //part of negative wieght cycle
    }
    else if (w[n]==1061109567){
        printf("Impossible\n"); //unreachable form source node
    }
    else{
        printf("%d\n",w[n]); //else just print its shortest path
    }
}
int main(){ // the example graph has 5 nodes and 4 edges
    initialize(); //pls initialize or weird stuff might happen
    edge(0,1,999);
    edge (1,2,-2);
    edge(2,1,1);
    edge (0,3,2);
    setup(0); //0 is source node
    SPFA();
    print(1);
    print(3);
    print(4);
    return 0;
}
