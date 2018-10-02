#include<stdio.h>
#include<math.h>
int main()
{
	int num;
	scanf("%d",&num);
	// taking input
	// Time Complexity : O(sqrt(n))
	int sqrtNo=sqrt(num);
	int fl=1;
	for(int i=2;i<=sqrtNo;i++)
	{
		if(num%i==0)
			fl=0;
	}
	if(fl==1)
		printf("%d is Prime number\n",num);
	else
		printf("%d is not a Prime number\n",num);
	return 0;
}
