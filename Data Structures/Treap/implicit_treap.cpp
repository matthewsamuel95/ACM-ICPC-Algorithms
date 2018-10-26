#include <bits/stdc++.h>

using namespace std;

struct node {
    int x, y, sz;
    node *l, *r;

    node () { }
    node (int X) : x (X), y (rand()), sz (1), l (0), r(0) { }
} *t;

typedef node* pnode;

int getSz (pnode t) {
    return (t ? t -> sz : 0);
}

void upd (pnode &t) {
    if (!t)
        return;
    t -> sz = getSz (t -> l) + getSz (t -> r) + 1;
}

pnode Merge (pnode a, pnode b) {
    if (!a)
        return b;
    if (!b)
        return a;
    if (a -> y > b -> y) {
        a -> r = Merge (a -> r, b);
        upd (a);
        return a;
    } else {
        b -> l = Merge (a, b -> l);
        upd (b);
        return b;
    }
}

void Split (pnode t, int x, pnode &a, pnode &b) {
    if (!t)
        return void (a = b = 0);
    int key = getSz (t -> l) + 1;
    if (key > x) {
        Split (t -> l, x, a, t -> l);
        upd (t);
        b = t;
    } else {
        Split (t -> r, x - key, t -> r, b);
        upd (t);
        a = t;
    }
}

void out (pnode t) {
    if (!t)
        return;
    out (t -> l);
    cout << t -> x << " ";
    out (t -> r);
}

int main () {
    t = 0;
    for (int i = 0; i < 5; i++)
        t = Merge (t, new node (i + 1));
    
    int x = 2, y = 3;

    pnode L, M, R;
    Split (t, y    , L, R);
    Split (L, x - 1, L, M);
    t = Merge (Merge (M, L), R);

    out (t); // Expected: 2 3 1 4 5
    cout << endl;

    x = 3, y = 5;

    Split (t, y    , L, R);
    Split (L, x - 1, L, M);
    t = Merge (Merge (M, L), R);

    out (t); // Expected: 1 4 5 2 3
    cout << endl;

    return 0;
}

