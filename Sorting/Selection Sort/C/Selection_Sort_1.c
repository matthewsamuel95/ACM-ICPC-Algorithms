#include<stdio.h>
#define int long long int

#undef int

int main()
{
	#define int long long int

	int arr[1005], n;
	int min_idx, temp;

	scanf("%lld", &n);
	
	for(int c=0; c<n; c++)
  	{
    	scanf("%lld", &arr[c]);
  	}

	for(int i=0;i<n; i++)
	{
		min_idx = i;	
		for(int j=i;j<n;j++)
		{
			if(arr[j]< arr[min_idx])
			{
				min_idx = j;
			}
		}

		temp = arr[min_idx];
		arr[min_idx] = arr[i];
		arr[i]= temp;

		printf("%lld ", arr[i]); 
	}


}
 
