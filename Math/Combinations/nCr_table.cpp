#include <iostream>
#include <vector>

using namespace std;

constexpr int MOD = 1000000007;

// compute a table ncr[i][j] = C(i, j) % MOD for i <= n, j <= m
vector<vector<int>> ncr_table(int n, int m) {
    vector<vector<int>> ncr(n + 1, vector<int>(m + 1, 0));
    for(int i = 0; i <= n; i++) {
        ncr[i][0] = 1;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m && j <= i; j++) {
            ncr[i][j] = (ncr[i - 1][j - 1] + ncr[i - 1][j]) % MOD;
        }
    }
    return ncr;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> ncr(ncr_table(n, m));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cout << ncr[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}