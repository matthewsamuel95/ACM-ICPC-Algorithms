//bfs algo using adjacency list
vector <int> adj[100005]; //max 100004 elements(if 1 based)
bool vis[100005]; //visited array
void bfs(int source)
{
  queue <int> q;
  q.push(source);
  vis[source] = true;
  while(!q.empty())
  {
    int cur = q.front();
    cout << cur << " ";
    q.pop();
    for(int i = 0; i < adj[cur].size(); i++)
      if(!vis[adj[cur][i]])
      {
        q.push(adj[cur][i]);
        vis[adj[cur][i]] = true;
      }
  }
}
