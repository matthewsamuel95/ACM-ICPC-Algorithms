#include<bits/stdc++.h>
using namespace std;

class BIT {
public:
	int n;
	vector<int> ft;
	BIT(int n) {
		this->n = n;
		this->ft.assign(n+1, 0);
	}

	void updateUtil(int ind, int val) {
		for(;ind < ft.size(); ind+=(ind&-ind))
			this->ft[ind] += val;
	}

	void update(int l, int r, int val) {
		updateUtil(l, val);
		updateUtil(r+1, -val);
	}

	int query(int ind) {
		int sum = 0;
		for(;ind>0; ind-=(ind&-ind))
			sum += this->ft[ind];
		return sum;
	}

};

int main() {
	BIT b(100);
	return 0;
}