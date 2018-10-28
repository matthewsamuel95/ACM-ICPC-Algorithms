#include <bits/stdc++.h>

using namespace std;

void bubbleSort(int *vet, int length) {
	int i, j, temp;
	for (i = 0; i < length - 1; i++){
       for (j = (i+1); j < length; j++){
            if (vet[j] < vet[i]){
                temp = vet[i];
                vet[i] = vet[j];
                vet[j] = temp;
            }
       }
   }
}

int main(){
  int size, i;
  int *array;
  printf("Insert the size of your array:\n");
  scanf("%d", &size);
  array = (int *)malloc(size*sizeof(int));
  printf("Insert the elements of your array:\n");
  for(i = 0; i < size; i++){
      scanf("%d", &array[i]);
  }
  bubblesort(array,size);
  printf("Your sorted array is:\n");
  for(i = 0; i < size; i++){
      printf("%d ", array[i]);
  }
  return 0;
}
