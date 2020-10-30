def count_ones(n):
    count = 0
    n=bin(n).split('b')[1]
    count=n.count('1')
    return count


if __name__ == '__main__':
    number = int(input("Enter an integer: "))
    print("One Count: %d" % count_ones(number))
