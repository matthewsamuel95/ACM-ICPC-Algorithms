#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void countingSort(vector<int> &v) {
	int range = *max_element(begin(v), end(v));
    vector<int> cnt(range + 1, 0);
    for (int i = 0; i < (int)v.size(); ++i) {
        ++cnt[v[i]];
    }
    
    for (int i = 0, j = -1; i <= range; ++i) {
        for (int k = 0; k < cnt[i]; ++k) {
            v[++j] = i;
        }
    }
}

int main() {
	vector<int> v{10, 10, 20, 30, 12, 8, 9, 14, 13, 11};
	countingSort(v);
	for (int i = 0; i < (int)v.size(); ++i) {
		cout << v[i] << " ";
	}
	cout << "\n";
	return 0;
}