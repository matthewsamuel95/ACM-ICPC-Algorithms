#ifndef QUEUE_H
#define QUEUE_H 1

#include "TREE.h"

typedef tnode Item;

void QUEUEinit(void);
int  QUEUEempty(void);
void QUEUEput(Item);
Item QUEUEget(void);

#endif
