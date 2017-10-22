#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int binarySearch(int arr[], int l, int r, int x)
{
	if (r >= l)
   {
        int mid = l + (r - l)/2;
 
        if (arr[mid] == x)  
        	return mid;
 
        if (arr[mid] > x) 
        	return binarySearch(arr, l, mid-1, x);
 
        return binarySearch(arr, mid+1, r, x);
   }
 
   return -1;
}

int main()
{
	int n;
	int arr[] = {3,1,8,5,10,19,16};
	cout<<"Enter the number you want to search:";
	cin>>n;
	int size = sizeof(arr)/sizeof(arr[0]);
	
	sort(arr, arr + size); 						// array should be sorted for beinary search
	
	int ans = binarySearch(arr, 0, size, n);
	if(ans == -1)
		cout << "Element is not present in the array\n";
	else
		cout << "Element is present at index " << ans << endl;
}