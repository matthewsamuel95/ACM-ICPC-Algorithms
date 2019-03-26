/*
Distinct elements in subarray using Mo’s Algorithm
Approach : 
1. Sort all queries in a way that queries with L values from 0 to \sqrt(n) - 1 are put together, then all queries from \sqrt(n) to 2*\sqrt(n) - 1, and so on. All queries within a block are sorted in increasing order of R values.
2. Initialize an array freq[] of size 10^6 with 0 . freq[] array keep count of frequencies of all the elements in lying in a given range.
3. Process all queries one by one in a way that every query uses number of different elements and frequency array computed in previous query and stores the result in structure.
4. Let ‘curr_Diff_element’ be number of different elements of previous query.
   -Remove extra elements of previous query. For example if previous query is [0, 8] and current query is [3, 9], then remove a[0], a[1] and a[2]
   -Add new elements of current query. In the same example as above, add a[9].
5. Sort the queries in the same order as they were provided earlier and print their stored results
*/
#include <bits/stdc++.h> 
using namespace std; 
  
// Used in frequency array (maximum value of an 
// array element). 
const int MAX = 1000000; 
  
// Variable to represent block size. This is made 
// global so compare() of sort can use it. 
int block; 
  
// Structure to represent a query range and to store 
// index and result of a particular query range 
struct Query { 
    int L, R, index, result; 
}; 
  
// Function used to sort all queries so that all queries 
// of same block are arranged together and within a block, 
// queries are sorted in increasing order of R values. 
bool compare(Query x, Query y) 
{ 
    // Different blocks, sort by block. 
    if (x.L / block != y.L / block) 
        return x.L / block < y.L / block; 
  
    // Same block, sort by R value 
    return x.R < y.R; 
} 
  
// Function used to sort all queries in order of their 
// index value so that results of queries can be printed 
// in same order as of input 
bool compare1(Query x, Query y) 
{ 
    return x.index < y.index; 
} 
  
// calculate distinct elements of all query ranges. 
// m is number of queries n is size of array a[]. 
void queryResults(int a[], int n, Query q[], int m) 
{ 
    // Find block size 
    block = (int)sqrt(n); 
  
    // Sort all queries so that queries of same 
    // blocks are arranged together. 
    sort(q, q + m, compare); 
  
    // Initialize current L, current R and current 
    // different elements 
    int currL = 0, currR = 0; 
    int curr_Diff_elements = 0; 
  
    // Initialize frequency array with 0 
    int freq[MAX] = { 0 }; 
  
    // Traverse through all queries 
    for (int i = 0; i < m; i++) { 
          
        // L and R values of current range 
        int L = q[i].L, R = q[i].R; 
  
        // Remove extra elements of previous range. 
        // For example if previous range is [0, 3] 
        // and current range is [2, 5], then a[0]  
        // and a[1] are subtracted 
        while (currL < L) { 
              
            // element a[currL] is removed 
            freq[a[currL]]--; 
            if (freq[a[currL]] == 0)  
                curr_Diff_elements--; 
              
            currL++; 
        } 
  
        // Add Elements of current Range 
        // Note:- during addition of the left 
        // side elements we have to add currL-1 
        // because currL is already in range 
        while (currL > L) { 
            freq[a[currL - 1]]++; 
  
            // include a element if it occurs first time 
            if (freq[a[currL - 1]] == 1)  
                curr_Diff_elements++; 
              
            currL--; 
        } 
        while (currR <= R) { 
            freq[a[currR]]++; 
  
            // include a element if it occurs first time 
            if (freq[a[currR]] == 1)  
                curr_Diff_elements++; 
              
            currR++; 
        } 
  
        // Remove elements of previous range. For example 
        // when previous range is [0, 10] and current range 
        // is [3, 8], then a[9] and a[10] are subtracted 
        // Note:- Basically for a previous query L to R 
        // currL is L and currR is R+1. So during removal 
        // of currR remove currR-1 because currR was 
        // never included 
        while (currR > R + 1) { 
  
            // element a[currL] is removed 
            freq[a[currR - 1]]--; 
  
            // if ocurrence of a number is reduced 
            // to zero remove it from list of  
            // different elements 
            if (freq[a[currR - 1]] == 0)  
                curr_Diff_elements--; 
              
            currR--; 
        } 
        q[i].result = curr_Diff_elements; 
    } 
} 
  
// print the result of all range queries in 
// initial order of queries 
void printResults(Query q[], int m) 
{ 
    sort(q, q + m, compare1); 
    for (int i = 0; i < m; i++) { 
        cout << "Number of different elements" <<  
               " in range " << q[i].L << " to " 
             << q[i].R << " are " << q[i].result << endl; 
    } 
} 
  
// Driver program 
int main() 
{ 
    int a[] = { 1, 1, 2, 1, 3, 4, 5, 2, 8 }; 
    int n = sizeof(a) / sizeof(a[0]); 
    Query q[] = { { 0, 4, 0, 0 }, { 1, 3, 1, 0 }, 
                  { 2, 4, 2, 0 } }; 
    int m = sizeof(q) / sizeof(q[0]); 
    queryResults(a, n, q, m); 
    printResults(q, m); 
    return 0; 
} 
