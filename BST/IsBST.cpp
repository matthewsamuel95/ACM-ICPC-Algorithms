

/*
Given the root node of a Binary Tree, write a method - IsBST to determine if it is a Binary Search Tree.

A BST must satisfy the following conditions : 
* The left subtree of a node contains nodes with data < its data.
* The right subtree of a node contains  nodes data > its data.
* A node's left and right subtrees follow the above two conditions.
Examples:
  
          20
         /   \
       15    30
      /  \
     14  18     
    output ==> true
    
    
          20
         /   \
       30    15 
      /  \                           
     14  18     
   output ==> false
   
 */
 
 
 
# 1st method (Recursive)
 
 
struct treeNode{
    int value;                  /* value of the node */
    struct treeNode* left;      /* left pointer to the left child node */
    struct treeNode* right;     /* right pointer to the right child node */
}; 
 
bool isBst(treeNode *root, int min, int max)
{
    if(!root)
        return 1;
    
    return (root->value > min && root->value < max 
            && isBst(root->left, min, root->value) 
            && isBst(root->right, root->value, max));
    
}
bool validate_bst(treeNode* root)
{
    int min = INT_MIN;
    int max = INT_MAX;
    return isBst(root, min, max);

}




# 2nd method (Iterative)

struct treeNode{
    int value;                  /* value of the node */
    struct treeNode* left;      /* left pointer to the left child node */
    struct treeNode* right;     /* right pointer to the right child node */
};
  
bool isBst(treeNode* root)
{
    if (!root) 
        return true;
        
    std::stack<treeNode*> st;
    
    treeNode* prev = NULL;
    
    while (!st.empty() || root) 
    {
        while(root) 
        {
            st.push(root);
            root = root->left;
        }
        
        root = st.top();
        st.pop();
        
        if (prev && prev->value >= root->value) 
            return false;
            
        prev = root;
        root = root->right;
        
    }
    
    return true;
    
}



