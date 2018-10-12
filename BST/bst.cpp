#include <iostream>
#include <cstdlib> 
#include <list>
using namespace std;

// Create binary searching tree structure
struct node {
  int val;
  struct node * left, * right;
};

// Insert a number n to node's val, and pointer node's left and right
// branch to NULL
struct node * insert(int n) {
  struct node * temp = new struct node();
  temp -> val = n;
  temp -> left = NULL;
  temp -> right = NULL;
  return temp;
}

// Inorder permutation, permutate from left to root to right,
// accordingly
void inorder(struct node * root) {
  if (root != NULL) {
    inorder(root -> left);
    cout << root -> val << " ";
    inorder(root -> right);
  }
}

// Postorder permutation, permutate from left to right to root,
// accoringly
void postorder(struct node * root) {
  if (root != NULL) {
    postorder(root -> right);
    postorder(root -> left);
    cout << root -> val << " ";
  }
}

// Preorder permutation, permutate from root to left to right,
// accorginly
void preorder(struct node * root) {
  if (root != NULL) {
    cout << root -> val << " ";
    preorder(root -> left);
    preorder(root -> right);
  }
}

// Create a new binary searching tree structure
struct node * create(struct node * root, int n) {
  // If root(node) is NULL, then insert a value n as it's value
  if (root == NULL)
    insert(n);
  // Find the node that is NULL, else if val > n, then check root's left
  // node is empty or not, else if val < n, then check root's right node
  // is empty or not
  else if (root -> val > n) {
    root -> left = create(root -> left, n);
  } else
    root -> right = create(root -> right, n);
}

// Find a specific node that the val is equal to key
bool find(struct node * root, int key) {
  // If val > key and the next left node is NULL, return not found(0)
  if (root -> val > key && root -> left == NULL)
    return 0;
	// If val < key and the next right node is NULL, return not found(0)
  if (root -> val < key && root -> right == NULL)
    return 0;
	// If val = key then return found(1)
  if (root -> val == key)
    return 1;
	// If val > key and the next left node is not NULL, then go to next
	// left node and keep searching
	// If val < key and the next right node is not NULL, then go to next
	// right node and keep searching
	// Else return not found(0)
  else if (root -> val > key) {
    find(root -> left, key);
  } else if (root -> val < key) {
    find(root -> right, key);
  } else
    return 0;
}
//This function counts the total number  of nodes in a tree
int countNodes(struct node * root){
  if(root==NULL)
    return 0;
  else
    return 1 + countNodes(root->left) + countNodes(root->right);
}


//This function calclulates the height of the binary search tree. 
int height(struct node *root){
  if(root==NULL)
    return 0;
  return 1 + max(height(root->left),height(root->right));
}


//This function calculates the diameter of the binary search tree.
int diameter(struct node *root){
  if(root == NULL)
    return 0;
  return max(1 + height(root->left) + height(root->right), max(diameter(root->left),diameter(root->right)));
}

int main() {
	// Init a empty node bst
  struct node * bst = NULL;
	// Input each value of bst
  bst = create(bst, 5);
  create(bst, 10);
  create(bst, 20);
  create(bst, 21);
  create(bst, 14);
  create(bst, 9);
  create(bst, 3);
  create(bst, 12);
  create(bst, 21);
	// Inorder permutate from left -> root -> right
  cout << "The Inorder traversal of the tree is : ";
  inorder(bst);
  cout << endl;
	// Postorder permutate from left -> right -> root
  cout << "The Postorder traversal of the tree is : ";
  postorder(bst);
  cout << endl;
	// Preorder permutate from root -> left -> right
  cout << "The Preorder traversal of the tree is : ";
  preorder(bst);
  cout << endl;
  // Count total number of nodes in the tree
  cout << "The number of nodes in the tree : ";
  cout << countNodes(bst) << endl;
  cout << "The height of the tree is : ";
  cout << height(bst) << endl;
  cout << "The diameter of the tree is : ";
  cout << diameter(bst) << endl;
  return 0;
}
