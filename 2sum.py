T = int(input())
for _ in range(T):
    target = int(input())
    arr =[int(x) for x in input().split()]
    for i in range(0,len(arr)-1):
        for j in range(0,len(arr)-1):
            if arr[i]+arr[j]=target:
                if i==j:
                    print("No such integers exist in the array")
                else:
                    print(i,j)
            else:
                print("No such integers exist in the array")
