#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int queue[MAX];
int front,rear;
struct Node 
{
	int vertex;
	struct Node* next;
	int size;
};
struct Node* initialize()
{
 struct Node* node=NULL;
 node->size=0;
 return node;
}
struct Node* getNode()
{
	return (struct Node*)malloc(sizeof(struct Node));
}
struct Node* insert_rear(struct Node* head, int data)
{
	struct Node* temp=getNode();
	temp->next=NULL;
	temp->vertex=data;
	if (head==NULL)
	{
	 //printf("%d",temp->vertex);
	 return temp;
	}
	else
	{
	  struct Node* ptr = head;
	  while(ptr->next!=NULL)
	  {
	  	ptr=ptr->next;
	  }
	  ptr->next=temp;
	  head->size+=1;
	  //printf("%d %d",ptr->vertex,ptr->next->vertex);
	  return head;
	}
}
void printList(struct Node* head)
{
    struct Node* temp = head;
    int count = 10;
	while(temp!=NULL)
	{
		printf("%d->", temp->vertex);
		
		temp=temp->next;

	}
	printf("\n");
}
int empty()
{
	if (front==-1 && rear==-1)
	{
		return 1;
	}
	return 0;
}
int Front()
{
	return queue[front];
}
void push(int add_item)//modify to fit the 
{
    
    if (rear == MAX - 1)
    {
     //printf("Queue Overflow \n");
    }
    else
    {
        if (front == - 1)
        {/*If queue is initially empty */
         front = 0;
        }
        rear = rear + 1;
        queue[rear] = add_item;
    }
}
void pop()//
{
	if (front == - 1 || front > rear)
    {
        //printf("Queue Underflow \n");
        return ;
    }
    else
    {
        printf("Element deleted from queue is : %d\n", queue[front]);
        front = front + 1;
    }
}//basic functions all defined i suppose
void dfs(struct Node* graph[], int vertices, int edges, int source)
{
 int level[100]={0}; //To determine the level of each node
 int  vis[100]={0}; //Mark the node if visited 
 push(source);
 level[source] = 0 ;  //Setting the level of the source node as 0
 vis[source] = 1;
 while(!empty())
 {
   int p = Front();
   pop();
   struct Node* temp=graph[p];
   while(temp!=NULL)
   {
      if(vis[temp->vertex] == 0)
      { 
       //Setting the level of each node with an increment in the level of parent node
        level[ temp->vertex ] = level[p]+1;                 
        push(temp->vertex);
        vis[temp->vertex] = 1;
      }
      temp=temp->next;
    }   
  if(empty())
    {
      break;
    } 
  }  

}
int main()
{
	int x,y,node,edges,vertices,source;
	printf("Enter the number of edges: ");
	scanf("%d",&edges);
	printf("Enter the number of vertices: ");
	scanf("%d",&vertices);
	struct Node* graph[vertices];
	for (int i=0;i<edges;i++)
	{
		graph[i]=NULL;
	}
	for (int i = 0 ;i<edges;i++)
	{
		scanf("%d %d",&x,&y);
		graph[x]= insert_rear(graph[x],y);
		//printf("\ngraph data %d ",graph[x]->vertex);
		printf("\n");
	}
	for (int i = 0;i <vertices;i++)
	{
		printf("The adjacency list for vertex number %d is ", i);
		printList(graph[i]);
	}
	front=-1;
	rear=-1;
	printf("Enter the source vertex\n");
	scanf("%d",&source);
	dfs(graph,vertices,edges,source);
	return 0;
}