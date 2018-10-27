#include <stdio.h>
#include "TREE.h"

#define N 15

void visit(tnode);

int main(void) {
	tnode head = createTree(1, N);
	
	deleteLeaf(head, 9);
	
	showTree(head, 0);
	
	return 0;
}
