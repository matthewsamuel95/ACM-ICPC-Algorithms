#include<stdio.h>

void swap(int *x, int *y) { 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
} 

int main(){  
  int n, i, j;
  bool swapped;
  scanf("%d", &n);
  int *a = (int *)malloc(n * sizeof(int)); 
  for(int i=0; i<n; i++)
    scanf("%d", &a[i]);
   
  for (i = 0; i < n - 1; i++) { 
    swapped = false; 
    for (j = 0; j < n - i - 1; j++) { 
      if (a[j] > a[j+1]) { 
        swap(&a[j], &a[j+1]); 
        swapped = true; 
      } 
    } 
    if (swapped == false) 
      break; 
   } 
  for(i = 0; c < n; c++)
    printf("%d ", a[i]);
  free(a);
  return 0;
}
