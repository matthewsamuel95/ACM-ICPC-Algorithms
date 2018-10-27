#include <stdlib.h>
#include "TREE.h"
#include "STACK.h"

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
	STACKinit();
	STACKpush(h);
	
	while (STACKcount() > 0) {
		h = STACKpop();

		if (h->l != NULL)
			STACKpush(h->l);
		
		// In-order Traversal
		(*visit)(h);

		if (h->r != NULL)
			STACKpush(h->r);
	}
}
