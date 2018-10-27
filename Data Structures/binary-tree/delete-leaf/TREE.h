#ifndef TREE_H
#define TREE_H 1

typedef struct treenode *tnode;
struct treenode {
	int item;
	tnode l;
	tnode r;
};

tnode createTree(int, int);
tnode deleteLeaf(tnode, int);
void showTree(tnode, int);

#endif
