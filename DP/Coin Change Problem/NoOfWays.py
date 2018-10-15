# Recursive Python3 program for
# coin change problem.
'''
Algorithm : Coin Change Problem (No of Ways)
Type : DP
Problem
You have m types of coins available in infinite quantities where the value of
each coin is given in the array C = [c0, c1....c m-1] .
Can you determine the number of ways of making change for n units
using the given types of coins? The order of coins doesn’t matter.
Example
Input
4 3
1 2 3
Output
4
Explanation
There are 4 ways to make n=4 with C=1,2,3
{1,1,1,1}
{1,1,2}
{2,2}
{1,3}

'''


def count(S, m, n):
    # If n is 0 then there is 1
    # solution (do not include any coin)
    if (n == 0):
        return 1

    # If n is less than 0 then no
    # solution exists
    if (n < 0):
        return 0

    # If there are no coins and n
    # is greater than 0, then no
    # solution exist
    if (m <= 0 and n >= 1):
        return 0

    # count is sum of solutions (i)
    # including S[m-1] (ii) excluding S[m-1]
    return count(S, m - 1, n) + count(S, m, n - S[m - 1])


# Driver program to test above function
# n , m = int(input()).split()
n, m = [int(x) for x in input().split()]

arr = [int(x) for x in input().split()]
# m = len(arr)
print(count(arr, m, n))

# This code is contributed by Smitha Dinesh Semwal
