#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

struct node {
	node *l, *r;
	ll val, lazy;

	node () {
		l = r = 0;
		val = lazy = 0;
	}
};

void prop (node *at, int i, int j) {
	at->val += at->lazy * (j - i + 1);

	if (i != j) {
		if (!at->l)	at->l = new node();
		if (!at->r)	at->r = new node();

		at->l->lazy += at->lazy;
		at->r->lazy += at->lazy;
	}

	at->lazy = 0;
}

ll query (node *at, int i, int j, int a, int b, int val) {
	prop (at, i, j);
	if (j < a or i > b)	return 0;

	if (i >= a and j <= b) {
		at->lazy += val;
		prop (at, i, j);
		return at->val;
	} else {
		int mid = (i + j)>>1;

		if (!at->l)	at->l = new node();
		if (!at->r) at->r = new node();

		ll L = query (at->l, i, mid, a, b, val);
		ll R = query (at->r, mid + 1, j, a, b, val);
		at->val = at->l->val + at->r->val;
		return L + R;
	}
}

int main (void) {
	ios_base::sync_with_stdio(false);

	int T;	cin >> T;
	while (T--) {
		node *root = new node();

		int n, q;	cin >> n >> q;

		while (q--) {
			int c, l, r;	cin >> c >> l >> r;
			l--;	r--;
			if (l > r)	swap (l, r);
			if (c == 0) {
				int v;	cin >> v;
				query (root, 0, n - 1, l, r, v);
			} else {
				cout << query (root, 0, n - 1, l, r, 0) << endl;
			}
		}
	}

	return 0;
}
