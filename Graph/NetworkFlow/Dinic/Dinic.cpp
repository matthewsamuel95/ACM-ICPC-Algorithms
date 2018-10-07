#include <iostream>
#include <vector>
#include <climits>

/**
 * Dinic's algorithm is a strongly polynomial algorithm for computing
 * the maximum flow in a flow network, conceived in 1970 by Yefim A. Dinitz.
 * The algorithm runs in O(E*V^2) time and is similar to the Edmonds–Karp algorithm,
 * which runs in O(V*E^2) time, in that it uses shortest augmenting paths.
 *
 * This implementation calculates maximum flow between the first and the last vertexes.
 *
 * @see https://en.wikipedia.org/wiki/Dinic%27s_algorithm
 */

using namespace std;

class graph {
public:

    graph(unsigned vertexes) {
        V = vertexes;
        s = 0;
        t = V - 1;
        g.resize(V);
        d.resize(V);
        ptr.resize(V);
        queue.resize(V);
    }

    int dinic() {
        int flow = 0;
        while (true) {
            if (!bfs()) break; // Break if vertex [t] is not reachable from vertex [s]
            ptr.assign(V, 0);
            while (int pushed = dfs(s, INT_MAX))
                flow += pushed;
        }
        return flow;
    }

    void addEdge(unsigned v1, unsigned v2, unsigned capacity) {
        v1--; // Remove these decrements if
        v2--; // vertexes are numbered from zero
        edge e1 = {v1, v2, capacity, 0};
        edge e2 = {v2, v1, 0, 0};
        g[v1].push_back((int) e.size());
        e.push_back(e1);
        g[v2].push_back((int) e.size());
        e.push_back(e2);
    }

private:
    struct edge {
        int a, b, capacity, flow;
    };

    unsigned V;
    unsigned s, t;
    vector<edge> e;
    vector<vector<int>> g; // Graph adjacency list
    vector<int> d; // d[u] is a shortest path from [s] to [u]
    vector<int> ptr; // ptr[u] is a number of the first edge
                     // in [u] adjacency list, that was not removed
    vector<int> queue;


    bool bfs() {
        int qhead = 0, qtail = 0;
        queue[qtail++] = s;
        d.assign(V, -1);
        d[s] = 0;
        while (qhead < qtail && d[t] == -1) {
            int v = queue[qhead++];
            for (size_t i = 0; i < g[v].size(); ++i) {
                int id = g[v][i],
                        to = e[id].b;
                if (d[to] == -1 && e[id].flow < e[id].capacity) {
                    queue[qtail++] = to;
                    d[to] = d[v] + 1;
                }
            }
        }
        return d[t] != -1;
    }

    // Finding the blocking flow
    // `minflow` is a minimal capacity on the path of the level graph
    int dfs(int v, int minflow) {
        if (!minflow) return 0;
        if (v == t) return minflow;
        for (; ptr[v] < (int) g[v].size(); ++ptr[v]) {
            int id = g[v][ptr[v]],
                    to = e[id].b;
            if (d[to] != d[v] + 1) continue;
            int pushed = dfs(to, min(minflow, e[id].capacity - e[id].flow));
            if (pushed) {
                e[id].flow += pushed;
                e[id ^ 1].flow -= pushed;
                return pushed;
            }
        }
        return 0;
    }
};

int main(int argc, char **argv) {
    graph g(4); // Create graph with 4 vertexes

    g.addEdge(1, 2, 1); // [1] --(1)--> [2]
    g.addEdge(1, 3, 2); // [1] --(2)--> [3]
    g.addEdge(3, 2, 1); // [3] --(1)--> [2]
    g.addEdge(2, 4, 2); // [2] --(2)--> [4]
    g.addEdge(3, 4, 1); // [3] --(1)--> [4]

    cout << "Maximum flow: " << g.dinic();
    return 0;
}