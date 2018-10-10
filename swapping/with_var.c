//swapping variable using temporary variable

#include<stdio.h>

int main()
{
    int a,b,temp ;
    printf("Enter value for a and b variable\n") ;
    scanf("%d",&a) ;   //user input for a variable 
    scanf("%d",&b) ;   //user input for b variable
    temp=a ;           // {
    a=b ;              //   swapping value of a and b
    b=temp ;           //            } 
  //after swapping
    printf(" after swapping value of  a=%d   &   b=%d",a,b) ;
}
