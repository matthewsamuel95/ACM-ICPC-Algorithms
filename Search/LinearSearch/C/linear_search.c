#include <stdio.h>

int search(int arr[], int n, int key)
{
  int i;
  for (i = 0; i < n; i++)
  {
    if (arr[i] == key)
      break;
  }

  return (i == n) ? -1 : i;
}

int main()
{
  int size;
  printf("Enter the size of the array\n");
  scanf("%d\n",&size);
  int arr[size],key;
  int n = sizeof(arr) / sizeof(int);
  printf("Enter the elememts of the array\n");
 for(int i=0;i<n;i++){
    scanf("%d\n",arr[i]);
  }
  printf("Enter the element you want to search");
  scanf("%d\n",&key);
  int res = search(arr, n, key);
  
  if (res == -1)
    printf("%d is not found!\n", key);
  else
    printf("%d is found at position %d.\n", key, res + 1);
  
  return 0;
}
