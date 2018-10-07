#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int key;
    struct node *left, *right;
};
struct node *root;
 
// A utility function to create a new BST node
struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
};

struct node* search(struct node* curr, int key)
{
    // Base Cases: root is null or key is present at root
    if (curr == NULL || curr->key == key)
       return curr;
    
    // Key is greater than root's key
    if (curr->key < key)
       return search(curr->right, key);
 
    // Key is smaller than root's key
    return search(curr->left, key);
}
 
// A utility function to do inorder traversal of BST
void inorder(struct node *curr)
{
    if (curr != NULL)
    {
        inorder(curr->left);
        printf("%d ", curr->key);
        inorder(curr->right);
    }
}
 
/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* curr, int key)
{
    /* If the tree is empty, return a new node */
    if (curr == NULL) 
        return newNode(key);
 
    /* Otherwise, recur down the tree */
    if (key < curr->key)
        curr->left=insert(curr->left, key);
    else
        curr->right=insert(curr->right, key);
 
    return curr;
}
 
/* Given a non-empty binary search tree, return the node with minimum
   key value found in that tree. Note that the entire tree does not
   need to be searched. */
struct node* minValueNode(struct node* curr)
{
    struct node* current = curr;
 
    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;
 
    return curr;
}
 
/* Given a binary search tree and a key, this function deletes the key
   and returns the new root */
struct node* deleteNode(struct node* curr, int key)
{
    // base case
    if (curr == NULL) 
        return curr;
 
    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < curr->key)
        curr->left = deleteNode(curr->left, key);
 
    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > curr->key)
        curr->right = deleteNode(curr->right, key);
 
    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (curr->left == NULL)
        {
            struct node *temp = curr->right;
            free(curr);
            return temp;
        }
        else if (curr->right == NULL)
        {
            struct node *temp = curr->left;
            free(curr);
            return temp;
        }
 
        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        struct node* temp = minValueNode(curr->right);
 
        // Copy the inorder successor's content to this node
        curr->key = temp->key;
 
        // Delete the inorder successor
        curr->right = deleteNode(curr->right, temp->key);
    }
    return curr;
}

int main() 
{
    int key,ch;
    printf("insert first element:");
    scanf("%d",&key);
    root=insert(root,key);
    do
    {
        printf("\n\nOperations on BST");
        printf("\n1. Insert\n2. Delete\n3. Search\n4. Inorder\n0. Exit\n");
        printf("\nEnter Choice 0-4? : ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                printf("\nEnter number: ");
                scanf("%d", &key);
                insert(root,key);
                break;
            case 2:
                printf("\nEnter number: ");
                scanf("%d", &key);
                deleteNode(root,key);
                break;
            case 3:
                printf("\nEnter number: ");
                scanf("%d", &key);
                search(root,key);
                break;
            case 4:
                inorder(root);
                break;
        }
    }while (ch != 0);

   return 0;
}