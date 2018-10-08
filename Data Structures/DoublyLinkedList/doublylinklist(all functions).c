#include <stdio.h>
#include <stdlib.h>
typedef struct nodetype{
	int data;
	struct nodetype *left,*right;
}node;
int count=0;
node *create_node()
{
	node *ptr;
	ptr=(node*)malloc(sizeof(node));
	printf("Enter number: ");
	scanf("%d",&ptr->data);
	ptr->right=NULL;
	ptr->left=NULL;
	count++;
	return ptr;
}
node* create_list(node *headp,int num)
{
	node *ptr; int i;
	ptr=headp;
	for(i=0;i<num;i++)
	{
		ptr->right=create_node();
		(ptr->right)->left=ptr;
		ptr=ptr->right;
	}
	return ptr;// new tail
}
void display(node *headp)
{
	node *ptr=headp;
	printf("------------------------------\n");
	while(ptr!=NULL)
	{
		printf("%d=>",ptr->data);
		ptr=ptr->right;
	}
	printf("\nCount=%d\n",count);
}
node* insert_tail(node *tailp)
{
	node *ptr=tailp,*newnode;
	newnode=create_node();
	ptr->right=newnode;
	newnode->left=ptr;
	newnode->right=NULL;
	tailp=newnode;
	return tailp;
}
node *insert_head(node* headp)
{
	node *ptr=headp,*newnode;
	newnode=create_node();
	newnode->right=ptr;
	ptr->left=newnode;
	newnode->left=NULL;
	headp=newnode;
	return headp;//updated head
}
node *del_head(node* headp)
{
	node *ptr;
	ptr=headp;
	headp=ptr->right;
	if(headp!=NULL)
		headp->left=NULL;
	count--;
	free(ptr);
	return headp;//updated head
}
node* del_end(node* tailp)
{
	node *ptr;
	ptr=tailp;
	tailp=ptr->left;
	if(tailp!=NULL)
		tailp->right=NULL;
	count--;
	free(ptr);
	return tailp;//updated tail
}
void insert_at(node *headp,int pos)
{
	node *ptr,*newnode;
	ptr=headp; int i;
	for(i=1;i<pos;i++)
	{
		ptr=ptr->right;
	}
	newnode=create_node();
	newnode->right=ptr;
	ptr->left=newnode;
	newnode->left=ptr->left;
	(ptr->left)->right=newnode;
}
void delete_at(node *headp,int pos)
{
	node *ptr;
	ptr=headp;
	int i;
	for(i=1;i<pos;i++)
	{
		ptr=ptr->right;
	}
	(ptr->left)->right=ptr->right;
	(ptr->right)->left=ptr->left;
	count--;
	free(ptr);
}
void reverse(node **head,node **tail)
{
	node *temp,*ptr;
	ptr=*head;
	while(ptr!=NULL)
	{
		temp=ptr->right;
		ptr->right=ptr->left;
		ptr->left=temp;
		ptr=temp;
	}
	temp=*head;
	*head=*tail;
	*tail=temp;
}
int main()
{
	node *head=NULL,*tail=NULL;
	int n,c,pos;
	while(1)
	{
		printf("1.create list\n2.display\n3.insert_tail\n4.insert head\n5.delete head\n6.delete end\n7.insert at\n8.delete at\n9.reverse\n10.exit\n");
		printf("Enter choice= ");
		scanf("%d",&c);
		switch(c)
		{
			case 1: if(count==0)
					{
						printf("Enter no. of list nodes to be created: ");
						scanf("%d",&n);
						if(n>=1)
						{
							head=(node*)malloc(sizeof(node));
							head->right=NULL;
							head->left=NULL;
							printf("Enter number: ");
							scanf("%d",&head->data);
							tail=head;
							count++;
						}
						if(n>1)
							tail=create_list(head,n-1);
					}
					else 
						printf("List already created\n");
					break;
			case 2:	if(count==0)
						printf("List empty\n");
					else
						display(head);
					break;
			case 3: if(count==0)
						printf("Create list first\n");
					else
						tail=insert_tail(tail);
					break;
			case 4: if(count==0)
						printf("Create list first\n");
					else
						head=insert_head(head);
					break;
			case 5: if(count==0)
						printf("List Empty\n");
					else
						head=del_head(head);
					break;
			case 6: if(count==0)
						printf("List Empty\n");
					else
						tail=del_end(tail);
					break;
			case 7:	if(count!=0)
					{
						printf("Enter position\n");
						scanf("%d",&pos);
						if(pos>count+1 ||pos<=0)
							printf("Wrong position\n");
						else if(pos==1)
							head=insert_head(head);
						else if(pos==count+1)
							tail=insert_tail(tail);
						else
							insert_at(head,pos);
					}
					else
						printf("Not possible\n");
					break;
			case 8: if(count!=0)
					{
						printf("Enter position\n");
						scanf("%d",&pos);
						if(pos>count ||pos<=0)
							printf("Wrong position\n");
						else if(pos==1)
							head=del_head(head);
						else if(pos==count)
							tail=del_end(tail);
						else
							delete_at(head,pos);
					}
					else
						printf("Not possible\n");
					break;
			case 9: if(count==0)
						printf("List Empty\n");
					else
						reverse(&head,&tail);
					break;
			case 10: exit(0);
					 break;
			default: printf("Wrong choice\n");
		}
		printf("------------------------------\n");
	}
	return 0;
}
