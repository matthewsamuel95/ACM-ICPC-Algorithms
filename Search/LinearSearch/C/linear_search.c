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
  int arr[] = {4, 10, 8, 25, 13, 89, 45, 12, 78, 11};
  int key = 78;
  int n = sizeof(arr) / sizeof(int);

  int res = search(arr, n, key);
  
  if (res == -1)
    printf("%d is not found!\n", key);
  else
    printf("%d is found at position %d.\n", key, res + 1);
  
  return 0;
}