#include <stdio.h>

int m,n;

int max(int a,int b)
{
  return a>b?a:b;
}

void coin_sort(int arr[][n])
{
  for(int i=1;i<m;i++)
    arr[i][0] += arr[i-1][0];
  
  for(int j=1;j<n;j++)
    arr[0][j] += arr[0][j-1];
  
  for(int i=1;i<m;i++)
  {
    for(int j=1;j<n;j++)
    {
      arr[i][j] += max(arr[i-1][j],arr[i][j-1]);
    }
  }
}

int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
  {
    scanf("%d %d",&m,&n);
    int arr[m][n];
    for(int i=0;i<m;i++)
      for(int j=0;j<n;j++)
        scanf("%d",&arr[i][j]);

    coin_sort(arr);

    printf("%d\n",arr[m-1][n-1]);
  }
  return 0;
}
