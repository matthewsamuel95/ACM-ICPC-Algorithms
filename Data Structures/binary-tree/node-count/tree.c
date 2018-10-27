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

int count(tnode h) {
	if (h == NULL)
		return 0;
	
	return count(h->l) + count(h->r) + 1;
}
