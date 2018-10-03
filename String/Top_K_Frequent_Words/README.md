# Top K Frequent Words

This cpp code is a solution for the issue [#277](https://github.com/matthewsamuel95/ACM-ICPC-Algorithms/issues/277).

## PROBLEM STATEMENT

Given an array of terms `s1 s2 s3 ... sn`, length of the array `n` and a total number of output terms `k`, write the top `k` frequent terms.

## POINT OF THIS ALGORITHM

1. Using `unordered_map` to store input terms. This STL Container has constant time access for adding and accessing.
2. Using lambda expresions to sort terms. 
