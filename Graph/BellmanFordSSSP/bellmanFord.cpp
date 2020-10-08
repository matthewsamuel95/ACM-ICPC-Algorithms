//
// Created by Scarlat Marius on 10/8/20.
//

#include <iostream>
#include <vector>

using namespace std;

const int VERTEX_MAX = 1001;

int vertices, edges;
vector < pair < int, int > > GRAPH[VERTEX_MAX];

int main() {

    cin >> vertices >> edges;

    for(int i = 1;i <= edges;++i) {
        int u, v, cost;
        cin >> u >> v >> cost;

        G[u].push_back({ v, cost });
    }



    return 0;
}