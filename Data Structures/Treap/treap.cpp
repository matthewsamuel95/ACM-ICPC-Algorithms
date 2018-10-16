#include <bits/stdc++.h>
using namespace std;

typedef struct node {
    int val,prior,size;
    struct node *l,*r;
} node;

typedef node* pnode;

int sz (pnode t) {
    return t ? t->size : 0;
}

void upd_sz (pnode t) {
    if (t) {
        t->size = sz(t->l) + 1 + sz(t->r);
    }
}

pnode find (pnode t, int key) {
    if (t == NULL || t->val == key) {
        return t;
    }

    return find(t->val < key ? t->r : t->l, key);
}

void split (pnode t, pnode &l, pnode &r, int key) {
    if (!t) {
        l = r = NULL;
    }
    else if (t->val <= key) {
        split(t->r, t->r, r, key);
        l = t;
    }
    else {
        split(t->l, l, t->l, key);
        r = t;
    }

    upd_sz(t);
}

void merge (pnode &t, pnode l, pnode r) {
    if (!l || !r) {
        t = l?l:r;
    }
    else if (l->prior > r->prior) {
        merge(l->r, l->r, r);
        t = l;
    }
    else {
        merge(r->l, l, r->l);
        t = r;
    }

    upd_sz(t);
}

void insert (pnode &t, pnode it) {
    if (!t) {
        t = it;
    }    
    else if (it->prior > t->prior) {
        split(t, it->l, it->r, it->val);
        t = it;
    }
    else {
        insert(t->val <= it->val ? t->r : t->l, it);
    }

    upd_sz(t);
}

void erase (pnode &t, int key) {
    pnode p = find(t, key);
    if (p == NULL) {
        return;
    }
    
    pnode temp = t;
    merge(t, p->l, p->r);
    free(temp);

    upd_sz(t);
}

pnode init (int val) {
    pnode ret = (pnode)malloc(sizeof(node));
    ret->val = val;
    ret->size = 1;
    ret->prior = rand();
    ret->l = ret->r = NULL;
    return ret;
}

int main() {
    pnode t = init(4);
    insert(t, init(19));
    insert(t, init(8));
    insert(t, init(27));
    insert(t, init(20));
    insert(t, init(12));
    insert(t, init(15));
    insert(t, init(6));
    insert(t, init(7));
    insert(t, init(8));
  
    return 0;
}
