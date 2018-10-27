#ifndef STACK_H
#define STACK_H 1

#include "TREE.h"

typedef tnode stackItem;

void STACKinit(void);
int  STACKcount(void);
void STACKpush(stackItem);
stackItem STACKpop(void);

#endif
