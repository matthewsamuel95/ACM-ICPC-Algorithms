/*
Given a set of positive integers, find if it can be divided into two subsets with equal sum.
Partition problem is special case of Subset Sum Problem which itself is a special case of the Knapsack Problem.
The idea is to calculate sum of all elements in the set. 
*/

#include <iostream>
#include <string>
using namespace std;

// Return true if there exists a subset of arr[] with given sum
bool subsetSum(int arr[], int n, int sum)
{
    // return true if sum becomes 0 (subset found)
    if (sum == 0)
        return true;

    // base case: no items left or sum becomes negative
    if (n < 0 || sum < 0)
        return false;

    // Case 1. include current item in the subset (arr[n]) and recurse
    // for remaining items (n - 1) with remaining sum (sum - arr[n])
    bool include = subsetSum(arr, n - 1, sum - arr[n]);

    // Case 2. exclude current item n from subset and recurse for
    // remaining items (n - 1)
    bool exclude = subsetSum(arr, n - 1, sum);

    // return true if we get subset by including or excluding current item
    return include || exclude;
}

// Return true if given array arr[0..n-1] can be divided into two
// subsets with equal sum
bool partition(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
       sum += arr[i];

    // return true if sum is even and array can can be divided into
    // two subsets with equal sum
    return !(sum & 1) && subsetSum(arr, n - 1, sum/2);
}

// main function to solve partition problem
int main()
{
    // Input: set of items
    int arr[] = { 7, 3, 1, 5, 4, 8 };

    // number of items
    int n = sizeof(arr) / sizeof(arr[0]);

    if (partition(arr, n))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}