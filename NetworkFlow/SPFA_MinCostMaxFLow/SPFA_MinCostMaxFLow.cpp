//Minimum Cost Max Flow SPFA implementation
const int mxN = 110;
const int inf = 1000000010;
struct Edge
{
	int to, cost, cap, flow, backEdge;
};
struct MCMF
{
	int s, t, n;
	vector<Edge> g[mxN];
	MCMF(int _s, int _t, int _n)
	{
		s = _s, t = _t, n = _n;
	}
	void addEdge(int u, int v, int cost, int cap)
	{
		Edge e1 =
		{ v, cost, cap, 0, g[v].size() };
		Edge e2 =
		{ u, -cost, 0, 0, g[u].size() };
		g[u].push_back(e1);
		g[v].push_back(e2);
	}
	pair<int, int> minCostMaxFlow()
	{
		int flow = 0, cost = 0;
		vector<int> state(n), from(n), from_edge(n), d(n);
		deque<int> q;
		while (true)
		{
			for (int i = 0; i < n; i++)
				state[i] = 2, d[i] = inf, from[i] = -1;
			state[s] = 1;
			q.clear();
			q.push_back(s);
			d[s] = 0;
			while (!q.empty())
			{
				int v = q.front();
				q.pop_front();
				state[v] = 0;
				for (int i = 0; i < (int) g[v].size(); i++)
				{
					Edge e = g[v][i];
					if (e.flow >= e.cap || d[e.to] <= d[v] + e.cost)
						continue;
					int to = e.to;
					d[to] = d[v] + e.cost;
					from[to] = v;
					from_edge[to] = i;
					if (state[to] == 1)
						continue;
					if (!state[to] || (!q.empty() && d[q.front()] > d[to]))
						q.push_front(to);
					else
						q.push_back(to);
					state[to] = 1;
				}
			}
			if (d[t] == inf)
				break;
			int it = t, addflow = inf;
			while (it != s)
			{
				addflow = min(addflow,
						g[from[it]][from_edge[it]].cap
								- g[from[it]][from_edge[it]].flow);
				it = from[it];
			}
			it = t;
			while (it != s)
			{
				g[from[it]][from_edge[it]].flow += addflow;
				g[it][g[from[it]][from_edge[it]].backEdge].flow -= addflow;
				cost += g[from[it]][from_edge[it]].cost * addflow;
				it = from[it];
			}
			flow += addflow;
		}
		return
		{	cost,flow};
	}
};
