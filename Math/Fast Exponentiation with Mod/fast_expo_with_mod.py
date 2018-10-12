def fast_mult_modulo(a, x, m):
    ''' returns a^x % m '''
    ans = 1
    while x > 0:
        if x & 1:
            ans = (ans * a) % m
        a = (a * a) % m
        x //= 2
    return ans


if __name__ == '__main__':
    # testing: should return 445
    print(fast_mult_modulo(1337, 65537, 2714))
