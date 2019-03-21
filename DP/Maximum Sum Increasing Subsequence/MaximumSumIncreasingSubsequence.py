#!/bin/python3
import sys
from copy import copy

fstd = "test2"
sys.stdin = open('%s.txt' % fstd, 'r')
input = sys.stdin.readline

# DP based Python
# implementation of Maximum Sum
# Increasing Subsequence (MSIS)
# problem


# constructMaxSumIS() returns the tupple:
# ( max sum of increasing subsequence, found subsequence )
def constructMaxSumIS(arr):
    N = len(arr)

    # L[i] stores the Maximum Sum Increasing Subsequence that ends with arr[i]
    L = [[] for _ in range(N)]
    # L[0] is equal to arr[0]
    L[0].append(arr[0])

    # msis[i] stores the Maximum Sum of Increasing Subsequence that
    # ends with arr[i]
    msis = [0] * N
    # Initialize msis values
    msis[0] = arr[0]

    # Compute maximum sum
    # values in bottom up manner
    for i in range(1, N):
        for j in range(i):
            if (arr[i] > arr[j]) and (msis[i] < msis[j]):
                msis[i] = msis[j]
                L[i] = copy(L[j])
        L[i].append(arr[i])
        msis[i] += arr[i]

    # Find max
    maxIndex = max(range(N), key=lambda i: msis[i])
    return (msis[maxIndex], L[maxIndex])


if __name__ == "__main__":
    print("Input sequence:")
    A = []
    while (True):
        line = input().strip()
        try:
            num = int(line)
        except ValueError:
            break
        A.append(num)
    print(A)
    res = constructMaxSumIS(A)
    print("Max sum is {}".format(res[0]))
    print("Found sequence is: {} ".format(res[1]))
