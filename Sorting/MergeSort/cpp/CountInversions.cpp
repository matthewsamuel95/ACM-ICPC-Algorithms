#include <iostream>
#include <vector>

using namespace std;

long long count_inversions(int *a, int n) {
    if (n <= 1) {
        return 0;
    }
    int sz1 = n / 2, sz2 = n - sz1;

    // get count of inversions in left and right half
    long long res = count_inversions(a, sz1) + count_inversions(a + sz1, sz2);

    // merge both halves (now copied into t1, resp. t2) into a
    vector<int> t1(a, a + sz1), t2(a + sz1, a + n);
    int k = 0, i = 0, j = 0;
    while (i < sz1 && j < sz2) {
        if (t1[i] <= t2[j]) {
            a[k++] = t1[i++];

            // all elements in t2[0..j-1] (which are j elements) are smaller than t1[i] 
            // and are to the right of t1[i] in the original array --> form an inversion
            res += j; 
        } else {
            a[k++] = t2[j++];
        }
    }
    while (i < sz1) {
        a[k++] = t1[i++];
        res += j; // j == sz2 holds here
    }
    while (j < sz2) {
        a[k++] = t2[j++];
    }
    return res;
}

int main() {
	vector<int> v{10, 10, 20, 30, 12, 8, 9, 14, 13, 11};
	cout << "Given array has " << count_inversions(&v[0], v.size()) << " inversions.\n";
	return 0;
} 