// Hashing Segment Tree
/*
 *  we'll maintain a rolling hash array, so pw[0] = 1, pw[i] = base*pw[i-1]%mod
 *  we'll also maintain the sum of bases so far, we'll use this to find our hash value when using lazy propagation
 *  the idea is this: our pw[] array will have the values 1, 10, 100, 1000.. and so on
 *  therefore, if we want an entire range to have the same lazy value (let's say 9) and our range is 4
 *  then, the hashed value would be 9999, this is equivalent to 1111*9, we get the 1111 value by accumulation of array pw[]
 *  when we're merging two ranges, we'll multiply the one on the left by the length of the right range then add them up
 *  hence, we have tree[node] = left*pw[en-mid] + right
 *  finally, suppose we are updating a range with length = 2, we should get the sum[en-st] and not en-st+1
 *  this is because we include the value 1 as our first hash/sum, so we don't have to use the range inclusive
 */

const int N = 1e5 + 5, mod = 1e9 + 9, base = 10;

ll tree[4 * N], lazy[4 * N], pw[4 * N], sum[4 * N];

void propagate(int node, int st, int en)
{
	if (~lazy[node])
	{
		tree[node] = (sum[en - st] * 1ll * lazy[node]) % mod;
		if (st != en)
			lazy[2 * node] = lazy[2 * node + 1] = lazy[node];
		lazy[node] = -1;
	}
}

void update(int node, int st, int en, int shemal, int yemeen, int val)
{
	propagate(node, st, en);

	if (st > en || st > yemeen || en < shemal)
		return;

	if (shemal <= st && en <= yemeen)
	{
		lazy[node] = val;
		propagate(node, st, en);
		return;
	}

	int mid = (st + en) / 2;

	update(2 * node, st, mid, shemal, yemeen, val);
	update(2 * node + 1, mid + 1, en, shemal, yemeen, val);

	int a = tree[2 * node], b = tree[2 * node + 1];

	tree[node] = ((a * 1ll * pw[en - mid] % mod) + b) % mod;
}

void query(int node, int st, int en, int shemal, int yemeen, ll &ans)
{
	propagate(node, st, en);

	if (st > en || st > yemeen || en < shemal)
		return;

	if (shemal <= st && en <= yemeen)
	{
		ans = ((ans * 1ll * pw[en - st + 1]) % mod + tree[node]) % mod;
		return;
	}

	int mid = (st + en) / 2;

	query(2 * node, st, mid, shemal, yemeen, ans);
	query(2 * node + 1, mid + 1, en, shemal, yemeen, ans);
}

int main()
{
	pw[0] = sum[0] = 1;
	rep(i, 1, 4 * N)
	pw[i] = (base * pw[i - 1]) % mod, sum[i] = (sum[i - 1] + pw[i]) % mod;

	reset(lazy, -1);

	int n, m, k;
	cin >> n >> m >> k;
	string x;
	cin >> x;
	x.insert(x.begin(), '0');

	erep(i, 1, n)
	update(1, 1, n, i, i, x[i] - '0');
	int q = m + k;
	while (q--)
	{
		int t, l, r, c;
		cin >> t >> l >> r >> c;
		if (t == 1)
			update(1, 1, n, l, r, c);
		else
		{
			ll a = 0;
			query(1, 1, n, l, r - c, a);
			ll b = 0;
			query(1, 1, n, l + c, r, b);

			if (a == b)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}

	return 0;
}

