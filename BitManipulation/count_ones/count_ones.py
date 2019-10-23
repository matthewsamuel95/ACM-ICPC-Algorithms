def count_ones(n: int):
    count = 0
    while n:
        if n & 1:
            count += 1
        n >>= 1
    return count


if __name__ == '__main__':
    number = int(input("Enter an integer: "))
    print("One Count: %d" % count_ones(number))
