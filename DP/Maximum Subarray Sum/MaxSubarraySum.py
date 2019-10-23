def func(a, size):

    max_so_far =a[0]
    curr_max = a[0]

    for i in range(1,size):
        curr_max = max(a[i], curr_max + a[i])
        max_so_far = max(max_so_far,curr_max)

    return max_so_far

if __name__ == "__main__":
    n = input()
    ls = map(int, raw_input().split())

    print func(ls,n)

'''
INPUT
5
10 8 -9 -8 58

OUTPUT
59
'''
