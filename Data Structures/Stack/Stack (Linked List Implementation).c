#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
struct node{
    int data;
    struct node *next;
};
struct Stack{
    struct node *top;
    int size;
};
//Funcao para criar a Stack
struct Stack* Create_stack(){
    struct Stack *temp;
    temp = (struct Stack *)malloc(sizeof(struct Stack));
    temp->top = NULL;
    temp->size = 0;
    return temp;
}
//Funcao para limpar a minha Stack/esvaziar a Stack. Sem me preocupar
//com a desalocacao de memoria
void Clear_Stack(struct Stack *temp){
    temp->top = NULL;
    temp->size = 0;
}
//Funcao para inserir um elemento na Stack
void Push(struct Stack *temp, int x){
    //Criando o node no qual eu vou inserir o meu inteiro x
    struct node *temp1 = (struct node*)malloc(sizeof(struct node));
    temp1->data = x;
    temp1->next = temp->top;//Fazendo o meu novo node apontar para onde Top apontava anteriormente
    temp->top = temp1;//Agora o top aponta para o meu novo node que foi criado
    //Aumentando o tamanho da minha stack
    temp->size++;
}
//Funcao para retirar um elemento da minha stack
int Pop(struct Stack *temp){
    int element;
    if(temp->top == NULL){//Quer dizer que minha stack ja ta vazia. Entao
    //nao tem oq retirar dela XD.
        printf("A stack ja se encontra vazia!\n");
        return - 1;
    }
    else{
        element = temp->top->data;
        temp->top = temp->top->next;
        temp->size--;
        return element;
    }
}
//Funcao para retornar o tamanho da minha stack
int Length(struct Stack *temp){
    return temp->size;
}
//Funcao para mostrar qual eh  o elemento que se encontra no topo da stack
//Ou seja, qual eh o primeiro elemento presente na minha stack
int Top(struct Stack *temp){
    if(temp->top == NULL){
        printf("Sua stack esta vazia, meu consagrado!\n");
        return -1;
    }
    else{
        return temp->top->data;
    }
}

int main(){
    int tam;
    int Haru;
    struct Stack *Pilha = NULL;
    Pilha = Create_stack();
    Push(Pilha, 40);
    Push(Pilha, -24);
    Push(Pilha, 10);
    Haru = Pop(Pilha);
    printf("O elemento retirado eh %d\n", Haru);
    Haru = Pop(Pilha);
    printf("O elemento retirado eh %d\n", Haru);
    Push(Pilha, 256);
    Push(Pilha, 128);
    Push(Pilha, 32);
    tam = Length(Pilha);
    printf("O tamanho da minha pilha eh %d\n", tam);
    Haru = Pop(Pilha);
    printf("O elemento retirado eh %d\n", Haru);
    Haru = Pop(Pilha);
    printf("O elemento retirado eh %d\n", Haru);
    Haru = Pop(Pilha);
    printf("O elemento retirado eh %d\n", Haru);
    Haru = Pop(Pilha);
    printf("O elemento retirado eh %d\n", Haru);
    Haru = Pop(Pilha);
    printf("O elemento retirado eh %d\n", Haru);
    Haru = Pop(Pilha);
    printf("O elemento retirado eh %d\n", Haru);

    return 0;
}
