#include<stdio.h>
int main()
{
    // Question : Calculate gcd of two numbers
    int a,b;
    // two numbers input
    scanf("%d%d",&a,&b);
    while(b!=0)
    {
	int temp=b;
	b=a%b;
	a=temp;
    }
    // Time Complexity : O(log(a)+log(b))
    // Analysis: 
    // iter 1 -> b, a%b
    // iter 2 -> a%b, b%(a%b)
   
    // case 1: 2a<=b
    // case 2: 2b<=a
    // case 3: 2a>b && a<b -> b = b-a
    // case 4: 2b>a && b<a -> a = a-b
    // case 5: a==b	
    printf("%d\n",a);
    return 0;
}
