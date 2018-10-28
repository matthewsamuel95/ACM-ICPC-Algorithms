def set_kth_bit(n, k):
    # set kth bit of n
    return (1 << k) | n

if __name__ == "__main__":
    n, k = map(int, input().split())
    print(set_kth_bit(n, k))
