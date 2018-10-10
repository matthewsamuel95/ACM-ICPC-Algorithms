#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000

void read(int v[], int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		v[i] = rand() % n;
	}
}

void print(int v[], int n, char mens[])
{
	int i;
	printf("%s\n",mens);
	for(i = 0; i < n; i++)
	{
		printf("%d ", v[i]);
		if(i % 20 == 0) printf("\n");
	}
	printf("\n");
}

typedef struct no
{
	int value;
	struct no* next;
}Node;

void insert(Node** r, int value)
{
	Node* p;
	Node* aux = NULL;
	Node* current = (*r);
	int cond = 1;

	p = (Node*)malloc(sizeof(Node));

	p->value = value;
	p->next = NULL;

 	while(current != NULL	&& cond)
 	{
 		if(value <  current->value) cond = 0;
 		else
 		{
 			aux = current;
 			current = current->next;
 		}
 	}
 	p->next = current;
 	if(aux == NULL) (*r) = p;
 	else aux->next = p;
}


void bucketSort(int v[], int n)
{
	Node** bucket = (Node**)malloc(n * sizeof(Node*));
	int i,j;
	
	for(i = 0; i < n; i++)
	{
		bucket[i] = NULL;
	}
	
	for(i = 0; i < n; i++)
	{
		int idx = n * ((double) v[i]/(n + 1));
		insert(bucket+idx, v[i]);

	}

	int idx = 0;
	Node*  b;

	for(i = 0; i < n; i++)
	{
		b = bucket[i];
		while(b != NULL)
		{
			v[idx++] = (b)->value;
			bucket[i] = (b)->next;
			free(b);
			b = bucket[i];
		}
		free(b);
	}
}

int main()
{
	srand(time(NULL));
	int n,i;
	printf("Input the array range\n");
	scanf("%d",&n);
	int *v = malloc(sizeof(int)*n);
	read(v, n);
	print(v, n, "Before");
	printf("\n");
	bucketSort(v, n);
	printf("\n");
	print(v, n, "After");
	printf("\n\n");

	return 0;
}
