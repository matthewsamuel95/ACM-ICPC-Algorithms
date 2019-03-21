#include <bits/stdc++.h>
#define ll long long int

using namespace std;

//Structure to store the data for a node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

//Method to create a new node
Node* getnode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = nullptr;
    temp->right = nullptr;
    return temp;
}

//Insert a new node in a bst
Node* insert_node(Node* start,int data)
{
    if(!start)
        return getnode(data);
    else if(start->data > data)
        start->left = insert_node(start->left,data);
    else
        start->right = insert_node(start->right,data);
    return start;
}

//Inorder traversal of BST
void traverse(Node* start)
{
    if(!start)
        return ;
    traverse(start->left);
    cout<<start->data<<" ";
    traverse(start->right);
}

//Copy the inorder traversal to a temporary array
void copy_to_array(Node* start,int a[],int &carry)
{
    if(start)
    {
        copy_to_array(start->left,a,carry);
        a[carry++] = start->data;
        copy_to_array(start->right,a,carry);
    }
}

//Insert node in BST from array in preorder form to get Min heap
void preorder(Node** start,int a[],int &index)
{
    if(*start)
    {
        (*start)->data = a[index++];
        preorder(&((*start)->left),a,index);
        preorder(&((*start)->right),a,index);
    }
}

//Level order traversal
void level_order(Node* start)
{
    queue<Node*> q;
    q.push(start);
    q.push(getnode(-1));
    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        if(!q.empty() && temp->data == -1)
        {
            cout<<"\n";
            q.push(temp);
        }
        else if(temp->data!=-1)
            cout<<temp->data<<" ";
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
}

int main() 
{
    Node* start=nullptr;
    //Dummy insertion of nodes in the BST
    start = insert_node(start,10);
    start = insert_node(start,5);
    start = insert_node(start,7);
    start = insert_node(start,3);
    start = insert_node(start,12);
    start = insert_node(start,11);
    start = insert_node(start,13);
    
    traverse(start);
    cout<<"\n";
    
    int a[1000],count=0;
    memset(a,0,sizeof(a));
    copy_to_array(start,a,count);
    
    
    int index=0;
    preorder(&start,a,index);
    
    //Print the heap in level order
    level_order(start);
    return 0;
}

