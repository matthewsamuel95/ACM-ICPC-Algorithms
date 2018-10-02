a=input().split()
print("Enter number you want to check:")
x=int(input())
f,s=0,0
flag=0
for i in range(len(a)):
    for j in range(i+1,len(a)):
        if(x==int(a[i])+int(a[j])):
            f,s=i,j
            flag=1
            break

    if(flag==1):
        break
if(flag==1):
    print(f,s)
else:
    print('Sum not found')

