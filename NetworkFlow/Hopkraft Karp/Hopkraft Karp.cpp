const int MAXN1 = 50000;
const int MAXN2 = 50000;
const int MAXM = 150000;

int n1, n2, edges, last[MAXN1], _prev[MAXM], head[MAXM];
int matching[MAXN2], dist[MAXN1], Q[MAXN1];
bool used[MAXN1], vis[MAXN1];

void init(int _n1, int _n2)
{
	n1 = _n1;
	n2 = _n2;
	edges = 0;
	fill(last, last + n1, -1);
}

void addEdge(int u, int v)
{
	head[edges] = v;
	_prev[edges] = last[u];
	last[u] = edges++;
}

void bfs()
{
	fill(dist, dist + n1, -1);
	int sizeQ = 0;
	for (int u = 0; u < n1; ++u)
	{
		if (!used[u])
		{
			Q[sizeQ++] = u;
			dist[u] = 0;
		}
	}
	for (int i = 0; i < sizeQ; i++)
	{
		int u1 = Q[i];
		for (int e = last[u1]; e >= 0; e = _prev[e])
		{
			int u2 = matching[head[e]];
			if (u2 >= 0 && dist[u2] < 0)
			{
				dist[u2] = dist[u1] + 1;
				Q[sizeQ++] = u2;
			}
		}
	}
}

bool dfs(int u1)
{
	vis[u1] = true;
	for (int e = last[u1]; e >= 0; e = _prev[e])
	{
		int v = head[e];
		int u2 = matching[v];
		if (u2 < 0 || !vis[u2] && dist[u2] == dist[u1] + 1 && dfs(u2))
		{
			matching[v] = u1;
			used[u1] = true;
			return true;
		}
	}
	return false;
}

int maxMatching()
{
	fill(used, used + n1, false);
	fill(matching, matching + n2, -1);
	for (int res = 0;;)
	{
		bfs();
		fill(vis, vis + n1, false);
		int f = 0;
		for (int u = 0; u < n1; ++u)
			if (!used[u] && dfs(u))
				++f;
		if (!f)
			return res;
		res += f;
	}
}
