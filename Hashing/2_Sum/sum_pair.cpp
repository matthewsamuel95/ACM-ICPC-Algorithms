
#include <bits/stdc++.h> 
  
using namespace std; 
  
void printPairs(int arr[], int arr_size, int sum) 
{ 
    unordered_set<int> s; 
    for (int i = 0; i < arr_size; i++) 
    { 
        int temp = sum - arr[i]; 
  
        if (temp >= 0 && s.find(temp) != s.end()) 
            cout << "Pair with given sum " << sum << 
                 " is (" << arr[i] << ", " << temp << 
                 ")" << endl; 
  
        s.insert(arr[i]); 
    } 
} 
  
/* Driver program to test above function */
int main() 
{ 
    int A[] = {1, 4, 45, 6, 10, 8}; 
    int n = 16; 
    int arr_size = sizeof(A)/sizeof(A[0]); 
  
    // Function calling 
    printPairs(A, arr_size, n); 
  
    return 0; 
} 
