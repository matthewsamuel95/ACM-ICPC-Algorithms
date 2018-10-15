def find_triplet(arr):
    found = False
    n = len(arr)
    for i in range(n - 1):
        set_val = set()
        for j in range(i + 1, n):
            x = -(arr[i] + arr[j])
            if x in set_val:
                print('{} {} {}'.format(x, arr[i], arr[j]))
                found = True
            else:
                set_val.add(arr[j])

    if not found:
        print('No triplet found!')


# Driver program to test above function
if __name__ == '__main__':
    arr = [0, -1, 2, -3, 1]
    find_triplet(arr)
