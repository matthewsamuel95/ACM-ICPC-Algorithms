#include <bits/stdc++.h>

using namespace std;

int main() {
	int n; scanf("%d", &n);
	
	for (int msk = 0; msk < (1 << n); ++msk) {
		for (int pmsk = msk; pmsk > 0; pmsk = (pmsk - 1) & msk) {
			for (int i = 0; i < n; ++i) {
				int a = 0; a += msk >> i & 1; a += pmsk >> i & 1;

				printf("%d", a);
			}
			puts("");
		}
		for (int i = 0; i < n; ++i) {
			int a = 0; a += msk >> i & 1;

			printf("%d", a);
		}
		puts("");
	}

	return 0;
}
