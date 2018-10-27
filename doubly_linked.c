#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void insertfirst(void);
void insertlast(void);
void insertbtw(void);
void deletefirst(void);
void deletelast(void);
void deletebtw(void);
void searchfront(int i);
void searchback(int i);
int compare(char a[],char b[]);
void displayfront(void);
void displayback(void);
struct info *newnode(void);
int count(void);

struct node
{
	char name[20];
	char roll[9];
	float cgpa;
	struct node *next;
	struct node *prev;
} *head,*tail;

int main()
{       clrscr();
	head=NULL;
	tail=NULL;
	printf("This program creates a doubly linear linked list.\n\n");
	int i,j;
	while(1)
	{
		printf("Enter 1 for Insertion\nEnter 2 for Deletion\nEnter 3 for Search\nEnter 4 for Display\nEnter 5 for exit.\n\n");
		scanf("%d",&i);
		if(i==5)
		{
			return 0;
		}
		switch(i)
		{
			case 1:
				printf("Enter 1 for insertion at first node\nEnter 2 for insertion at last node\nEnter 3 for insertion in between node.\n\n");
				scanf("%d",&i);
				switch(i)
				{
					case 1:
						insertfirst();
						break;

					case 2:
						insertlast();
						break;

					case 3:
						insertbtw();
						break;

					default:
						printf("Error in input.\n");
						break;
				}
				break;

			case 2:
				if(head==NULL)
				{
					printf("List Empty.\nNo deletion is possible.\n");
					break;
				}
				printf("Enter 1 for deletion at first node\nEnter 2 for deletion at last node\nEnter 3 for deletion in between node.\n\n");
				scanf("%d",&i);
				switch(i)
				{
					case 1:
						deletefirst();
						break;

					case 2:
						deletelast();
						break;

					case 3:
						deletebtw();
						break;

					default:
						printf("Error in input.\n");
						break;
				}
				break;

			case 3:
				if(head==NULL)
				{
					printf("List Empty.\nNo search is possible.\n");
					break;
				}
				printf("Enter 1 for search by name\nEnter 2 for search by roll number\nEnter 3 for search by cgpa.\n");
				scanf("%d",&i);
				if(i<1||i>3)
				{
					printf("Error in input.\n");
				}
				else
				{
					printf("Enter 1 for forward search.\nEnter 2 for backward search.\n");
					scanf("%d",&j);
					switch(j)
					{
						case 1:
							searchfront(i);
							break;

						case 2:
							searchback(i);
							break;

						default:
							printf("ERROR IN INPUT.\n");
							break;
					}
				}
				break;

			case 4:
				if(head==NULL)
				{
					printf("LIST EMPTY.\n");
					break;
				}
				printf("Enter 1 for front display.\nEnter 2 for back display.\n");
				scanf("%d",&i);
				switch(i)
				{
					case 1:
						displayfront();
						break;

					case 2:
						displayback();
						break;

					default:
						printf("ERROR IN INPUT.\n");
						break;
				}
				break;

			default:
				printf("Error in input.\n");
				break;
		}
	}
	getch();
	return 0;
}

struct node *newnode(void)
{
	struct node *n=(struct node*)malloc(sizeof(struct node));
	printf("Enter Name.\n");
	gets(n->name);
	printf("Enter Roll number.\n");
	gets(n->roll);
	printf("Enter cgpa.\n");
	scanf("%f",&n->cgpa);
	n->next=NULL;
	n->prev=NULL;
	return n;
}

void insertfirst(void)
{
	struct node *temp,*temp1;
	temp=newnode();
	if(head==NULL)
	{
		head=temp;
		tail=temp;
		return;
	}
	temp1=head;
	head->prev=temp;
	head=temp;
	head->next=temp1;
}

void insertlast(void)
{
	struct node *temp,*temp1;
	temp=newnode();
	if(head==NULL)
	{
		head=temp;
		tail=temp;
		return;
	}
	temp1=head;
	while(temp1->next!=NULL)
	{
		temp1=temp1->next;
	}
	tail=temp;
	temp1->next=temp;
	temp->prev=temp1;
}

void insertbtw(void)
{
	int i,j;
	struct node *temp,*temp1,*temp2;
	printf("Enter the position at which node is to be inserted.\n");
	scanf("%d",&i);
	if(i>count()+1)
	{
		printf("\nINVALID POSITION.\n");
		return;
	}
	if(i==1)
	{
		insertfirst();
		return;
	}
	if(i==count()+1)
	{
		insertlast();
		return;
	}
	temp=newnode();
	temp1=head;
	for(j=1;j<=i-2;j++)
	{
		temp1=temp1->next;
	}
	temp2=temp1->next;
	temp1->next=temp;
	temp->prev=temp1;
	temp->next=temp2;
	temp->next->prev=temp;
}

void deletefirst(void)
{
	if(head==NULL)
	{
		printf("\nLIST EMPTY.\nNO DELETION IS POSSIBLE.\n");
		return;
	}
	struct node *temp;
	temp=head;
	head=head->next;
	if(head==NULL)
	{
		tail=NULL;
	}
	else
	{
		head->prev=NULL;
	}
	printf("\nThe entry deleted is -\n");
	printf("\nNAME       : %s\nROLL NUMBER: %s\nCGPA       : %.2f\n",temp->name,temp->roll,temp->cgpa);
	free(temp);
}

void deletelast(void)
{
	if(head==NULL)
	{
		printf("\nLIST EMPTY.\nNO DELETION IS POSSIBLE.\n");
		return;
	}
	struct node *temp,*temp1;
	temp=head;
	if(temp->next==NULL)
	{
		deletefirst();
		return;
	}
	while(temp->next->next!=NULL)
	{
		temp=temp->next;
	}
	temp1=temp->next;
	temp->next=NULL;
	tail=temp;
	printf("\nThe entry deleted is -\n");
	printf("\nNAME       : %s\nROLL NUMBER: %s\nCGPA       : %.2f\n",temp1->name,temp1->roll,temp1->cgpa);
	free(temp1);
}

void deletebtw(void)
{
	if(head==NULL)
	{
		printf("\nLIST EMPTY.\nNO DELETION IS POSSIBLE.\n");
		return;
	}
	struct node *temp,*temp1,*temp2;
	int i,j;
	printf("Enter the position at which the node is to be deleted.\n");
	scanf("%d",&i);
	if(i>count())
	{
		printf("\nINVALID POSITION.\n");
		return;
	}
	if(i==1)
	{
		deletefirst();
		return;
	}
	if(i==count())
	{
		deletelast();
		return;
	}
	temp=head;
	for(j=1;j<=i-2;j++)
	{
		temp=temp->next;
	}
	temp1=temp->next;
	temp2=temp1->next;
	temp->next=temp2;
	temp->next->prev=temp;
	printf("\nThe entry deleted is -\n");
	printf("\nNAME       : %s\nROLL NUMBER: %s\nCGPA       : %.2f\n",temp1->name,temp1->roll,temp1->cgpa);
	free(temp1);
}

void searchfront(int i)
{
	struct node *temp;
	float b;
	char a[20];
	temp=head;
	int j,k=0;
	switch(i)
	{
		case 1:
			printf("Enter Name to be searched.\n");
			scanf("%s",a);
			while(temp!=NULL)
			{
				k++;
				j=compare(a,temp->name);
				if(j==0)
				{
					printf("\nNAME       : %s\nROLL NUMBER: %s\nCGPA       : %.2f\n",temp->name,temp->roll,temp->cgpa);
					printf("Found at position = %d\n",k);
					return;
				}
				temp=temp->next;
			}
			printf("\nGiven name not found.\n");
			break;

			case 2:
			printf("Enter ROLL NUMBER to be searched.\n");
			scanf("%s",a);
			while(temp!=NULL)
			{
				k++;
				j=compare(a,temp->roll);
				if(j==0)
				{
					printf("\nNAME       : %s\nROLL NUMBER: %s\nCGPA       : %.2f\n",temp->name,temp->roll,temp->cgpa);
					printf("Found at position = %d\n",k);
					return;
				}
				temp=temp->next;
			}
			printf("\nGiven roll number not found.\n");
			break;

			case 3:
			printf("Enter CGPA to be searched.\n");
			scanf("%f",&b);
			while(temp!=NULL)
			{
				k++;
				if(b==temp->cgpa)
				{
					printf("NAME       : %s\nROLL NUMBER: %s\nCGPA       : %.2f\n",temp->name,temp->roll,temp->cgpa);
					printf("Found at position = %d\n",k);
					return;
				}
				temp=temp->next;
			}
			printf("\nGiven CGPA not found.\n");
			break;
	}
}

void searchback(int i)
{
	struct node *temp;
	float b;
	char a[20];
	temp=tail;
	int j,k=0;
	switch(i)
	{
		case 1:
			printf("Enter Name to be searched.\n");
			scanf("%s",a);
			while(temp!=NULL)
			{
				k++;
				j=compare(a,temp->name);
				if(j==0)
				{
					printf("\nNAME       : %s\nROLL NUMBER: %s\nCGPA       : %.2f\n",temp->name,temp->roll,temp->cgpa);
					printf("Found at position = %d\n",k);
					return;
				}
				temp=temp->prev;
			}
			printf("\nGiven name not found.\n");
			break;

			case 2:
			printf("Enter ROLL NUMBER to be searched.\n");
			scanf("%s",a);
			while(temp!=NULL)
			{
				k++;
				j=compare(a,temp->roll);
				if(j==0)
				{
					printf("\nNAME       : %s\nROLL NUMBER: %s\nCGPA       : %.2f\n",temp->name,temp->roll,temp->cgpa);
					printf("Found at position = %d\n",k);
					return;
				}
				temp=temp->prev;
			}
			printf("\nGiven roll number not found.\n");
			break;

			case 3:
			printf("Enter CGPA to be searched.\n");
			scanf("%f",&b);
			while(temp!=NULL)
			{
				k++;
				if(b==temp->cgpa)
				{
					printf("NAME       : %s\nROLL NUMBER: %s\nCGPA       : %.2f\n",temp->name,temp->roll,temp->cgpa);
					printf("Found at position = %d\n",k);
					return;
				}
				temp=temp->prev;
			}
			printf("\nGiven CGPA not found.\n");
			break;
	}
}

int compare(char a[],char b[])
{
	int i,m;
	for(i=0;(a[i]!='\0')&&(b[i]!='\0');i++)
	{
		m=a[i]-b[i];
		if(m!=0)
		{
			return m;
		}
	}
	if((a[i]=='\0')&&(b[i]=='\0'))
	{
		return 0;
	}
	else
	{
		m=a[i]-b[i];
		return m;
	}
}

void displayfront(void)
{
	struct node *temp=head;
	printf("The list is -\n");
	while(temp!=NULL)
	{
		printf("NAME       : %s\nROLL NUMBER: %s\nCGPA       : %.2f\n\n",temp->name,temp->roll,temp->cgpa);
	temp=temp->next;
	}
}

void displayback(void)
{
	struct node *temp=tail;
	printf("The list is -\n");
	while(temp!=NULL)
	{
		printf("NAME       : %s\nROLL NUMBER: %s\nCGPA       : %.2f\n\n",temp->name,temp->roll,temp->cgpa);
	temp=temp->prev;
	}
}

int count(void)
{
	struct node *temp;
	int i=0;
	temp=head;
	while(temp!=NULL)
	{
		i++;
		temp=temp->next;
	}
	return i;
}
