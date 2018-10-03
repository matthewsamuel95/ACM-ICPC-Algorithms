/* **** A Greedy algorithm that never uses more than D+1 colors to color all the vertices of a graph, where D is the maximum degree in the graph  *** */
/* **** Complexity = O(V^2 + E) where V is number of vertices and E is number of edges *** */
/* **** This is written in C++14 *** */

#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

struct Edge {
    int sourceVertex, destinationVertex;
};

//You can add Other Colors too
string color[] =
{
    "", "BLUE", "GREEN", "RED", "YELLOW", "ORANGE", "PINK",
    "BLACK", "BROWN", "WHITE", "PURPLE", "VOILET"
};

class Graph
{
    public:
    vector<int> *adjacencyList;
    Graph(vector<Edge> const &edges, int N)
    {
        adjacencyList = new vector<int>[N];
        for (int i = 0; i < edges.size(); i++)
        {
            int src = edges[i].sourceVertex;
            int dest = edges[i].destinationVertex;
            adjacencyList[src].push_back(dest);
            adjacencyList[dest].push_back(src);
        }
    }
    ~Graph() {
        delete[] adjacencyList;
    }
};

void colorGraph(const Graph &graph, int N)
{
    map<int, int> result;
    for (int u = 0; u < N; u++)
    {
        set<int> assigned;
        for (int i : graph.adjacencyList[u]) {
            if (result[i]) {
                assigned.insert(result[i]);
            }
        }
        int color = 1;
        for (auto &c: assigned ) {
            if (color != c) {
                break;
            }
            color++;
        }
        result[u] = color;
    }
    for (int v = 0; v < N; v++) {
        cout << "Color assigned to vertex " << v << " is "
             << color[result[v]] << '\n';
    }
}

int main()
{
    int N;
    cout<<"\nEnter number of vertices in the graph : ";
    cin>>N;

    int E;
    cout<<"\nEnter number of edges in the graph : ";
    cin>>E;

    int temp1, temp2;
	cout << "\nEnter edges in pair ,where each pair is represented by starting vertex and ending vertex.";
	cout<<"\nVertex number starts from 0 till "<<N-1;
	cout << "\nFor Example, edge between vertex 4 and vertex 5 is given like \n4 5\n";

	vector<Edge> edges;
	int counter=E;
	while(E--)
    {
        temp1=-1;
        temp2=-1;

        while(temp1<0 || temp2<0 || temp1>=N || temp2>=N)
        {
            cout << "\nEnter Edge "<< counter - E -1<<" According to above format\n";
            cin>>temp1;
            cin>>temp2;
        }
        edges.push_back({temp1,temp2});

    }
    /*
    edges =
    {
        {0, 1}, {0, 4}, {0, 5}, {4, 5}, {1, 4}, {1, 3}, {2, 3}, {2, 4}
    };
    */
    Graph graph(edges, N);
    colorGraph(graph, N);
    return 0;
}
