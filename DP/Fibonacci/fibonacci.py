# DP Approach for Fibonacci series

ans = dict()


def fibo(i):
    global ans
    if i == 1:
        return 0
    elif i == 2:
        return 1
    elif i in ans:
        # print('found:', i, '=>', ans[i])
        return ans[i]
    else:
        r = fibo(i - 1) + fibo(i - 2)
        ans[i] = r
        return r


index = int(input('enter the index?'))
print(fibo(index))
