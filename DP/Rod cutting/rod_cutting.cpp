#include<bits/stdc++.h> 
  
using namespace std;


/* Returns the best obtainable price for a rod of length n and 
   price[] as prices of different pieces */
int cutRod(int price[], int n) 
{ 
   int val[n+1]; 
   val[0] = 0; 
   int i, j; 
  
   // Build the table val[] in bottom up manner and return the last entry 
   // from the table 
   for (i = 1; i<=n; i++) 
   { 
       int max_val = INT_MIN; 
       for (j = 0; j < i; j++) 
         max_val = max(max_val, price[j] + val[i-j-1]); 
       val[i] = max_val; 
   } 
  
   return val[n]; 
} 
  
int main() 
{ 
    int n; //size of the rod
    cin>>n;
    int price[n];//different prices of different sizes of the rod
    for(int i = 0;i<n;i++){
      cin>>price[i];
    }
    cout<<"Maximum price value is "<<cutRod(price , n)<<endl; 
    getchar(); 
    return 0; 
} 
