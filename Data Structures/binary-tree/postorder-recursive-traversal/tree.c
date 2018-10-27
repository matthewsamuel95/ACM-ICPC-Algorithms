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

void traverseTree(tnode h, void (*visit)(tnode)) {

	if (h->l != NULL)
		traverseTree(h->l, visit);

	if (h->r != NULL)
		traverseTree(h->r, visit);
	
	// Post-order Traversal
	(*visit)(h);
}
