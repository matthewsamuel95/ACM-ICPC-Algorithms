#include<stdio.h>
#include<conio.h>
struct sum{
	int index1;
	int index2;
};
struct sum gettarget(int arr[] , int target, int size){
int i,j,flag=0;
struct sum str;
for(i=0;i<size-1;i++)
	{
		for(j=i+1 ; j<size;j++){
			if(arr[i] + arr[j] ==target)
			{
				str.index1 = i;
				str.index2= j;
				flag=1;
				break;
			}

		}
		if(flag==1)
		break;
	}
	return str;
	
}
int main(){
	int size,target;
	printf("Enter size of array:");
	scanf("%d", &size);
	printf("\nEnter target:");
	scanf("%d", &target);
	int arr[size],i;
	printf("\nEnter elements of array:");
	for( i=0;i<size;i++)
	{
		scanf("%d", &arr[i]);
	}
	struct sum result;
	result = gettarget(arr, target, size);
	printf("Index 1 = %d and Index 2 = %d", result.index1 , result.index2);
	getch();
	return 0;

	
}