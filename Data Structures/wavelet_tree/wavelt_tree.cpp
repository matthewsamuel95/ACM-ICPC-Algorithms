#include <bits/stdc++.h>

#define ll long long

#define pb push_back
using namespace std;
const int N = 1e5;

int a[N];
struct wavelet_tree {
	int lo, hi;
	wavelet_tree *l, *r;
	vector<int> b;

	//nos are in range [x,y]
	//array indices are [from, to)
	wavelet_tree(int *from, int *to, int x, int y) {
		lo = x, hi = y;
		if (lo == hi or from >= to)
			return;
		int mid = (lo + hi) / 2;
		auto f = [mid](int x) {
			return x <= mid;
		};
		b.reserve(to - from + 1);
		b.pb(0);
		for (auto it = from; it != to; it++)
			b.pb(b.back() + f(*it));
		//see how lambda function is used here
		auto pivot = stable_partition(from, to, f);
		l = new wavelet_tree(from, pivot, lo, mid);
		r = new wavelet_tree(pivot, to, mid + 1, hi);
	}

	//kth smallest element in [l, r]
	int kth(int l, int r, int k) {
		if (l > r)
			return 0;
		if (lo == hi)
			return lo;
		int inLeft = b[r] - b[l - 1];
		int lb = b[l - 1]; //amt of nos in first (l-1) nos that go in left
		int rb = b[r]; //amt of nos in first (r) nos that go in left
		if (k <= inLeft)
			return this->l->kth(lb + 1, rb, k);
		return this->r->kth(l - lb, r - rb, k - inLeft);
	}

	//count of nos in [l, r] Less than or equal to k
	int LTE(int l, int r, int k) {
		if (l > r or k < lo)
			return 0;
		if (hi <= k)
			return r - l + 1;
		int lb = b[l - 1], rb = b[r];
		return this->l->LTE(lb + 1, rb, k) + this->r->LTE(l - lb, r - rb, k);
	}

	//count of nos in [l, r] equal to k
	int count(int l, int r, int k) {
		if (l > r or k < lo or k > hi)
			return 0;
		if (lo == hi)
			return r - l + 1;
		int lb = b[l - 1], rb = b[r], mid = (lo + hi) / 2;
		if (k <= mid)
			return this->l->count(lb + 1, rb, k);
		return this->r->count(l - lb, r - rb, k);
	}
};
int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> a[1] >> a[2] >> a[3];
	wavelet_tree tree(a + 1, a + 3 + 1, 0, 10);
	cout << tree.LTE(1, 3, 5);

	return 0;
}
