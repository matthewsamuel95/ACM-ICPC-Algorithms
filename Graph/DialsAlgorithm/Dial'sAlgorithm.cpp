
#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f
 
class Graph
{
    int V;  
    list< pair<int, int> > *adj;
 
public:
    Graph(int V);  
    void addEdge(int u, int v, int w);
 
  
    void shortestPath(int s, int W);
};
 

Graph::Graph(int V)
{
    this->V = V;
    adj = new list< pair<int, int> >[V];
}
 
void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}
 

void Graph::shortestPath(int src, int W)
{
    vector<pair<int, list<int>::iterator> > dist(V);
 

    for (int i = 0; i < V; i++)
        dist[i].first = INF;
 

    list<int> B[W * V + 1];
 
    B[0].push_back(src);
    dist[src].first = 0;
 

    int idx = 0;
    while (1)
    {


        while (B[idx].size() == 0 && idx < W*V)
            idx++;

        if (idx == W * V)
            break;
 

        int u = B[idx].front();
        B[idx].pop_front();

        for (auto i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            int v = (*i).first;
            int weight = (*i).second;
 
            int du = dist[u].first;
            int dv = dist[v].first;

            if (dv > du + weight)
            {

                if (dv != INF)
                    B[dv].erase(dist[v].second);
 

                dist[v].first = du + weight;
                dv = dist[v].first;
 

                B[dv].push_front(v);
 

                dist[v].second = B[dv].begin();
            }
        }
    }

    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d     %d\n", i, dist[i].first);
}
 
int main()
{

    int V = 9;
    Graph g(V);
 

    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
 

    g.shortestPath(0, 14);
 
    return 0;
}