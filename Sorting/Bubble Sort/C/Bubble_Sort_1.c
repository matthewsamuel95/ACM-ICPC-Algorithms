#include <stdio.h>

void swap (int array[], int j){
  int aux = 0;
  aux = array[j]; 
  array[j] = array[j+1]; 
  array[j+1] = aux;
}

void bubbleSort(int array[], int size, int order){
  if(order == 1){
    for(int i=0; i < size-1; i++){
      int flag = 0;

      for(int j=0; j<size-1-i; j++){
        if(array[j] > array[j+1]){
          swap(array, j);
          flag = 1;
        }
      }
      if(flag == 0){
        break;
      }
    }
  }

  else if(order == 2){
    for(int i=0; i < size-1; i++){
      int flag = 0;

      for(int j=0; j<size-1-i; j++){
        if(array[j] < array[j+1]){
          swap(array, j);
          flag = 1;
        }
      }
      if(flag == 0){
        break;
      }
    }
  }
}
int main() {
  int size;
  int order;

  printf("Enter the size of the array:\n");
	scanf("%i", &size);

	int array[size];

	printf("Enter the elements of the array:\n");
	for(int i = 0; i < size; i++){
	  scanf("%i", &array[i]);
  }

  printf("What type of ordering do you want: \n 1 - Ascending \n 2 - Descending\n");
  scanf("%i", &order);

	bubbleSort(array, size, order);

	printf("The sorted array is:\n");
	for (int i = 0; i < size; i++){
    printf("%i ", array[i]);
  }
  return 0;
}
