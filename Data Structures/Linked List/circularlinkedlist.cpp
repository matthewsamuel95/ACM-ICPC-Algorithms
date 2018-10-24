#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node* next;
};
Node* head;
void insertatlast(int data)
{
	Node* temp=new Node;
	temp->data=data;
	temp->next=NULL;
	if(head==NULL)
	{
		
		head=temp;
		temp->next=head;
	}
	else
	{
		 Node* temp2=head;
		 	Node* prev;
	while(temp2->next!=head)
	{    
		temp2=temp2->next;	
}
temp->next=head;
head=temp;
temp2->next=head;
}
}
void print()
{
	Node* temp=head;
	do{
	
	
		cout<<temp->data<<" ";
		temp=temp->next;
	} while(temp!=head);
}
main()
{ head=NULL;
	int i,x,v,n,d;
	cout<<"enter how many nodes you want"<<endl;
	cin>>n;
	for(i=0;i<n;i++)
	{    cin>>x;
		insertatlast(x);
		
	}
	
print();	
	
}
