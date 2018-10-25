# 0/1 Knapsack Problem (using BRANCH & BOUND)

## Problem:

1. Given two integer arrays val[0..n-1] and wt[0..n-1] that represent values and weights associated with n items respectively. 
2. Find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to Knapsack capacity W. 
3. We have ‘n’ items with value v1 , v2 . . . vn and weight of the corresponding items is w1 , w2 . . . Wn . Max capacity is W . 
4. We can either choose or not choose an item. We have x1 , x2 . . . xn. Here xi = { 1 , 0 }. xi = 1 , item chosen xi = 0 , item not chosen.

## Why Branch And Bound?
- Greedy approach works only for fractional knapsack problem. 
- If weights are not integers , dynamic programming will not work.
- There are 2n possible combinations of item , complexity for brute force goes exponentially.

## Algorithm:
1. Sort all items in decreasing order of ratio of value per unit weight so that an upper bound can be computed using Greedy Approach.
2. Initialize maximum profit, maxProfit = 0
3. Create an empty queue, Q.
4. Create a dummy node of decision tree and enqueue it to Q. 
   Profit and weight of dummy node are 0.
5. Do following while Q is not empty.
	- Extract an item from Q. Let the extracted item be u.
	- Compute profit of next level node. If the profit is more than maxProfit, then update maxProfit.
	- Compute bound of next level node. If bound is more than maxProfit, then add next level node to Q.
	- Consider the case when next level node is not considered as part of solution and add a node to queue with level as next, 
	   but weight and profit without considering next level nodes.
