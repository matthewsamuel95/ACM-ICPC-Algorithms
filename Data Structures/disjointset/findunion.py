'''
Disjoint set example of find and union 

Question Url : https://www.hackerrank.com/challenges/merging-communities/problem

'''


[N,Q]=[int(x) for x in input().split()]
ds = [[i,1] for i in range(0,N+1)]
for q in range(Q):
    inp = input().split()
    if inp[0] == 'M':
        ind1 = int(inp[1])
        ind2 = int(inp[2])
        ind3 = ind2
        while ds[ind1][0] != ind1:
            ind1 = ds[ind1][0]
        while ds[ind2][0] != ind2:
            ind2 = ds[ind2][0]
        if ind1 == ind2:
            continue
        while ind3 != ind2:
            ind4 = ds[ind3][0]
            ds[ind3][0] = ind1
            ind3 = ind4
        ds[ind2][0] = ind1
        ds[ind1][1] += ds[ind2][1]
    else:
        ind1 = int(inp[1])
        while ds[ind1][0] != ind1:
            ind1 = ds[ind1][0]
        print(ds[ind1][1])