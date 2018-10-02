#include<stdio.h>
#define int long long int
#undef int

int main()
{
  #define int long long int
  
  int arr[1005], n;
  scanf("%lld", &n);
  
  for(int i=0; i<n; i++)
  {
    scanf("%lld", &arr[i]);
  }
  
  for(int j=0; j<n; j++)
  {
    for(int k=0; k<n-1-j; k++)
    {
      if(arr[k]>arr[k+1])
      {
        arr[k]=arr[k]^arr[k+1];
        arr[k+1]=arr[k]^arr[k+1];
        arr[k]=arr[k]^arr[k+1];
      }
    }
  }
  
  for(int c=0; c<n; c++)
  {
    printf("%lld ", arr[c]);
  }

  return 0;
 }
