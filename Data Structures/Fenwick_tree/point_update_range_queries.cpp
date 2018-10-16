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

	void update(int ind, int val) {
		for(;ind < ft.size(); ind+=(ind&-ind))
			this->ft[ind] += val;
	}

	int getSum(int ind) {
		int sum = 0;
		for(;ind>0; ind-=(ind&-ind))
			sum += this->ft[ind];
		return sum;
	}

	int query(int l, int r) {
		return getSum(r) - getSum(l-1);
	}
};

int main() {
	BIT b(100);
	return 0;
}