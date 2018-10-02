#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	// question : calculate a^(1/n)
	// complexity : O(nlog(n))

	long double a,n;
	scanf("%Lf%Lf",&a,&n);
	long double low=1,high=a;
	long double precision = 0.00000001;
	if(a>=0 && a<=1)
	{
		low=a;
		high=1;
	}
	if(a==0)
	{
		// extra case
		printf("0.000000\n");
		return 0;
	}
	while(fabs(high-low)>=precision)
	{
		long double guess=(low+high)/2;
		long double cal=1;
		for(int i=1;i<=n;i++)
			cal=cal*guess;
		// cal = guess^n
		if(fabs(cal-a)<=precision)
		{
			printf("%6Lf\n",guess);
			break;
		}
		else if(cal>a)
			high=guess;
		else
			low=guess;
	}
	return 0;
}
