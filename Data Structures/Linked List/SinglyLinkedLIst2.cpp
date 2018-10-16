#include "iostream"
#include "cstdlib"
using namespace std;
struct Node
{
	int data;
	Node* link;
};
Node* A;
void insert()
{
	int n,p;
	cout<<"Enter the no to be Inserted:";
	cin>>n;
	cout<<"Enter the position:";
	cin>>p;
	Node* temp=new Node;
	if (p==1)
	{
		temp->link=A;
		temp->data=n;
		A=temp;
		return;
	}
	Node* temp2=A;
	for(int i=1;i<p-1;i++)
	{
		temp2=temp2->link;
	}
	temp->link=temp2->link;
	temp2->link=temp;
	temp->data=n;
}
void delet()
{
	int p;
	cout<<"Enter the position of the element to be deleted:";
	cin>>p;
	Node* temp=A;
	if (p==1)
	{
		A=temp->link;
		temp=NULL;
		return;
	}
	Node* temp2=new Node;
	for(int i=1;i<p-1;i++)
	{
		temp=temp->link;
	}
	temp2=temp->link;
	temp->link=temp2->link;
	temp2=NULL;

}
void display()
{
	Node* temp=A;
	while(temp!=NULL)
	{
		cout<<"->"<<temp->data;
		temp=temp->link;
	}
	cout<<"\n"<<"---------------------------"<<"\n";
}
void count()
{
	int c=0;
	Node* temp=A;
	while(temp!=NULL)
	{
		c++;
		temp=temp->link;
	}
	cout<<c<<endl;
}
void rev()
{
	Node* temp=A;
	Node* temp2=new Node;
	Node* prev=temp->link;
	while(prev!=NULL)
	{
		temp2=prev->link;
		prev->link=temp;
		temp=prev;
		prev=temp2;
	}
	A->link=NULL;
	A=temp;
}
int main()
{
	A=NULL;
	while(1)
	{
		int ch;
		cout<<"Enter your choice:\n1-Insert\n2-Delete\n3-Display\n4-Reverse\n5-Count\n6-Exit\n->";
		cin>>ch;
		switch(ch)
		{
			case 1:
				insert();
				break;
			case 2:
				delet();
				break;
			case 3:
				display();
				break;
			case 4:
				rev();
				break;
			case 5:
				count();
				break;
			case 6:
				exit(0);
		}
	}
}

