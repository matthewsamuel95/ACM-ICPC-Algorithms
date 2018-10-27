#ifndef TREE_H
#define TREE_H 1

typedef struct treenode *tnode;
struct treenode {
	int item;
	tnode l;
	tnode r;
};

tnode createTree(int, int);
int count(tnode);

#endif
