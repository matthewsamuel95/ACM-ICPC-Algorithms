#include<stdio.h>
#include<stdlib.h>

struct node {
    int key;
    int height;
    struct node *left;
    struct node *right;
};

int max(int a, int b){
    return (a>b) ? a : b;
}

int height(struct node *n){
    if(n == NULL){
        return 0;
    }
    return n->height;
}

struct node* newNode(int key){
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->key = key;
    n->left = NULL;
    n->right = NULL;
    n->height = 1;
    return (n);
}

struct node *rightRotate(struct node *y){
    struct node *x = y->left;
    struct node *T2 = x->right;

    // Perform Rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return new root 
    return x;
}

struct node *leftRotate(struct node *x){
    struct node *y = x->right; 
    struct node *T2 = y->left; 
  
    // Perform rotation 
    y->left = x; 
    x->right = T2; 
  
    //  Update heights 
    x->height = max(height(x->left), height(x->right)) + 1; 
    y->height = max(height(y->left), height(y->right)) + 1; 
  
    // Return new root 
    return y; 
}

int getBalance(struct node *N){ 
    if (N == NULL) 
        return 0; 
    return height(N->left) - height(N->right); 
} 

// Recursive function to insert a key in the subtree rooted 
// with node and returns the new root of the subtree. 
struct node* insert(struct node* node, int key){ 
    /* 1.  Perform the normal BST insertion */
    if (node == NULL) 
        return(newNode(key)); 
  
    if (key < node->key){
        node->left  = insert(node->left, key); 
    }
    else if (key > node->key){
        node->right = insert(node->right, key); 
    }
    else{ // Equal keys are not allowed in BST 
        return node; 
    }
  
    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left), 
                           height(node->right)); 
  
    /* 3. Get the balance factor of this ancestor 
          node to check whether this node became 
          unbalanced */
    int balance = getBalance(node); 
  
    // If this node becomes unbalanced, then 
    // there are 4 cases 
  
    // Left Left Case 
    if (balance > 1 && key < node->left->key) 
        return rightRotate(node); 
  
    // Right Right Case 
    if (balance < -1 && key > node->right->key) 
        return leftRotate(node); 
  
    // Left Right Case 
    if (balance > 1 && key > node->left->key){ 
        node->left =  leftRotate(node->left); 
        return rightRotate(node); 
    } 
  
    // Right Left Case 
    if (balance < -1 && key < node->right->key){ 
        node->right = rightRotate(node->right); 
        return leftRotate(node); 
    } 
  
    /* return the (unchanged) node pointer */
    return node; 
} 

// print the inorder traversal of a tree
void inOrder(struct node *root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    printf("%d ", root->key);
    inOrder(root->right);
}

int main(){
    struct node *root = NULL;

    root = insert(root, 10);
    root = insert(root, 20); 
    root = insert(root, 30); 
    root = insert(root, 40); 
    root = insert(root, 50); 
    root = insert(root, 25);

    printf("inorder traversal of the constructed AVL Tree is \n");
    inOrder(root);

    return 0;
}