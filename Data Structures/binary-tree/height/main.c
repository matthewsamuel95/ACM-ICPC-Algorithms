#include <stdio.h>
#include "TREE.h"

#define N 15

void visit(tnode);

int main(void) {
	tnode head = createTree(1, N);
	
	printf("Tree Height: %i\n", height(head));
	
	return 0;
}
