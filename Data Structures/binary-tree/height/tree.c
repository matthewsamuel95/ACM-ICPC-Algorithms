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

int height(tnode h) {
	int u, v;
	
	if (h == NULL)
		return -1;
	
	u = height(h->l);
	v = height(h->r);
	
	if (u > v)
		return u + 1;
	else
		return v + 1;
}
