#include <bits/stdc++.h>

using namespace std;

void SelectionSort(int array[], int tam){
    int i, j;
    int menor, troca;
    for(i = 0; i < tam-1; i++){
        menor = i;
        for(j = i+1; j < tam; j++){
            if(array[j] < array[menor]){
                menor = j;
            }
        }
        if(i != menor){
            troca = array[i];
            array[i] = array[menor];
            array[menor] = troca;
        }
    }
}

int main(){
    int vetor[10] = {5,6,8,3,4,2,1,0,9,7};
    SelectionSort(vetor, 10);
    printf("Your sorted array is:\n");
    for(int i = 0; i < 10; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
    return 0;
}
