#include <bits/stdc++.h>
using namespace std;

typedef struct node{
    int val,prior,size;
    struct node *l,*r;
} node;

typedef node* pnode;

int sz(pnode t){
    return t ? t->size : 0;
}

pnode init(int val){
    pnode ret = (pnode)malloc(sizeof(node));
    ret->val=val;
    ret->size=1;
    ret->prior=rand();
    ret->l=ret->r=NULL;
    return ret;
}
