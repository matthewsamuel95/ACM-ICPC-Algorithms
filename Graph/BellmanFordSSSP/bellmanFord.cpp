//
// Created by Scarlat Marius on 10/8/20.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int VERTEX_MAX = 1001;
const int INF = (1 << 30);

pair < bool, vector < int > > bellmanFord(const vector < pair < int, int > >& G[VERTEX_MAX], const int& vertices, const int& src) {

    queue < int > q;

    vector < int > inQueueCounter(VERTEX_MAX, 0);
    vector < int > dist(VERTEX_MAX, INF);
    vector < bool > inQueue(VERTEX_MAX, false);

    inQueue[src] = true;
    inQueueCounter[src]++;

    dist[src] = 0;
    q.push(src);

    bool hasNegativeCycles{};
    while(!q.empty() && !hasNegativeCycles) {

        const int node = q.front();
        visited[node] = false;

        q.pop();

        for(const pair < int, int >& neighbor : G[node]) {
            if(dist[node] + neighbor.second < dist[neighbor.first]) {

                dist[neighbor.first] = dist[node] + neighbor.second;
                inQueueCounter[neighbor.first]++;

                if(inQueueCounter[neighbor.first] > vertices) {
                    hasNegativeCycles = true;
                    break;
                }

                if(inQueue[neighbor.first]) continue;

                inQueue[neighbor.first] = true;
                q.push(neighbor.first);
            }
        }
    }

    return { hasNegativeCycles, dist };
}

int main() {

    int vertices, edges;
    vector < pair < int, int > > GRAPH[VERTEX_MAX];

    cin >> vertices >> edges;

    for(int i = 1;i <= edges;++i) {
        int u, v, cost;
        cin >> u >> v >> cost;

        G[u].push_back({ v, cost });
    }



    return 0;
}