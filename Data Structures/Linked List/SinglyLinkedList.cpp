/*A simple C++ program for singly linked list*/

#include <iostream>
using namespace std;
class Node{
public:
	int data;
	Node* next;
	Node(int value){
		data=value;
		next=NULL;
	}
};
Node* takeInput(){
	//size of the linked list
	int size;
	cin>>size;

	//head and tail of the linked list intialised to NULL
	Node* head=NULL;
	Node* tail=NULL;

	while(size--){
		//value to be inserted 
		int num;
		cin>>num;
		//creation of new node
		Node* newNode=new Node(num);

		//if there are no previous elements in the linked list
		if(head==NULL) head=tail=newNode;
		else{
			//else add the new node to the end of the tail
			//and make it tail
			tail->next=newNode;
			tail=newNode;
		}
	}
	return head;
}
void PrintLL(Node* head){

	Node* ptr=head;
	//transverse until it reaches the end node (NULL)
	while(ptr!=NULL){
		cout<<ptr->data<<" ";
		ptr=ptr->next;
	}
	cout<<endl;
}
int main(){
	//create the linked list
	Node* head=takeInput();	
	//print the linked list
	PrintLL(head);
	return 0;
}
//Test case
/*Input Example
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50*/