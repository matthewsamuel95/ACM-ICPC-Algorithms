nt sparse[20][N], lg[N];
int q(int x, int y)
{
	int v = lg[y - x + 1];
	return max(sparse[v][x], sparse[v][y + 1 - (1 << v)]);
}

for(int i = 0; (1 << i) < N; i++)
	lg[1 << i] = i;
for(int i = 1; i < N; i++)
	lg[i] = max(lg[i], lg[i - 1]);

for(int j = 1; j < 20; j++)
	for(int i = 0; i + (1 << (j - 1)) < n; i++)
		sparse[j][i] = max(sparse[j - 1][i], sparse[j - 1][i + (1 << (j - 1))]);
