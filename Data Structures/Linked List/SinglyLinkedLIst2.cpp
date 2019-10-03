#include<bits/stdc++.h>

using namespace std;

class Node{
	public:
	int data;
	Node *next;
};

void PushFront(Node** head_ref, Node** tail, int key){
	Node* newnode = new Node();
	newnode->next = *head_ref;
	newnode->data = key;

	if(*tail == NULL){
		*tail = newnode;
	}

	*head_ref = newnode;
}

void AddAfter(Node* pre_node,Node** tail, int key){
	if(pre_node == NULL){
		cout<<"Node can't be null\n";
		return;
	}
	Node* newnode = new Node();
	newnode->data = key;
	newnode->next = pre_node->next;
	pre_node->next = newnode;

	if(pre_node == *tail)
		*tail = newnode;
}

void TopFront(Node** head_ref){
	if(*head_ref == NULL){
		cout<<"List is Empty\n";
		return;
	}
    Node* temp = *head_ref;
	cout<<"Top element: "<<temp->data<<endl;
}

void PopFront(Node** head_ref, Node** tail){
	if(*head_ref == NULL){
		cout<<"Error: Empty list\n";
		return;
	}
    Node* temp = *head_ref;
	cout<<"Deleted Element: "<<temp->data<<endl;
	*head_ref = temp->next;

	if(*head_ref == NULL)
		*tail = NULL;

}

void PushBack(Node** head_ref, Node** tail, int key){
	Node* newnode = new Node();
	newnode->data = key;
	newnode->next = NULL;

	if(*tail == NULL){
		*head_ref = newnode;
		*tail = newnode;
	}
	else{
		Node* temp = *tail;
		temp->next = newnode;
		*tail = newnode;
	}
}

void printList(Node* node){
	if(node == NULL){
		cout<<"Error: List is Empty"<<endl;
	}
	while(node->next != NULL){
		cout<<node->data<<" ";
		node=node->next;
	}
}
void TopBack(Node** tail){
	if(*tail == NULL){
		cout<<"Error: List is Empty\n";
		return;
	}
    Node* temp = *tail;
	cout<<"Last Element: "<<temp->data<<endl;
}

void PopBack(Node** head_ref, Node** tail){
	if(*head_ref == NULL){
		cout<<"Error: List is Empty\n";
		return;
	}
	Node* p=*head_ref;	
	while(p->next->next != NULL);
	p->next=NULL;
}

// bool find(int key){
	
// }

int main(){
	Node *head = NULL;
	Node *tail = NULL;
	while(1){
		int ch, num;
		cout<<"Enter your choice:\n1-Insert at front\n2-Insert at back\n3-Insert After\n4-delete from front\n5-delete from back\n6-First Element\n7-Last Element\n8-PrintList\n9-Exit->";
		cin>>ch;
		switch(ch){
			case 1:
				cout<<"Enter the Element: ";
				cin>>num;
				PushFront(&head, &tail, num);
				break;
			case 2:
				cout<<"Enter the Element: ";
				cin>>num;
				PushBack(&head, &tail, num);
				break;
			case 3:
				cout<<"Enter the Element: ";
				cin>>num;
				AddAfter(head->next, &tail, num);
				break;
			case 4:
				PopFront(&head, &tail);
				break;
			case 5:
				PopBack(&head, &tail);
				break;
			case 6:
				TopFront(&head);
				break;
			case 7:
				TopBack(&tail);
				break;
			case 8:
				printList(head);
				break;
			case 9:
				exit(0);
		}
	}


}


