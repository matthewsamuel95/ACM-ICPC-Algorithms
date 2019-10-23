def is_sparse(n):
    # a number n is sparse if there are no two
    # adjacent 1's in its binary representation
    # ex: 5 (101) is sparse, but 6 (110) is not
    # Therefore, a sparse number when shifted one position
    # will have no collapsing 1's on an AND operation
    return not n & (n>>1)


if __name__ == "__main__":
    n = int(input())
    print(is_sparse(n))
