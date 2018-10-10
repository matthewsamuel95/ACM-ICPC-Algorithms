//swapping variable using temporary variable

#include<stdio.h>

int main()
{
    int a,b,temp ;
    printf("Enter value for a and b variable") ;
    scanf("%d",&a) ;   //user input for a variable 
    scanf("%d",&b) ;   //user input for b variable
    temp=a ;           // {
    a=b ;              //   swapping value of a and b
    b=temp ;           //            } 
    printf("a=%d b=%d",a,b) ;
}
