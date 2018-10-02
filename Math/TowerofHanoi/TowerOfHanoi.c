#include<stdio.h>
void move(int n,char source,char dest,char temp)
{
      if(n==1)
	printf("\nMove from %c to %c",source,dest);
      else
      {
	move(n-1,source,dest,temp);
	move(1,source,temp,dest);
	move(n-1,temp,source,dest);
      }
}

int main()
{
      int n;
      printf("\nEnter the no. of disks:");
      scanf("%d",&n);
      move(n,'A','B','C');
      return 0;
}