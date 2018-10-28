t=int(input())
for i in range(t):
    x,y=map(int,input().split())
    X=3*x-4*y
    if(X<=0):
        print(0)
    else:
        print(X)
