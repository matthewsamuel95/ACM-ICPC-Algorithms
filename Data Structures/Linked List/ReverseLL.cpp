#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node* next;
	
};
void rprint(Node* p)
{ if(p==NULL)
{   cout<<endl;
	return;
}
rprint(p->next);
cout<<p->data;
	
}

Node* insert( Node* head,int data)
{
	Node* temp= new Node;
	temp->data=data;
	temp->next=NULL;
	if(head==NULL)
	{
		head=temp;	
	}
	else
	 {
	 Node* temp1= head;
	 while(temp1->next!=NULL)
	 
	 	temp1=temp1->next;
	 	temp1->next=temp;
	 }
	 return head;
}
main()
{
	Node* head=NULL;
	head=insert(head,2);
		head=insert(head,4);
			head=insert(head,6);
				head=insert(head,5);
				rprint(head);
}
