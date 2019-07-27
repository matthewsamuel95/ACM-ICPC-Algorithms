/**
 * Author   : huynhsamha
 * Topic    : Iterative Depth First Search (DFS) using Stack
 * ===================================================================
 * Input format:
 * The first line contains n, m, src, where:
 *  + n   : the number of vertices
 *  + m   : the number of edges
 *  + src : source node
 *
 * Then m lines follow, each describe en edge, the i-th line contains
 * u, v denoting that have an undirected edge between u and v
 * ==================================================================
 * Example:
 * ================
 * Input:
 * ================
    8 7 2
    1 2
    1 4
    2 3
    2 4
    2 5
    3 5
    6 7
 * ================
 * Output:
 * ================
    Order of vertices in dfs from 2
    5 3 4 1
 * ================
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef unsigned long long ull;

#define X first
#define Y second
#define pb push_back
#define EL printf("\n")
#define sz(A) (int)A.size()
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, r, l) for (int i = r; i >= l; i--)

const int N = 1e5 + 5;
int n, m, src;
vector<int> a[N];
bool visited[N];
vector<int> order;

void input() {
    cin >> n >> m >> src;
    FOR(i, 1, m) {
        int u, v;
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }
}

void handle_visited_node(int u) {
    /**
     * Push node u to the result
     * You can do anything you want
     */
    order.push_back(u);
}

void dfs_iterative() {
    stack<int> st;
    st.push(src);
    visited[src] = true;

    while (!st.empty()) {
        int u = st.top();
        st.pop();
        if (!visited[u]) {
            handle_visited_node(u);
            visited[u] = true;
        }

        for (int v : a[u]) {
            if (!visited[v]) {
                st.push(v);
            }
        }
    }
}

int main() {

    input();
    dfs_iterative();

    cout << "Order of vertices in dfs from " << src << "\n";
    for (int u : order) {
        cout << u << " ";
    }
    EL;

    return 0;
}
