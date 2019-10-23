'''

 Bottom up Approach for Fibonacci series

'''

N = int(input())


def fib(n):
    if (n == 0):
        return 0
    elif (n == 1):
        return 1
    else:
        fib = [0, 1]
        for i in range(2, n + 1):
            fib.append(fib[i - 2] + fib[i - 1])
        return fib[i]


print(fib(N))
