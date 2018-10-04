#include<iostream>
 
using namespace std;
 
// A function implementing Shell sort.
void ShellSort(int a[], int n)
{
	int i, j, k, temp;
	// Gap 'i' between index of the element to be compared, initially n/2.
	for(i = n/2; i > 0; i = i/2)
	{
		for(j = i; j < n; j++)
		{
			for(k = j-i; k >= 0; k = k-i)
			{
				// If value at higher index is greater, then break the loop.
				if(a[k+i] >= a[k])
				break;
				// Switch the values otherwise.
				else
				{
					temp = a[k];
					a[k] = a[k+i];
					a[k+i] = temp;
				}
			}
		}
	}
}
int main()
{	
	int n, i;
	cout<<"\nEnter the number of data element to be sorted: ";
	cin>>n;
 
	int arr[n];
	for(i = 0; i < n; i++)
	{
		cout<<"Enter element "<<i+1<<": ";
		cin>>arr[i];
	}
 
	ShellSort(arr, n);
 
	// Printing the sorted data.
	cout<<"\nSorted Data ";
	for (i = 0; i < n; i++)
		cout<<"->"<<arr[i];
 
	return 0;
}