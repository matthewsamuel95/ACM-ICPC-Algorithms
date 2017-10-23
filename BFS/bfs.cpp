#include <iostream>
#include <queue>
#include <vector>
#include <iomanip>

using namespace std;

class Graph {
  public:
    // initialize verticies with constructor
    Graph(int num_nodes) 
      : adj_list(num_nodes), dist(num_nodes, -1) {}

    void add_edge(int start, int end);
    vector<vector<int>> adj_list;
    vector<int> dist;
};

void BFS(Graph& g, int source);
void print(const Graph& g);

/*
Input Format:
  nodes edges source
  edge start end
  edge start end
  edge start end
  edge start end
  edge start end
  edge start end

Input Example:
  6 6 0
  0 1
  0 2
  2 3
  2 4
  3 5
  4 5

Output: 
  source: 0
  node ids: 0 1 2 3 4 5 
  distance: 0 1 1 2 2 3 

*/


int main() {
  // node id starts at 0
  int nodes, edges, source;
  cin >> nodes >> edges >> source;
  Graph g(nodes);
  // add directed edges to graph g
  for (int i = 0; i < edges; ++i) {
    int start, end;
    cin >> start >> end;
    g.add_edge(start, end);
  }

  BFS(g, source);
  cout << "Source: " << source << endl; 
  print(g); // prints dist array

  return 0;
}

void Graph::add_edge(int start, int end) {
  adj_list[start].push_back(end);
}

// prints the vertices on the first row
// prints the dist array on the second row
void print(const Graph& g) {
  cout << "node ids: ";
  for (unsigned int i = 0; i < g.adj_list.size(); ++i) {
    cout << setw(3) << i << " ";
  }
  cout << endl << "distance: ";
  for (auto distance : g.dist) {
    cout << setw(3) << distance << " ";
  }
  cout << endl;
}

void BFS(Graph& g, int source) {
  vector<bool> visited(g.adj_list.size(), false);
  queue<int> q;
  q.push(source);
  // initialize visited and dist vector
  visited[source] = true;
  g.dist[source] = 0;

  while(!q.empty()) {
    int cur_node = q.front();
    vector<int> cur_node_adj = g.adj_list[cur_node];
    // iterate through cur_node's adj_list
    for (unsigned int i = 0; i < cur_node_adj.size(); ++i) {
      int adj_node = cur_node_adj[i];
      if (visited[adj_node] == false) {
        visited[adj_node] = true;
        g.dist[adj_node] = g.dist[cur_node] + 1;
        q.push(adj_node);
      }
    }
    q.pop();
  } // end while q is not empty
}
