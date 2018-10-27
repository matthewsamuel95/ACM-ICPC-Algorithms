//Simulate the Stack and Queue using linked lists.
#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	struct node *next;
};
typedef struct node NODE;

// To create the NODE

NODE *getnode() {
  NODE *newnode;
	newnode  = (NODE*)malloc(sizeof(NODE));
	int ele;
	printf("Enter the Element\n");
	scanf("%d", &ele);
	newnode->data = ele;
	newnode->next = NULL;
	return newnode;
}

// Intiallize top as NULL for Stack
NODE *top = NULL;

// Intiallize front and rare as NULL for Queue
NODE *front = NULL;
NODE *rare = NULL;

// Stack Function to push element in stack work like insert_front in linked list

void push() {
	NODE *newnode =	getnode();
	if(top == NULL) {
  	newnode->next = NULL;    // if stack is empty then newnode will join to NULL
  }
	else {
		newnode->next = top;    // pushing newnode in stack
	}
	top = newnode;
}

// Stack Function to pop a element from stack work like delete_front in linked list

void pop() {
  if(top == NULL) {
		printf("Stack is Empty\n");
    return;
  }
	NODE *temp = top;
	top = top->next;
	free(temp);
}

// Queue Function to Enqueue the element in queue

void Enqueue() {

	NODE *newnode;
  newnode = getnode();
	if(rare == NULL) {         // If rare is null then front and rare both linked with newnode
		front = rare = newnode;
		return;
  }
	rare->next = newnode;  // otherwise rare will shift to newnode
	rare = newnode;
	return;
}

// Queue Function to Dequeue the element from Queue

void Dequeue() {
  if(front == NULL) {     // if front is null list is empty
		printf("Queue is Empty\n");
    return;
  }
	NODE *temp = front;   // Work like delete_front in linked list
	front = front->next;
	free(temp);
	if(front == NULL) {   // if new position of front is null then link rare with null as list is empty in this condition
		rare = NULL;
		return;
	}
}

// To Display Stack

void Display_stack() {
	if(top == NULL) {
    printf("\nStack is Empty\n");
  }
	NODE *temp = top;
	while(temp != NULL) {
		printf("%d --> ", temp->data);
		temp = temp->next;
	}
}

//To Display Queue

void Display_queue() {
	if(rare == NULL) {
    printf("\nQueue is Empty\n");
  }
	NODE *temp = front;
	while(temp != NULL) {
		printf("%d --> ", temp->data);
		temp = temp->next;
	}
}

void main() {
	int a;
	int b;
	printf("Enter 1 : Simulate the Stack\n");
	printf("Enter 2 : Simulate the Queue\n");
	scanf("%d", &b);
	if(b==1) {
		while(a!=0) {
			printf("\n\n");
			printf("Enter 1 -> PUSH\n");
		  printf("Enter 2 -> POP\n");
		  printf("Enter 3 -> Display\n");
			printf("Enter 0 -> Exit\n");
			scanf("%d", &a);
			if(a==0) {
	      printf("-------------------------Thank You----------------------------\n");
	      return;
	    }
			switch(a) {
				case 1 :
					{
					push();
					Display_stack();
					break;
					}
				case 2 :
					{
					pop();
					Display_stack();
					break;
					}
			case 3 :
					{
					Display_stack();
					break;
					}

				default :
					{
					printf("Wrong Value Detacted\n");
					break;
					}
				return;
			}
		}
	}
	else if(b==2) {
		while(a!=0) {
			printf("\n\n");
			printf("Enter 1 -> Enqueue\n");
		  printf("Enter 2 -> Dequeue\n");
		  printf("Enter 3 -> Display_LL\n");
			printf("Enter 0 -> Exit\n");
			scanf("%d", &a);
			if(a==0) {
	      printf("-------------------------Thank You----------------------------\n");
	      return;
	    }
			switch(a) {
				case 1 :
					{
					Enqueue();
					Display_queue();
					break;
					}
				case 2 :
					{
					Dequeue();
					Display_queue();
					break;
					}
			case 3 :
					{
					Display_queue();
					break;
					}

				default :
					{
					printf("Wrong Value Detacted\n");
					break;
					}
				return;
			}
		}
	}
}
