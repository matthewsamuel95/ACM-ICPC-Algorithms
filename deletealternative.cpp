#include<iostream>
using namespace std;
struct node
{
	int info;
	node* link;
};
void delete_alternative(node* head)
{
	if(head==NULL)
	{
		cout<<" underflow";
	}
	else
	{
	
	node* prev=head;
	node* cur=head->link;
	while(prev!=NULL && cur!=NULL)
	{
		prev->link=cur->link;
		delete cur;
		prev=prev->link;
		if(prev!=NULL)
		{
			cur=prev->link;
		}
	}
}
}
void insert(node** head,int data)
{
	node* temp=new node;
	temp->info=data;
	if(*head==NULL){
	
	temp->link=*head;
	*head=temp;
}
else
{
	node* temp2=*head;
	while(temp2->link!=NULL)
	{
		temp2=temp2->link;
	}
	temp2->link=temp;
	temp->link=NULL;
}
}
void print(node* head)
{
	while(head!=NULL)
	{
		cout<<head->info<<" ";
		head=head->link;
	}
}
void middle(node* head)
{
	node* fast=head;
	node* slow=head;
	if(head!=NULL)
	{
		while(fast!=NULL&& fast->link!=NULL)
		{
			fast=fast->link->link;
			slow=slow->link;
		}
		cout<<"\n middle nodes are\n";
		cout<<slow->info;
	}
}
void movetofront(node** head)
{
	if(*head==NULL || (*head)->link==NULL)
	{
		return;
	}
	node* seclast=NULL;
	node* last=*head;
	while(last->link!=NULL)
	{
		seclast=last;
		last=last->link;
	}
	seclast->link=NULL;
	last->link=*head;
	*head=last;
}
main()
{
	node* head=NULL;
	insert(&head,2);
	insert(&head,6);
	insert(&head,8);
	insert(&head,4);
	insert(&head,10);
	insert(&head,12);
	insert(&head,14);
		print(head);
		cout<<"\n move last node to first node\n";
		movetofront(&head);
		cout<<"\n";
		print(head);
		cout<<"\ndelete alternative nodes from the list are:\n";
	delete_alternative(head);
	print(head);
	middle(head);
}
