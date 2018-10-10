def fibonacci_search(arr, x, n):
    """
    Returns index of x if present, else returns -1
    :param arr:
    :param x:
    :param n:
    :return:
    """
    fib2 = 0   # (m-2)'th Fibonacci No.
    fib1 = 1   # (m-1)'th Fibonacci No.
    fib = fib2 + fib1   # m'th Fibonacci

    while fib < n:
        fib2 = fib1
        fib1 = fib
        fib = fib2 + fib1

    offset = -1
    while fib > 1:
        # to get a valid index
        i = min(offset + fib2, n - 1)

        if arr[i] < x:
            fib = fib1
            fib1 = fib2
            fib2 = fib - fib1
            offset = i

        elif arr[i] > x:
            fib = fib2
            fib1 = fib1 - fib2
            fib2 = fib - fib1

        else:
            return i

    if fib1 and arr[offset + 1] == x:
        return offset + 1

    # element not found. return -1
    return -1


if __name__ == "__main__":
    n = int(input("Enter the number of elements: "))
    print("Enter the elements each line")
    arr = []
    for i in range(n):
        arr.append(int(input()))
    x = int(input("Enter element to be searched: "))
    idx = fibonacci_search(arr, x, n)
    if idx == -1:
        print("Element not found!")
    else:
        print("Element found at position: "+str(idx+1))
