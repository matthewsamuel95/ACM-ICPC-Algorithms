#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct node
{
	int data;
	struct node* next;
};

struct Time
{
	int disc;
	int fsh;
};

void addedge(struct node* a[],int u,int v){
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=v;
	temp->next=a[u];
	a[u]=temp;
}

void DFS_visit(struct node* a[],struct Time tm[],int u,int t,int color[],struct node** topo){
	t=t+1;
	tm[u].disc=t;
	color[u]=1;
	struct node* v=a[u];
	while(v!=NULL){
		if (color[v->data]==0)
		{
			DFS_visit(a,tm,v->data,t,color,topo);
		}
		v=v->next;
	}
	color[u]=-1;
	t++;
	tm[u].fsh=t;
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=u;
	temp->next=*topo;
	*topo=temp;
}

void DFS(struct node* a[],struct Time tm[],struct node** topo){
	int color[10];
	for (int i = 0; i <10; ++i)
	{
		color[i]=0;
	}
	int t=0;
	for (int i = 0; i < 10; ++i)
	{
		if (color[i]==0 && a[i]!=NULL)
		{
			DFS_visit(a,tm,i,t,color,topo);
		}
	}
}

void TS(struct node* a[],struct Time t[]){
	struct node* topo=NULL;
	DFS(a,t,&topo);
	struct node* temp=topo;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");	
}

int main()
{
	struct node* a[10];
	struct Time t[10];
	for (int i = 0; i < 10; ++i)
	{
		a[i]=NULL;
	}
	addedge(a,0,1);
	addedge(a,0,3);
	addedge(a,1,4);
	addedge(a,4,3);
	addedge(a,2,4);
	addedge(a,2,5);
	addedge(a,4,6);
	TS(a,t);
	return 0;
}