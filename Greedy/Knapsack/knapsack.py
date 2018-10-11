'''
Code problem: fractional knapsack

The first line of the input contains the number 1≤n≤103 of items and the weight 0≤W≤2⋅106 of a knapsack. The next n lines define the cost 0≤ci≤2⋅106 and the weight 0≤wi≤2⋅106 of i-th item (n, W, ci's, wi's are integers). Output the maximal possible cost of the knapsach with at least three digits of precision.

Sample Input:
3 50
60 20
100 50
120 30
Sample Output:
180.000

Memory Limit: 256 MB
Time Limit: 5 seconds
'''
n, weight = map(int, input().split())

costWeight = []
for i in range(n):
    c, w = map(int, input().split())
    costWeight.append((c, w, c * 1.0 / w))

sortedWeight = sorted(costWeight, key=lambda x: x[2], reverse=True)
totalCost = 0
for tup in sortedWeight:
    if weight >= tup[1]:
        weight -= tup[1]
        totalCost += tup[0]
    else:
        totalCost += weight * 1.0 / tup[1] * tup[0]
        break

print(format(totalCost, '.3f'))
