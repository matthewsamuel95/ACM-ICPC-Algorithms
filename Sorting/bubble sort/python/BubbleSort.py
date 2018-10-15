def bubbleSort(arr):
    swap = True
    while swap:
        swap = False
        for i in range(len(arr) - 1):
            if arr[i] > arr[i + 1]:
                x = arr[i]
                arr[i] = arr[i + 1]
                arr[i + 1] = x
                swap = True


if __name__ == "__main__":
    arr = [10, -43, 21, 0, 4, 67, 5, 3, 10]
    bubbleSort(arr)
    print(arr)
