#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
	long long int x, n;
	scanf("%lld %lld", &x, &n);
	
	long long int exp(long long int x, long long int n)
	{

		if(n==0)
			return 1;

		if(n%2==0)
		{
			long long int temp= exp(x, n/2);
			return (temp*temp);
		}

		else
		{
			long long int temp= exp(x, (n-1)/2);
			return (x*temp*temp);
		}
	}

  long long int ans= exp(x,n);
	printf("%lld", ans);

	return 0;
}
