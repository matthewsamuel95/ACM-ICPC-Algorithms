// This is very fast in practice, and only loses to push-relabel flow.
// Running time:
// 		O(min(|E|,flow) * Layers)
// 		In general graphs: Layers = O(|V|^2)
// 		In bibpartite graphs: Layers = O(sqrt(|V|))
// INPUT:
// 		- graph, constructed using AddEdge()
//      - source and sink
// OUTPUT:
//      - maximum flow value
//      - To obtain actual flow values, look at edges with capacity > 0
//        (zero capacity edges are residual edges).

/* Find min cut between every pair of vertices using N max_flow call (instead of N^2)
 *
 * Not tested with directed graph
 * Index start from 0
 */

const int mxN = 210, INF = 1000000010;

typedef long long LL;
struct Edge
{
	int u, v;
	LL cap, flow;
	Edge()
	{
	}
	Edge(int u, int v, LL cap) :
			u(u), v(v), cap(cap), flow(0)
	{
	}
};
struct Dinic
{
	int N;
	vector<Edge> E;
	vector<vector<int>> g;
	vector<int> d, pt;
	Dinic(int N) :
			N(N), E(0), g(N), d(N), pt(N)
	{
	}
	void AddEdge(int u, int v, LL cap)
	{
		if (u != v)
		{
			E.push_back(Edge(u, v, cap));
			g[u].push_back(E.size() - 1);
			E.push_back(Edge(v, u, 0));
			g[v].push_back(E.size() - 1);
		}
	}
	bool BFS(int S, int T)
	{
		queue<int> q(
		{ S });
		fill(d.begin(), d.end(), N + 1);
		d[S] = 0;
		while (!q.empty())
		{
			int u = q.front();
			q.pop();
			if (u == T)
				break;
			for (int k : g[u])
			{
				Edge &e = E[k];
				if (e.flow < e.cap && d[e.v] > d[e.u] + 1)
				{
					d[e.v] = d[e.u] + 1;
					q.push(e.v);
				}
			}
		}
		return d[T] != N + 1;
	}
	LL DFS(int u, int T, LL flow = -1)
	{
		if (u == T || flow == 0)
			return flow;
		for (int &i = pt[u]; i < g[u].size(); ++i)
		{
			Edge &e = E[g[u][i]];
			Edge &oe = E[g[u][i] ^ 1];
			if (d[e.v] == d[e.u] + 1)
			{
				LL amt = e.cap - e.flow;
				if (flow != -1 && amt > flow)
					amt = flow;
				if (LL pushed = DFS(e.v, T, amt))
				{
					e.flow += pushed;
					oe.flow -= pushed;
					return pushed;
				}
			}
		}
		return 0;
	}
	LL MaxFlow(int S, int T)
	{
		LL total = 0;
		while (BFS(S, T))
		{
			fill(pt.begin(), pt.end(), 0);
			while (LL flow = DFS(S, T))
				total += flow;
		}
		return total;
	}
};

struct GomoryHu
{
	int ok[mxN], cap[mxN][mxN];
	int answer[mxN][mxN], parent[mxN], n;
	Dinic flow;
	GomoryHu(int n) :
			n(n), flow(n)
	{
		for (int i = 0; i < n; ++i)
			ok[i] = parent[i] = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				cap[i][j] = 0, answer[i][j] = INF;
	}
	void addEdge(int u, int v, int c)
	{
		cap[u][v] += c;
	}
	void calc()
	{
		for (int i = 0; i < n; ++i)
			parent[i] = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				answer[i][j] = 2000111000;
		for (int i = 1; i <= n - 1; ++i)
		{
			flow = Dinic(n);
			for (int u = 0; u < n; u++)
				for (int v = 0; v < n; v++)
					if (cap[u][v])
						flow.AddEdge(u, v, cap[u][v]);
			int f = flow.MaxFlow(i, parent[i]);
			bfs(i);
			for (int j = i + 1; j < n; ++j)
				if (ok[j] && parent[j] == parent[i])
					parent[j] = i;
			answer[i][parent[i]] = answer[parent[i]][i] = f;
			for (int j = 0; j < i; ++j)
				answer[i][j] = answer[j][i] = min(f, answer[parent[i]][j]);
		}
	}
	void bfs(int start)
	{
		memset(ok, 0, sizeof ok);
		queue<int> qu;
		qu.push(start);
		while (!qu.empty())
		{
			int u = qu.front();
			qu.pop();
			for (int xid = 0; xid < flow.g[u].size(); ++xid)
			{
				int id = flow.g[u][xid];
				int v = flow.E[id].v, fl = flow.E[id].flow,
						cap = flow.E[id].cap;
				if (!ok[v] && fl < cap)
					ok[v] = 1, qu.push(v);
			}
		}
	}
};
