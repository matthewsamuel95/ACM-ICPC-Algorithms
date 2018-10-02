//BubbleSort code in C
#include<stdio.h>
void bubblesort(int arr[] , int size)
{

	int i,j;
	for(i=0;i<size;i++)
	{
		for(j=0;j<size-i-1;j++)
		{
			if(arr[j] > arr[j+1])
			{
				int temp;
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
  	//Print the sorted array
  	printf("\n");
  	for(i=0;i<size;i++)
  		printf("%d\t", arr[i]);
}
int main()
{
	int size,i;
	printf("Enter the size of array:");
	scanf("%d", &size);
	int arr[size];
	printf("\nEnter elements of the array: \n");
	for(i=0;i<size;i++)
	{
		scanf("%d", &arr[i]);
	}
	bubblesort(arr, size);
}