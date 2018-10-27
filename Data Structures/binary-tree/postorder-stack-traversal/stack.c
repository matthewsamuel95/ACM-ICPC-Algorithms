#include <stdlib.h>
#include "STACK.h"

typedef tnode stackItem;

typedef struct STACKnode *link;
struct STACKnode {
		stackItem item;
		link next;
};
static link head;

link NEW(stackItem item, link next) {
	link x = malloc(sizeof(*x));
	if (x != NULL) {
		x->item = item;
		x->next = next;
	}
	return x;
}

void STACKinit(void) {
	head = NULL;
}

int STACKcount(void) {
	int i;
	link x;
	
	for (i = 0, x = head; x != NULL; x = x->next, ++i)
		;
		
	return i;
}

void STACKpush(stackItem item) {
	head = NEW(item, head);
}

stackItem STACKpop(void) {
	stackItem item = head->item;
	link t = head->next;
	free(head);
	head = t;
	
	return item;
}
