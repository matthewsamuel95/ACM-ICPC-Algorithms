#include<iostream> 
using namespace std; 
  
// A dynamic programming based function to find nth 
// Catalan number 
unsigned long int catalanDP(unsigned int n) 
{ 
    // Table to store results of subproblems 
    unsigned long int catalan[n+1]; 
  
    // Initialize first two values in table 
    catalan[0] = catalan[1] = 1; 
  
    // Fill entries in catalan[] using recursive formula 
    for (int i=2; i<=n; i++) 
    { 
        catalan[i] = 0; 
        for (int j=0; j<i; j++) 
            catalan[i] += catalan[j] * catalan[i-j-1]; 
    } 
  
    // Return last entry 
    return catalan[n]; 
} 
  
// Driver program to test above function 
int main() 
{ 
    for (int i = 0; i < 10; i++) 
        cout << catalanDP(i) << " "; 
    return 0; 
} 
