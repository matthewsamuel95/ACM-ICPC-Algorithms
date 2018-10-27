#include <stdio.h> 
int main() 
{ 
  int x , y; 
  scanf("%d %d",&x,&y);
  // Code to swap 'x' and 'y' 
  x = x * y;  // x now becomes 50 
  y = x / y;  // y becomes 10 
  x = x / y;  // x becomes 5 
  
  printf("After Swapping: x = %d, y = %d", x, y); 
  
  return 0; 
} 