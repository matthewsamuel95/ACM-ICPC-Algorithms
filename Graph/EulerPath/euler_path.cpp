// O(V + E)
// Euler path is a path that uses every edge in graph exactly once
// const int N = 1e5 + 50;
int n, in[N], out[N]; // in and out degrees
vector<int> path;  // has the euler path in reverse order
queue<int> adj[N];

void dfs(int u)
{
    while(adj[u].size())
    {
        int v = adj[u].front();
        adj[u].pop();
        dfs(v);
    }
    path.push_back(u);
}

pair<bool, int> is_eulerian() // {is eulerian, start node of dfs}
{
    int _s = 0, _e = 0, st = 1;
    for(int u = 1; u < N; u++)
    {
        int sub = in[u] - out[u];
        if(sub == -1)
            ++_s, st = u;
        else if(sub == 1)
            ++_e;
        else if(sub != 0)
            return {0, -1};
    }
    if(_s > 1 || _e > 1 || _s + _e == 1)
        return {0, -1};
    return {1, st};
}
