#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node* next;
	
};
Node* head;
void insert(int data)
{
	Node* temp= new Node;
	temp->data=data;
	temp->next=head;
	head=temp;
}
void print()
{
	Node* temp=head;
	cout<<" list is: ";
	while(temp!=NULL)
	{
		cout<<temp->data;
		temp=temp->next;
	}
	cout<<endl;
}
void delete1()
{
	Node* temp1= head;
	Node* prev;
	while(temp1->next!=NULL)
		
		{ prev=temp1;
			temp1=temp1->next;
		}
		prev->next=NULL;
		delete temp1;
      
	
	
	
}

main()
{
	head=NULL;
	insert(2);
		insert(4);
			insert(6);
				insert(5);
				print();
				delete1();
				print();
}
