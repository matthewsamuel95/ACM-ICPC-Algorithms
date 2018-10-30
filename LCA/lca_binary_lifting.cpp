template <typename T>
struct Edge {
	int from;
	int to;
	T cost;
	Edge(const int _f, const int _t, const T _c) : from(_f), to(_t), cost(_c) {}
};

using edge = Edge<int>;

const int mxlog = 25;

int n, timer;
vector<vector<int>> adj, up;
vector<int> tin, tout;
vector<edge> edges;

void dfs(const int from, const int p) {
	tin[from] = timer++;
	up[from][0] = p;
	for(int i = 1; i < mxlog && ~up[from][i - 1]; i++) {
		up[from][i] = up[up[from][i - 1]][i - 1];
	}
	for(int &id : adj[from]) {
		int to = from ^ edges[id].from ^ edges[id].to;
		if(to != p) {
			dfs(to, from);
		}
	}
	tout[from] = timer++;
}

inline bool anc(const int &x, const int &y) {
	return tin[x] <= tin[y] && tout[x] >= tout[y];
}

inline int lca(int x, int y) {
	if(anc(x, y)) {
		return x;
	}
	if(anc(y, x)) {
		return y;
	}
	for(int i = mxlog - 1; ~i; i--) {
		if(~up[x][i] && !anc(up[x][i], y)) {
			x = up[x][i];
		}
	}
	return up[x][0];
}

inline void init() {
	timer = 0;
	edges = vector<edge>();
	adj = vector<vector<int>>(n);
	tin = tout = vector<int>(n, -1);
	up = vector<vector<int>>(n, vector<int>(mxlog, -1));
}
