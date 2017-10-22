// C++ program for implementation of selection sort
#include <iostream>
using namespace std;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
 
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
 
        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}
 
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        //printf("%d ", arr[i]);
        cout<<arr[i]<<" ";
    cout<<endl;
}
 
// Driver program to test above functions
int main()
{
    int arr[50],n;
    cout<<"Enter the size of array: ";
    cin>>n;

    cout<<"Enter the array elements: "; 
    
    for(int i=0;i<n;++i)
        cin>>arr[i];

    selectionSort(arr, n);
    cout<<"Sorted array: "<<endl;
    printArray(arr, n);
    return 0;
}
