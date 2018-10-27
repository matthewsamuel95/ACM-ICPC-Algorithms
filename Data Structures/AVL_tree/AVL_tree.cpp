#include <bits/stdc++.h>
class avl_tree{
    private:
        struct Node{ 
            int key; 
            Node* left;
            Node* right; 
            int height;
        };
        Node *root = nullptr;

        int get_alt(Node* no){ 
            if (no == nullptr){
                return 0;
            } 
            return no->height; 
        }

        int top_val(int a, int b){
            if(a > b){
                return a;
            }
            return b; 
        }

        Node* createNO(int dado){ 
            Node* node = new Node; 
            node->key = dado; 
            node->left = nullptr; 
            node->right = nullptr; 
            node->height = 1;
            return node; 
        }

        Node* ROTdir(Node* no){ 
            Node* fl = no->left; 
            Node* flr = fl->right;
            fl->right = no; 
            no->left = flr; 

            no->height = top_val(get_alt(no->left), get_alt(no->right)) + 1; 
            fl->height = top_val(get_alt(fl->left), get_alt(fl->right)) + 1;
            return fl; 
        }

        Node* ROTesq(struct Node* no){ 
            Node* fr = no->right; 
            Node* frl = fr->left; 
            fr->left = no; 
            no->right = frl; 
  
            no->height = top_val(get_alt(no->left), get_alt(no->right)) + 1; 
            fr->height = top_val(get_alt(fr->left), get_alt(fr->right)) + 1; 
            return fr; 
        }

        int getBalance(Node* no){ 
            if (no == nullptr){
                return 0; 
            }
            return get_alt(no->left) - get_alt(no->right); 
        }

        Node* HELPinsert(Node* no, int key){ 
            if (no == nullptr){
                return createNO(key); 
            }
            if(key < no->key){ 
                no->left = HELPinsert(no->left, key); 
            } 
            else if (key > no->key){ 
                no->right = HELPinsert(no->right, key);
            }

            no->height = top_val(get_alt(no->left),get_alt(no->right)) +1; 
            int balance = getBalance(no);
            //rotacoes simples
            if (balance > 1 && key < no->left->key){
                return ROTdir(no);
            }
            if (balance < -1 && key > no->right->key){
                return ROTesq(no); 
            }
            //rotacoes duplas
            if (balance > 1 && key > no->left->key) { 
                no->left = ROTesq(no->left); 
                return ROTdir(no); 
            }
            if (balance < -1 && key < no->right->key) { 
                no->right = ROTdir(no->right); 
                return ROTesq(no); 
            } 
            return no; 
        }

        void HelpPREorder(Node *root){
            if(root != nullptr){
                printf("%d ", root->key); 
                HelpPREorder(root->left); 
                HelpPREorder(root->right); 
            }
        }

        bool Helpfind(int val, Node* no){
            if(no == nullptr){
                return false;
            }
            if(no->key == val){
                return true;
            }if(no->key> val){
                return Helpfind(val, no->left);
            }
            if(no->key < val){
                return Helpfind(val, no->right);
            }
            return false;
        }

    public:
        void insert(int val){
            root = HELPinsert(root, val);
        }

        bool find(int val){
            if(root == nullptr){
                return false;
            }
            return Helpfind(val,root);
        }

        void preOrder(){ 
            if(root != nullptr){ 
                HelpPREorder(root);
            }
            printf("\n");
        } 
};
int main() { 
    avl_tree arv;
    arv.insert(9);
    arv.insert(5);
    arv.insert(10);
    arv.insert(0);
    arv.insert(6);
    arv.insert(11);
    arv.insert(-1);
    arv.insert(1);
    arv.insert(2);
    
    printf("Pre-order of AVL tree is\n");
    arv.preOrder();

    for(int i = 0; i < 10; i++){
        if(arv.find(i)){
            printf("the AVL tree have %d\n", i);
        }else{
            printf("the AVL tree don't have %d\n", i);
        }
    }
    return 0; 
} 
