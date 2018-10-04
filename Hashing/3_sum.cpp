#include<bits/stdc++.h> 
using namespace std; 
  
// function to print triplets with 0 sum 
void findTriplets(int arr[], int n) 
{ 
    bool found = false; 
  
    // sort array elements 
    sort(arr, arr+n); 
  
    for (int i=0; i<n-1; i++) 
    { 
        // initialize left and right 
        int l = i + 1; 
        int r = n - 1; 
        int x = arr[i]; 
        while (l < r) 
        { 
            if (x + arr[l] + arr[r] == 0) 
            { 
                // print elements if it's sum is zero 
                printf("%d %d %d\n", x, arr[l], arr[r]); 
                l++; 
                r--; 
                found = true; 
            } 
  
            // If sum of three elements is less 
            // than zero then increment in left 
            else if (x + arr[l] + arr[r] < 0) 
                l++; 
  
            // if sum is greater than zero than 
            // decrement in right side 
            else
                r--; 
        } 
    } 
  
    if (found == false) 
        cout << " No Triplet Found" << endl; 
} 
  
// Driven source 
int main() 
{ 
    int arr[] = {0, -1, 2, -3, 1}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    findTriplets(arr, n); 
    return 0; 
} 
