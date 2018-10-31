#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;

// nesse caso base usaremos key tipo string e elemento tipo int

struct BSTnode{
    string key;
    int element;
    BSTnode *left;
    BSTnode *right;
};

struct BST{
    BSTnode *root;
    int nodecount;
};

BST *create_bst(){
    BST *bst;
    bst = new BST;
    bst->root=NULL;
    bst->nodecount=0;
    return bst;
}

void clear(BST *bst){
    bst->root = NULL;
    bst->nodecount=0;
}

int size_bst(BST *bst){
    return bst->nodecount;
}

int find_help(BSTnode *rt, string k){
    if(rt==NULL){
        return INT_MAX;
    }
    else if(rt->key>k){
        return find_help(rt->left, k);
    }
    else if(rt->key==k){
        return rt->element;
    }
    else{
        return find_help(rt->right, k);
    }

}

int find(BST *bst, string k ){
    return find_help(bst->root, k);
}

BSTnode *create_bstnode(string k, int e){
    BSTnode *rt;
    rt = new BSTnode;
    rt->left=NULL;
    rt->right=NULL;
    rt->key = k;
    rt->element = e;
    return rt;
}

BSTnode *inserthelp(BSTnode *rt, string k, int e){
    if(rt==NULL){
        return create_bstnode(k,e);
    }
    else if(rt->key>k){
        rt->left = inserthelp(rt->left, k, e);
    }
    else{
        rt->right = inserthelp(rt->right, k, e);
    }
    return rt;
}

void insert(BST *bst, string k, int e){
    bst->nodecount++;
    bst->root = inserthelp(bst->root, k, e);
}

BSTnode *getmin(BSTnode *rt){
    if(rt->left==NULL){
        return rt;
    }
    return getmin(rt->left);
}

BSTnode *deletemin(BSTnode *rt){
    if(rt->left == NULL){
        return rt->right;
    }
    rt->left = deletemin(rt->left);
    return rt;
}

BSTnode *remove_help(BSTnode *rt, string k){
    if(rt==NULL){
        return NULL;
    }
    if(rt->key>k){
        rt->left = remove_help(rt->left, k);
    }
    else if(rt->key<k){
        rt->right = remove_help(rt->right, k);
    }
    else{
        if(rt->left==NULL){
            return rt->right;
        }
        else if(rt->right==NULL){
            return rt->left;
        }
        else{
            BSTnode *temp = getmin(rt->right);
            rt->element = temp->element;
            rt->key = temp->key;
            rt->right = deletemin(rt->right);
        }
    }
}

int remove(BST *bst, string k){
    int temp = find_help(bst->root, k);
    if(temp!=INT_MAX){
        bst->root = remove_help(bst->root, bst->root->key);
        bst->nodecount--;
    }
    return temp;

}

int main(void){
    BST *bst=create_bst();
    insert(bst, "a", 0);
    insert(bst, "ab", 1);
    insert(bst, "abc", 2);
    insert(bst, "abcd", 3);
    insert(bst, "abcde", 4);
    cout << find(bst, "a") << endl;
    cout << find(bst, "ab") << endl;
    cout << find(bst, "abc") << endl;
    cout << find(bst, "abcd") << endl;
    cout << find(bst, "abcde") << endl;
    clear(bst);
    cout << find(bst, "a") << endl;
    cout << find(bst, "ab") << endl;
    cout << find(bst, "abc") << endl;
    cout << find(bst, "abcd") << endl;
    cout << find(bst, "abcde") << endl;
    

    return 0;
}
