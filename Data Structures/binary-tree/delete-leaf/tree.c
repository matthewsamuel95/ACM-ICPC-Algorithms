#include <stdlib.h>
#include <stdio.h>
#include "TREE.h"

static void printnode(char, int, int);

tnode createTree(int S, int N) {
	tnode t;
	
	if (S > N)
		return NULL;
	
	t = malloc(sizeof(*t));
	t->item = S;
	t->l = createTree(S*2, N);
	t->r = createTree(S*2+1, N);
	
	return t;
}

tnode deleteLeaf(tnode root, int x) {
	tnode t;

	if (root->l == NULL && root->r == NULL && root->item == x) {
		free(root);
		return NULL;
	}
	
	if (root->l != NULL)
		root->l = deleteLeaf(root->l, x);
	if (root->r != NULL)
		root->r = deleteLeaf(root->r, x);
	
	return root;
}

void showTree(tnode x, int h) {
	if (x == NULL) {
		printnode('*', 0, h);
		return;
	}
	showTree(x->r, h+1);
	printnode(0, x->item, h);
	showTree(x->l, h+1);
}

static void printnode(char x, int n, int h) {
	int i;
	
	for (i = 0; i < h; ++i) {
		printf("    ");
	}
	
	if (x > 0)
		printf("%c\n", x);
	else
		printf("%i\n", n);
}
