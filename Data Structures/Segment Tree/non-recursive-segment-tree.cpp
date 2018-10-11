#include <bits/stdc++.h>

using namespace std;

struct SegmentTree {
    vector<int> parent;
    int sz, fallback;

    int (*operation)(int, int);

    SegmentTree(const vector<int> &v, int (*_operation)(int, int), int _fallback) {
        sz = v.size();
        operation = _operation;
        fallback = _fallback;
        parent.assign(sz * 2, fallback);
        copy(v.begin(), v.end(), parent.begin() + sz);
        for (int i = sz - 1; i > 0; i--) {
            parent[i] = operation(parent[i << 1], parent[i << 1 | 1]);
        }
    }

    void update(int pos, int value) {
        parent[pos += sz] = value;
        for (pos >>= 1; pos > 0; pos >>= 1) {
            parent[pos] = operation(parent[pos << 1], parent[pos << 1 | 1]);
        }
    }

    int query(int l, int r) {
        int ans = fallback;
        for (l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ans = operation(ans, parent[l++]);
            if (r & 1) ans = operation(ans, parent[--r]);
        }
        return ans;
    }
};

int main() {
    //sum example
    vector<int> vSum = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    SegmentTree STSum(vSum, [](int a, int b) { return a + b; }, 0);

    assert(STSum.query(0, vSum.size()) == 55);
    STSum.update(9, 0);
    assert(STSum.query(0, vSum.size()) == 45);
    STSum.update(1, 5);
    assert(STSum.query(0, 2) == 6);
    assert(STSum.query(0, 3) == 9);
    assert(STSum.query(7, vSum.size()) == 17);
    assert(STSum.query(8, vSum.size()) == 9);

    //max example
    vector<int> vMax = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    SegmentTree STMax(vMax, [](int a, int b) { return a > b ? a : b; }, 1<<31);

    assert(STMax.query(0, vMax.size()) == 10);
    STMax.update(6, 11);
    assert(STMax.query(0, vMax.size()) == 11);
    STMax.update(1, 5);
    assert(STMax.query(0, 2) == 5);
    assert(STMax.query(1, 6) == 6);
    assert(STMax.query(7, vMax.size()) == 10);
    assert(STMax.query(8, vMax.size()) == 10);

    //min example
    vector<int> vMin = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    SegmentTree STMin(vMin, [](int a, int b) { return a < b ? a : b; }, ~(1<<31));

    assert(STMin.query(0, vMin.size()) == 1);
    STMin.update(4, 0);
    assert(STMin.query(0, vMin.size()) == 0);
    STMin.update(1, 0);
    assert(STMin.query(0, 2) == 0);
    assert(STMin.query(1, 6) == 0);
    assert(STMin.query(7, vMin.size()) == 8);
    assert(STMin.query(8, vMin.size()) == 9);

    //gcd example
    vector<int> vGcd = {1, 2, 2, 4, 4, 5, 6, 6, 6, 6};
    SegmentTree STGcd(vGcd, __gcd, 0);

    assert(STGcd.query(0, vGcd.size()) == 1);
    STGcd.update(0, 2);
    STGcd.update(5, 4);
    assert(STGcd.query(0, vGcd.size()) == 2);
    STGcd.update(1, 0);
    assert(STGcd.query(0, 2) == 2);
    assert(STGcd.query(1, 6) == 2);
    assert(STGcd.query(5, vGcd.size()) == 2);
    assert(STGcd.query(6, vGcd.size()) == 6);
    return 0;
}
