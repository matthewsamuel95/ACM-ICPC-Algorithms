def reverse_32_bit(n):
    n=bin(n).split('b')[1]
    if len(n)<32:
        temp=32-len(n)
        s=''
        for i in range(temp):
            s+='0'
        n=s+n
    n=n[::-1]
    return int(n,2)

for _ in range(int(input())):
    n=int(input())
    result=reverse_32_bit(n)
    print(result)
