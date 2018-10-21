import numpy as np
import random, math

def algoAllPairs(cost, A, n):
	for i in range(n):
		for j in range(n):
			A[i][j] = cost[i][j]

	for k in range(n):
		for i in range(n):
			for j in range(n):
				A[i][j] = min(A[i][k] + A[k][j], A[i][j])

	return np.matrix(A)

n = random.randint(5, 7)
e = [[0 for x in range(n)] for y in range(n)] 
c = [[0 for x in range(n)] for y in range(n)] 

for i in range(n):
	for j in range(n):
		if (i!= j):
			e[i][j] = 1
			c[i][j] = random.randint(10,40)

print ('Number of vertices: ', n)
print ('Edge Adjacency Matrix: \n',np.matrix(e))
print ('Cost Adjacency Matrix: \n',np.matrix(c))
A = [[0 for x in range(n)] for y in range(n)]

print ('Minimum Cost Adjacency Matrix: \n', algoAllPairs(c, A, n))
