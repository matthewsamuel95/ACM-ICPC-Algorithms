'''
    Author: Prateek Sharma
'''


import math


# To find semi primes:
def check_semi_prime(num1):
    cnt = 0
    n = int(math.sqrt(num1))
    for i in range(2, n + 1):
        while num1 % i == 0:
            num1 /= i
            cnt += 1
            if cnt >= 2:
                break
    if num1 >= 1:
        cnt += 1
    return cnt == 2


T = int(input())
for m in range(T):
    N = int(input())
    s = " "
    p = False
    for num in range(2, N):
        if check_semi_prime(num):
            s = f"{s} {str(num)}"
    s = list(map(int, s.split()))
    for i in range(len(s)):
        for j in range(i, len(s)):
            if s[i] + s[j] == N:
                p = True
    if p:
        print("YES")
    else:
        print("NO")
