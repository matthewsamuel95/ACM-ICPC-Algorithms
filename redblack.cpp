#include <iostream>
using namespace std;
struct node{
	int val;
	int color;//let 0 be black and 1 be red
	node *left;
	node *right;
	node *parent;
};
class RedBlack{
public:
	node *root;
	node *q; 
	RedBlack(){
		root = NULL;
		q = NULL;
	}

	void leftRotate(node *p){
		if(p -> right == NULL){
			return;

		}else{

			node *y = p -> right;
			if(y -> left != NULL){

				p -> right = y -> left;
				y -> left -> parent = p;

			}else{
				p -> right = NULL;
			}

			if(p -> parent != NULL){
				y -> parent = p -> parent;
			}

			if(p -> parent == NULL){
				root = y;
			}else{ 

				if(p == p-> parent -> left){
					p -> parent -> left = y;
				}else{
					p -> parent -> right = y;
				}
			}

			y->left = p;
			p -> parent = y;
		}
	}


	void rightRotate(node *p){

		if(p -> left == NULL){
			return;
		}else{

			node *y = p -> left;
			if(y -> right != NULL){

				p -> left = y -> right;
				y -> right -> parent = p;

			}else{
				p -> left = NULL;
			}

			if(p -> parent != NULL){
				y -> parent = p -> parent;
			}

			if(p -> parent == NULL){
				root = y;
			}else{ 

				//!!!!!!!!!!!!!!!!!!!!!!!!
				if(p == p-> parent -> right){
					p -> parent -> right = y;
				}else{
					p -> parent -> left = y;
				}

			}

			y->right = p;
			p -> parent = y;
		}

		
	}

	void insertFix(node *z){

		if (root == z){
			z -> color = 0; //root should be black
			return;
		}
		node *uncle;
		while(z -> parent != NULL && z -> parent -> color == 1){
			node *grandpa = z -> parent -> parent;


			if(grandpa -> left == z -> parent){ 

				if(grandpa -> right != NULL){
					uncle = grandpa -> right;
					if(uncle -> color == 1) { //uncle is red case
					//recolor parent, grandparent and uncle
						z -> parent -> color = 0;
						grandpa -> color = 1;
						uncle -> color = 0;
						z = grandpa;
					}

				}

				else{

					if( z == z -> parent -> right){ //line case
						//rotate parent
						z = z -> parent;
						leftRotate(z);
					}

					z -> parent -> color = 0;
					grandpa -> color = 1;
					rightRotate(grandpa);

				} 	
			}


			else {
				if(grandpa -> left != NULL){
					uncle = grandpa -> left;
					if(uncle -> color == 1){
						//recolor parent, grandparent and uncle
						z -> parent -> color = 0;
						grandpa -> color = 1;
						uncle -> color = 0;
						z = grandpa;
					}
				}else{
					if(z == z -> parent ->left){
						z = z->parent;
						rightRotate(z);
					}
					z -> parent -> color = 0;
					grandpa -> color = 1;
					rightRotate(grandpa);
				}

			}

			root -> color = 0;
		}

	}


	void insert(int val){

		//!!!!!!!!!!!!!
		node *p, *q; 
		node *z = new node;

		z -> val = val;
		z -> right = NULL;
		z -> left = NULL;
		z->color = 1;

		p = root; 
		q = NULL;

		if(root == NULL){
			root = z;
			z -> parent = NULL;
			cout << "first element is inserted" << endl;
		}else{
			while(p != NULL){
				q = p;
				if(z -> val > p -> val){
					p = p -> left;
				}else{
					p = p -> right;
				}
			}
			z -> parent = q;
			if(q -> val < z -> val){
              q -> right = z;
              cout << "Z > Q" << endl;
			}
         	else{
              q -> left = z;
              cout << "Z <= Q" << endl;
         	}
		}

		insertFix(z);
		
	}
	node* successor(node *p)
	{
      	node *y=NULL;
	    if(p->left!=NULL)
	    {
	        y=p->left;
	        while(y->right!=NULL){
	        	y=y->right;
	        }
	              
	    }
	    else
	    {
	        y=p->right;
	        while(y->left!=NULL){
	        	y=y->left;
	        }
	              
	    }
	    return y;
	}
	void delfix(node *p)
	{
	    node *s;
	    while(p != root && p-> color == 0)
	    {
	          if(p -> parent -> left == p)
	          {
	                  s = p -> parent -> right;
	                  if(s -> color == 1)
	                  {
	                         s -> color = 0;
	                         p -> parent -> color = 1;
	                         leftRotate(p -> parent);
	                         s = p -> parent -> right;
	                  }
	                  if(s -> right -> color == 0 && s -> left -> color == 0)
	                  {
	                         s->color= 1;
	                         p=p->parent;
	                  }
	                  else
	                  {
	                      if(s -> right -> color == 0 )
	                      {
	                             s -> left -> color = 0;
	                             s -> color = 1;
	                             rightRotate(s);
	                             s = p-> parent -> right;
	                      }
	                      s -> color = p -> parent -> color;
	                      p -> parent -> color = 0;
	                      s -> right -> color = 0;
	                      leftRotate(p -> parent);
	                      p = root;
	                  }
	          }
	          else
	          {
	                  s = p -> parent -> left;
	                  if(s -> color == 1)
	                  {
	                        s -> color = 0;
	                        p -> parent -> color = 1;
	                        rightRotate(p -> parent);
	                        s = p -> parent -> left;
	                  }
	                  if(s -> left -> color == 0 && s -> right -> color == 0)
	                  {
	                        s -> color = 1;
	                        p = p -> parent;
	                  }
	                  else
	                  {
	                        if(s -> left -> color == 0)
	                        {
	                              s -> right -> color = 0;
	                              s -> color = 1;
	                              leftRotate(s);
	                              s = p -> parent -> left;
	                        }
	                        s -> color = p -> parent -> color;
	                        p -> parent -> color = 0;
	                        s -> left -> color = 0;
	                        rightRotate(p -> parent);
	                        p = root;
	                  }
	          }
	        p -> color = 0;
	        root -> color = 0;
	    }
	}

	void deleteVal (int val){
		if(root == NULL){
			cout << "empty" << endl;
			return;
		}
		node *p;
		p = root;
		node *y = NULL;
		node *q = NULL;
		bool found = false;

		while(p != NULL && found == false){
			if(p -> val == val){
				found = true;
			}
			if(found == false){
				if(p -> val < val){
					p = p -> right;
				}else{
					p = p -> left;
				}
			}
		}

		if(found == false){
			cout << "ooops, element is not found" << endl;
			return;
		}
		else{
			cout << "element deleted " << p -> val << endl;

		}
		if(p -> left == NULL || p -> right == NULL){
			y = p;
		}else{
              y = successor(p);
        }
        if(y -> left != NULL){
				q = y-> left;
        }
         else
         {
              if(y-> right != NULL){

                   q = y-> right;
              }
              else{
                   q = NULL;
              }
         }

        if(q != NULL){
              q -> parent = y -> parent;
        }

        if(y -> parent == NULL){
              root=q;
        }

        else
        {
            if(y == y -> parent -> left){

                y -> parent -> left = q;
            }else{
                y -> parent -> right = q;
            }
        }

        if(y!=p)
        {=
            p -> color = y -> color;
            p -> val = y -> val;
        }

        if(y -> color == 0){
             delfix(q);
        }
     

	}

};
int main(){
	RedBlack *rb = new RedBlack();
	rb->insert(8);
	rb->insert(3);
	rb->insert(82);
	return 0;
}