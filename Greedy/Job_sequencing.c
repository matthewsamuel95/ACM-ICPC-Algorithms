#include<stdio.h>
#include<conio.h>
void jobsequence(int d[6],int j[6],int n);
int j[10],d[10],p[10],profit;
void main()
{
  int n,i;
  clrscr();
  printf("\n Enter the no. of jobs: ");
  scanf("%d",&n);
  printf("\n Enter the profit matrix in descending order: ");
  for(i=1;i<=n;i++)
  scanf("%d",&p[i]);
  printf("\n Enter the deadline matrix: ");
  for(i=1;i<=n;i++)
  scanf("%d",&d[i]);
  jobsequence(d,j,n);
  getch();
}
void jobsequence(int d[6],int j[6],int n)
{
  int q,i,r,k,a,count=0;
  d[0]=0;
  j[0]=0;
  profit=p[1];
  j[1]=1;
  k=1;
  for(i=2;i<=n;i++)
  {
    r=k;
    while((d[j[r]]>d[i]) &&(d[j[r]]!=r))
    r=r--;
    if((d[j[r]]<=d[i]) && (d[i]>r))
    {
      for(q=k;q<=r+1;q++)
      {
        j[q+1]=j[q];
      }
      j[r+1]=i;
      count++;
      profit+=p[i];
      k=k++;
    }
  }
  printf("\n The optimal job sequence is: ");
  for(a=1;a<=count+1;a++)
    printf(" %d",j[a]);
  printf("\n The profit for optimal sequence is %d",profit);
}