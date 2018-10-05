#include <iostream>
#include <cstdlib> 
#include <list>
using namespace std;

list < int > arr;
struct node {
  int val;
  struct node * left, * right;
};
struct node * insert(int n) {
  struct node * temp = new struct node();
  temp - > val = n;
  temp - > left = NULL;
  temp - > right = NULL;
  return temp;
}
void inorder(struct node * root) {
  if (root != NULL) {
    inorder(root - > left);
    cout << root - > val << " ";
    arr.push_back(root - > val);
    inorder(root - > right);
  }
}
void postorder(struct node * root) {
  if (root != NULL) {
    postorder(root - > right);
    postorder(root - > left);
    cout << root - > val << " ";
  }
}
void preorder(struct node * root) {
  if (root != NULL) {
    cout << root - > val << " ";
    preorder(root - > left);
    preorder(root - > right);
  }
}
struct node * create(struct node * root, int n) {
  if (root == NULL)
    insert(n);
  else if (root - > val > n) {
    root - > left = create(root - > left, n);
  } else
    root - > right = create(root - > right, n);
}

bool find(struct node * root, int key) {
  if (root - > val > key && root - > left == NULL)
    return 0;
  if (root - > val < key && root - > right == NULL)
    return 0;
  if (root - > val == key)
    return 1;
  else if (root - > val > key) {
    find(root - > left, key);
  } else if (root - > val < key) {
    find(root - > right, key);
  } else
    return 0;
}
int main() {
  struct node * bst = NULL;
  cout<<"enter 1 to insert element"<<endl;
  cout<<"enter 2 to do preorder"<<endl;
  cout<<"enter 3 to do inorder"<<endl;
  cout<<"enter 4 to do postorder"<<endl;
  cout<<"enter 5 to exit"<<endl;
  int choice;
  cin>>choice;
  while(choice!=5)
  {
    
  switch(choice)
  {
    case 1:
      {
        int a;
        cout<<"enter the element to enter"<<endl;
        cin>>a;
        create(bst,a);
        break();
      }
    case 2:
      {
        preorder(bst);
        break();
      }
    case 3:
      {
        inorder(bst);
        break();
      }
    case 4:
      {
        postorder(bst);
        break();
      }
    default :
     {
       cout<<"entered Wrong option try again";
     }
  }
  cout<<"enter 1 to insert element"<<endl;
  cout<<"enter 2 to do preorder"<<endl;
  cout<<"enter 3 to do inorder"<<endl;
  cout<<"enter 4 to do postorder"<<endl;
  cout<<"enter 5 to exit"<<endl;
  cin>>choice;
}
  return 0;
}
