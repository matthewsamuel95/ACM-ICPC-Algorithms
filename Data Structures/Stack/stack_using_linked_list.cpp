#include <bits/stdc++.h>
using namespace std;
#define stack_empty -1
class pilha{
    private:
        struct node{
            int dado;
            node *prox;
        };
        node *head = nullptr;

    public:
        void push(int val){
            node* elemento;
            elemento = new node;
            elemento->dado = val;
            if(head == nullptr){
                //pilha vazia
                elemento->prox = nullptr;
                head = elemento;
            }else{
                //pilha com elemento
                elemento->prox = head;
                head = elemento;
            }
        }

        bool isempty(){
            if(head == nullptr){
                return true;
            }
            return false;
        }

        int pop(){
            int val = stack_empty;
            if(!isempty()){
                val = head->dado;
                node *next, *at;
                next = head->prox;
                at = head;
                head = next;
                delete at;
            }
            return val;
        }

        int show_top(){
            int val = stack_empty;
            if(!isempty()){
                val = head->dado;
            }
            return val;
        }

        int size(){
            int cont = 0;
            node* aux;
            aux = head;
            while(aux->prox !=nullptr){
                cont++;
                aux = aux->prox;
            }
            cont++;
            return cont;
        }
};

int main(){
    pilha st;
    int val;

    for(int i = 0; i < 10; i++){
        st.push((i+1));
    }
    for(int i = 0; i <12; i++){
        val = st.pop();
        if(val != stack_empty){
            cout << val << endl;
        }else{
            cout << "stack is empty!" << endl;
        }
    }

    for(int i = 0; i < 5; i++){
        st.push((i+1));
    }

    cout << "stack have " << st.size() << " elements" << endl;
    cout << st.show_top() << " is top element of stack" << endl;
    return 0;
}
