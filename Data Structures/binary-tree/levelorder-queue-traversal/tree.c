#include <stdlib.h>
#include "TREE.h"
#include "QUEUE.h"

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

	QUEUEinit();
	QUEUEput(h);
	
	while (!QUEUEempty()) {
		h = QUEUEget();
		(*visit)(h);
		
		if (h->l != NULL)
			QUEUEput(h->l);
		
		if (h->r != NULL)
			QUEUEput(h->r);
	}
}
