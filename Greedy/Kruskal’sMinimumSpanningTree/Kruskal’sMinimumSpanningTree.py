import math, random
import numpy as np

def find(b, c):
	for a in visited:
		if (b in a) and (c in a):
			return False
		else:
			return True

n = random.randint(5,7)
print('Number of vertices:', n)
max_int = math.inf
num, m, l = 0, 0, 0

e = [[0 for x in range(n)] for y in range(n)] 
c = [[max_int for x in range(n)] for y in range(n)]
t = [[0 for x in range(2)] for y in range(n-1)] 4

print (np.matrix(t)) 

for i in range(n):
	for j in range(n):
		if(i < j):
			e[i][j]=1
			c[i][j]=float(random.randint(10,50))
		else:
			e[i][j]=e[j][i]
			c[i][j]=c[j][i]

print('Edge Adjacency Matrix: \n', np.matrix(e))
print('Cost Adjacency Matrix: \n',np.matrix(c))
mincost = 0
visited = [set() for _ in range(n)]
new_set = set()
for i in visited:
	i.add(num)
	num += 1
print ('Disjoint Sets: ', visited)
values = np.array(c)
count = 0
while(count < n-1):
	index = np.argmin(values)
	u, v = index//n, index%n
	if find(u, v):
		t[count][0], t[count][1] = u, v
		values[u][v], values[v][u] = max_int, max_int
		for a in visited:
			if u in a:
				k = a	
			if v in a:
				l = a
		visited.append(k.union(l))
		visited.remove(k)
		visited.remove(l)		
		mincost += c[u][v]
		count += 1
if (count != n-1):
	print ('No MST was formed.')

print ('MST: \n', np.matrix(t))
print ('Visited:', visited)
print ('Cost:', mincost)

		
