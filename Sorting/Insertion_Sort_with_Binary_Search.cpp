#include<bits/stdc++.h>
using namespace std;

/*In Binary Search func, start and end denotes the first and last position where searching is to be done. y is the 
	element to be searched. count will count the no of comparisons.*/
int binary_search(int arr[],int start,int end,int y,int &count)	
{
	if(start>=end)				
		return start;
	int mid=(start+end)/2;
	count++;
	if(arr[mid]>y)
		end=mid;
	else
		start=mid+1;

	int pos=binary_search(arr,start,end,y,count);
		return pos;
}

void insertion_sort(int arr[],int n)
	{
		int count=0;		// count variable will count the number of comparisons in Binary Search.
		for(int i=2;i<=n;i++)
		{
			int y=arr[i];
			int j=i;
			int pos=binary_search(arr,1,j,y,count);	//binary_search func will return the pos where arr[i] is to be added
			for(int j=i-1;j>=pos;j--)			//shiftin the elements one step forward
				arr[j+1]=arr[j];
			arr[pos]=y;
			
		}
		
	}
int main()
{
	int n;
	cin>>n;
	int *arr=new int[n+1];
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	insertion_sort(arr,n);	//function for insertion sort
	for(int i=1;i<=n;i++)
		cout<<arr[i]<<" ";
	delete[] arr;
	return 0;
}