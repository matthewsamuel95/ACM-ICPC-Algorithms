#include<stdio.h>
#include<math.h>

int sqroot(int x)
{
  if(x==0)
    return 0;

  int counter=1;
  
  while(pow(counter,2)<=x)
  {
    counter++;
  }

  counter--;

  return counter;
}

int main()
{
  int n;

  printf("Enter Number\n");
  scanf("%d", &n);
  
  printf("The square root of the number is: %d\n", sqroot(n));
  
  return 0;
}
