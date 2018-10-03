#include<stdio.h>
#define int long long int

#undef int

int main()
{
	#define int long long int

	int n;
	scanf("%lld", &n);

	if((n&(n-1))==0)
	{
		printf("Yes, the number is a power of two\n");
	}

	else
		printf("No, the number is not a power of two\n");

	return 0;
}
