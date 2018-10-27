#include <stdio.h>
#include "TREE.h"

#define N 15

void visit(tnode);

int main(void) {
	tnode head = createTree(1, N);
	
	traverseTree(head, visit);
	
	return 0;
}

void visit(tnode x) {
	printf("%i ", x->item);
}
