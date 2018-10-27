#include <stdlib.h>
#include "TREE.h"

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

int pathLength(tnode x, int l) {
	int c = l;
	
	if (x->r == NULL && x->l == NULL)
		return c;
	
	if (x->r != NULL)
		c += pathLength(x->r, l+1);
	if (x->l != NULL)
		c += pathLength(x->l, l+1);
	
	return c;
}
