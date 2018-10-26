#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 10000
struct List{
    int *array;
    int maxsize;
    int listsize;
    int curr;
};
struct List* Create_list(int tam){
    struct List *temp;
    temp = (struct List*)malloc(sizeof(struct List));
    temp->maxsize = tam;
    temp->listsize = 0;
    temp->curr = 0;
    temp->array = (int *)malloc(sizeof(int)*tam);
    return temp;
}
void Clear(struct List *temp){
    temp->listsize = 0;
    temp->curr = 0;
}
//A funcao vai retornar 1 se a insercao der certo.
//A funcao vai retornar 0 se a insercao der errado.
int Insert(struct List* temp, int x){
    //Na hora de printar tem que ficar ligado pra saber onde o cursor/curr se encontra na lista
    if(temp->listsize > temp->maxsize){
        return 0;
    }
    int i = temp->listsize;
    while(i > temp->curr){
        temp->array[i] = temp->array[i-1];
        i--;
    }
    temp->array[temp->curr] = x;
    temp->listsize++;
    return 1;
}
void Print(struct List *temp){
    int i = 0;
    int final = (temp->listsize)-1;
    for(i = 0; i <= final; i++){
        printf("%d\n", temp->array[i]);
    }
}
int Append(struct List* temp, int x){
    if(temp->listsize >= temp->maxsize){
        return 0;
    }
    temp->curr = temp->listsize;
    temp->array[temp->curr] = x;
    temp->listsize = temp->listsize + 1;
    return 1;
}
void MoveToStart(struct List* temp){
    temp->curr = 0;
}
void MoveToEnd(struct List* temp){
    temp->curr = temp->listsize;
}
int Prev(struct List* temp){
    if(temp->curr == 0){
        return 0;
    }
    temp->curr--;
    return 1;
}
int Next(struct List* temp){
    if(temp->curr >= temp->listsize){
        return 0;
    }
    temp->curr++;
    return 1;
}
int Length(struct List *temp){
    return temp->listsize;
}
int CurrPos(struct List* temp){
    return temp->curr;
}
int MoveToPos(struct List *temp, int pos){
    if(pos < 0 || pos > temp->listsize){
        return 0;
    }
    temp->curr = pos;
    return 1;
}
int GetValue(struct List *temp){
    if(temp->curr < 0 || temp->curr >= temp->listsize){
        return 0;
    }
    return temp->array[temp->curr];
}
int Delete(struct List *temp){
    int i;
    if(temp->curr < 0 || temp->curr >= temp->listsize){
        return 0;
    }
    i = temp->curr;
    while(i < temp->listsize - 1){
        temp->array[i] = temp->array[i+1];
        i++;
    }
    temp->listsize--;
}

int main(){
    struct List *head = NULL;
    int aux;
    head = Create_list(10);
    aux = Insert(head,10);
    aux = Insert(head,-34);
    aux = Insert(head,0);
    aux = Insert(head,23);
    aux = Append(head, 69);
    aux = Append(head, -43);
    MoveToPos(head, 2);
    printf("A lista antes da remocao eh:\n");
    Print(head);
    Delete(head);
    printf("A lista depois da remocao eh:\n");
    Print(head);
    
    return 0;
}
