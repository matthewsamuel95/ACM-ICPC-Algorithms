#include <stdlib.h>
#include <stdio.h>
struct QNode
{
    int key;
    struct QNode *next;
};
struct QNode *front,*rear;
struct QNode* newNode(int k)
{
    struct QNode *temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp->key = k;
    temp->next = NULL;
    return temp;
}
void display()
{
	if (!(front->next))
    {
    	printf("QUEUE EMPTY\n");
       return;
    }
	struct QNode *temp = (struct QNode*)malloc(sizeof(struct QNode));
	temp=front->next;
	while((temp->next)!=NULL)
	{
		printf("%d<---",temp->key);
		temp=temp->next;
	}
	printf("%d\n",temp->key);
}
void enQueue(int k)
{
    struct QNode *temp = newNode(k);
    if (rear->next==NULL)
    {
       front->next=rear->next=temp;
       return;
    }
    struct QNode *ptr=front->next;
    while(ptr->next!=NULL)
    {
    	ptr=ptr->next;
    }
    ptr->next=temp;
    rear->next=temp;
}
void deQueue()
{
    if (!(front->next))
    {
    	printf("QUEUE EMPTY\n");
       return;
    }
    struct QNode *temp = front->next;
    if (front->next->next== NULL)
   	{
   		front->next=rear->next=NULL;
   	}
   	else
    	front = front->next;
   	free(temp);
}
int main()
{
	//clrscr();
    front=(struct QNode*)malloc(sizeof(struct QNode));
    rear=(struct QNode*)malloc(sizeof(struct QNode));
	front->next=rear->next=NULL;
    while(1)
	{
		printf("\n*MAIN MENU*\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT\n");
		int e,n;
		scanf("%d",&e);
		switch(e)
		{
			case 1:printf("Enter the Number :");
					scanf("%d",&n);
					enQueue(n);
					break;
			case 2:deQueue();
					break;
			case 3:display();
					break;
			case 4:exit(0);

		}
	}
    return 0;
}
