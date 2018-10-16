#include <stdio.h>
#include <stdlib.h>

// 	LINKED_QUEUE

typedef struct node{
	int inf;
	struct node *next;
}NODE;

typedef struct{
	NODE *begin;
	NODE *end;
	int size;
}DESCRITOR;

typedef DESCRITOR * LINKED_QUEUE;

void make_queue(LINKED_QUEUE *q){
	*q = (DESCRITOR * )malloc(sizeof(DESCRITOR));	
		if(!(*q)){
			puts("The memory is full\n");
			exit(1);	
		}
		(*q)->begin = (*q)->end = NULL;
		(*q)->size = 0;
}

int isEmpty(LINKED_QUEUE q){
	return (q->begin == NULL);  //return (q->size == 0);
}

int sizeQUEUE (LINKED_QUEUE q){
	return (q->size);
}

void insert_QUEUE (LINKED_QUEUE q, int info){
	NODE *new_node;
		new_node = (NODE *)malloc(sizeof(NODE));
		if(!new_node){
			puts("The memory is full\n");
			exit(2);
		}
	new_node->inf = info;
	new_node->next = NULL;
		if(isEmpty(q))
			q->begin = new_node;
		else q->end->next = new_node;
	q->end = new_node;
	q->size++;		
}

int query(LINKED_QUEUE q){
	if(isEmpty(q)){
		puts("QUEUE is Empty!\n");
		exit(3);
	}else return q->begin->inf;
}

void removeQUEUE(LINKED_QUEUE q){
	NODE *aux = q->begin;
	
	if(isEmpty(q)){
		puts("QUEUE is Empty!\n");
		exit(4);
	}
	
	q->begin = q->begin->next;
	if(!(q->begin->next))
		q->end = NULL;	
	
	free(aux);
}

int main(){}
