#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
 
int busca(int* vetor,int x,int inicio,int fim){
    if(fim>=inicio){
        int meio=(inicio+fim)/2;
        if (vetor[meio]==x){
            return meio;
        }
        else if(vetor[meio]>x){
            busca(vetor,x,inicio,meio-1);
        }
        else{
            busca(vetor,x,meio+1,fim);
        }
    }
    else{
        return -1;
    }
 
}
 
 
int main() {
    int tam,i,pesq,j,x;
    int *vetor;
    int meio;
    scanf("%i %i",&tam,&pesq);
    vetor=(int*) malloc(tam*sizeof(int));
    for(i=0;i<tam;i++){
        scanf("%i",&vetor[i]);
    }
    for(i=0;i<pesq;i++){
        scanf("%i",&x);
        int pqp = busca(vetor,x,0,tam-1);
        if(pqp!=-1){
            dnv:;
            if(vetor[pqp]==vetor[pqp-1]){
                pqp--;
                goto dnv;
            }
            else{
                goto next;
            }
        }
        next:;
        printf("%i\n",pqp);
    }
 
    return 0;
}
