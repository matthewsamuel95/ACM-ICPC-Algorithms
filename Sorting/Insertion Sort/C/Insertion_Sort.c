#include<stdio.h>

int main(void)
{
  	int n;
	int arr[1005];
	scanf("%d", &n);
  
  	for(int c=0; c<n; c++)
  	{
    	scanf("%d", &arr[c]);
  	}
 
	int min_idx, temp;

	for(int i = 0; i<n; i++)
	{
    	printf("%d ", arr[i]);
 	}
  
	printf("\n");

	for(int i=0; i<n; i++)
	{
		min_idx = i;	
		for(int j=i; j<n; j++)
    	{
			if(arr[j] < arr[min_idx])
      		{
				min_idx = j;
	   		}
	  	}

    	temp = arr[min_idx];
		arr[min_idx] = arr[i];
		arr[i]= temp;
	}

	for (int i = 0; i <n; ++i)
	{
		printf("%d ", arr[i]); 
	}


}
