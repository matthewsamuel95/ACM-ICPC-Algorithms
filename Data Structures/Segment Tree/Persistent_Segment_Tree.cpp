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
 
const int N = 1e5 + 5, M = 3e7 + 7;
int n, a[N];
int root[N], nodes, L[M], R[M], seg[M];
 
int build (int l, int r) {
	int at = nodes++;
 
	if (l == r) {
		seg[at] = a[at];
	} else {
		int m = (l + r)/2;
		L[at] = build (l, m);
		R[at] = build (m + 1, r);
		seg[at] = seg[L[at]] + seg[R[at]];
	}
 
	return at;
}
 
/* point update, v[p]++ */
int update (int i, int l, int r, int p) {
	int at = nodes++;
 
	if (l == r) {
		seg[at] = seg[i] + 1;
	} else {
		int m = (l + r)/2;
		if (p <= m) {
			L[at] = update (L[i], l, m, p);
			R[at] = R[i];
		} else {
			L[at] = L[i];
			R[at] = update (R[i], m + 1, r, p);
		}
		seg[at] = seg[L[at]] + seg[R[at]];
	}
 
	return at;
}
 
/* range query: v[A] + ... + v[B] */
int A, B;
int query (int i, int l, int r) {
	if (A > B)	return 0;
	if (r < A or l > B)	return 0;
 
 	if (l >= A and r <= B) {
		return seg[i];
	} else {
		int m = (l + r)/2;
		return query (L[i], l, m) + query (R[i], m + 1, r);
	}
}
