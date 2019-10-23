#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int, int> pii;

#define erep(i, x, n) for (auto i = x; i<=(ll)(n); i++)
#define rep(i, x, n) for(auto i = x; i<(ll)(n); i++)
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define mod(n, m) ((n%m + m) % m)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'

int power(int x, unsigned int y, int p)
{
	int res = 1; // Initialize result
	x = x % p; // Update x if it is more than or
	// equal to p
	while (y > 0)
	{
		// If y is odd, multiply x with result
		if (y & 1)
			res = (res * 1ll * x) % p;

		// y must be even now
		y = y >> 1; // y = y/2
		x = (x * 1ll * x) % p;
	}
	return res;
}

// Function to find modular inverse of a under modulo p
// using Fermat's method. Assumption: p is prime
int modInverse(int a, int p)
{
	return power(a, p - 2, p);
}

// Returns n! % p using Wilson's Theorem
int modFact(int n, int p)
{
	// n! % p is 0 if n >= p
	if (p <= n)
		return 0;

	// Initialize result as (p-1)! which is -1 or (p-1)
	int res = (p - 1), den = 1;

	// Multiply modulo inverse of all numbers from (n+1)
	// to p
	for (int i = n + 1; i < p; i++)
		res = (res * 1ll * i) % p;
	return res * modInverse(den, p - 2);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		int n, m;
		cin >> n >> m;
		cout << modFact(n, m) << endl;
	}
	return 0;
}
