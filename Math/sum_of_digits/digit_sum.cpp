//C++ program to compute sum of digits in numbers from 1 to n
#include<bits/stdc++.h>
using namespace std;
 
// Function to computer sum of digits in numbers from 1 to n
// Comments use example of 328 to explain the code
int sumOfDigitsFrom1ToN(int n)
{
    // base case: if n<10 return sum of
    // first n natural numbers
    if (n<10)
      return n*(n+1)/2;
 
    // d = number of digits minus one in n. For 328, d is 2
    int d = log10(n);
 
    // computing sum of digits from 1 to 10^d-1,
    // d=1 a[0]=0;
    // d=2 a[1]=sum of digit from 1 to 9 = 45
    // d=3 a[2]=sum of digit from 1 to 99 = a[1]*10 + 45*10^1 = 900
    // d=4 a[3]=sum of digit from 1 to 999 = a[2]*10 + 45*10^2 = 13500
    int *a = new int[d+1];
    a[0] = 0, a[1] = 45;
    for (int i=2; i<=d; i++)
        a[i] = a[i-1]*10 + 45*ceil(pow(10,i-1));
 
    // computing 10^d
    int p = ceil(pow(10, d));
 
    // Most significant digit (msd) of n,
    // For 328, msd is 3 which can be obtained using 328/100
    int msd = n/p;
 
    // EXPLANATION FOR FIRST and SECOND TERMS IN BELOW LINE OF CODE
    // First two terms compute sum of digits from 1 to 299
    // (sum of digits in range 1-99 stored in a[d]) +
    // (sum of digits in range 100-199, can be calculated as 1*100 + a[d]
    // (sum of digits in range 200-299, can be calculated as 2*100 + a[d]
    //  The above sum can be written as 3*a[d] + (1+2)*100
 
    // EXPLANATION FOR THIRD AND FOURTH TERMS IN BELOW LINE OF CODE
    // The last two terms compute sum of digits in number from 300 to 328
    // The third term adds 3*29 to sum as digit 3 occurs in all numbers 
    //                from 300 to 328
    // The fourth term recursively calls for 28
    return msd*a[d] + (msd*(msd-1)/2)*p +  
           msd*(1+n%p) + sumOfDigitsFrom1ToN(n%p);
}
 
// Driver Program
int main()
{
    int n = 328;
    cout << "Sum of digits in numbers from 1 to " << n << " is "
         << sumOfDigitsFrom1ToN(n);
    return 0;
}
