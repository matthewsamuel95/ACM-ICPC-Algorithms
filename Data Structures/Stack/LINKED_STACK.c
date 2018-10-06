#include <stdio.h>
#include <stdlib.h>

// 	LINKED_STACK

typedef struct node{
	int info;
	struct node *next;
}NODE;

typedef NODE * LINKED_STACK;

void create_stack(LINKED_STACK *p){
	*p = NULL;
}

int isEmpty(LINKED_STACK p){
	return (p == NULL);
}

void insert(LINKED_STACK *p, int info){
	NODE *new_node;
		new_node = (NODE *) malloc (sizeof(NODE));
		if(!new_node){
			puts("Memory FULL\n");
			exit(1);
		}
	new_node->info = info;
	new_node->next = *p;
	*p = new_node; 
}

void removeSTACK (LINKED_STACK *p){
	NODE *aux = *p;
	
	if(isEmpty(*p)){
			puts("Stack is Empty\n");
			exit(2);
	}
	(*p) = (*p)->next;
	free(aux);
}



int main(){}
