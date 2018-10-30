#include <iostream>
#include <list>
#include <limits.h>

using namespace std;

class Graph
{
  int V;
  list<int> *adj;
  bool isCyclicUtil(int v, bool visited[], int parent);
  public:
    Graph(int v);
    void addEdge(int v, int w);
    bool isCyclic();
};

Graph::Graph(int V)
{
  this->V = V;
  adj = new list<int>[V];
}

void Graph::addEdge(int v,int w)
{
  adj[v].push_back(w);
  adj[w].push_back(v);
}

bool Graph::isCyclicUtil(int v, bool visited[], int parent)
{
  visited[v]=true;

  list<int>::iterator i;
  for(i=adj[v].begin(); i!=adj[v].end(); ++i)
  {
    if(!visited[*i])
    {
      if(isCyclicUtil(*i,visited,v))
        return true;
    }
    else if (*i != parent)
      return true;
  }
  return false;
}

bool Graph::isCyclic()
{
  bool *visited = new bool[V];
  for(int i=0;i<V;i++)
  {
    visited[i]=false;
  }
  for(int u=0;u<V;u++)
    if(!visited[u])
      if(isCyclicUtil(u, visited, -1))
        return true;

  return false;
}

int main()
{
  Graph g1(9);
  g1.addEdge(7,6);
  g1.addEdge(6,5);
  g1.addEdge(2,8);
  g1.addEdge(3,4);
  g1.addEdge(5,4);
  g1.addEdge(2,5);
  g1.addEdge(0,1);
  g1.addEdge(1,2);
  g1.isCyclic()? cout << "Graph is Cyclic" << endl:
                 cout << "Graph is Not Cyclic" << endl;
  return 0;
}
