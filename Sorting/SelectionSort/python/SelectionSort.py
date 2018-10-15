# Selection Sort: Find the minimum value at each pass and move it
# to the beginning


def SelectionSort(arr):
    for i in range(len(arr)):
        minValueIndex = i

        for j in range(i, len(arr)):
            if arr[j] < arr[minValueIndex]:
                minValueIndex = j

        arr[i], arr[minValueIndex] = arr[minValueIndex], arr[i]
    return arr


if __name__ == "__main__":
    arr = [1, 5, 7, 2, 8, 3]
    print(SelectionSort(arr))  # [1, 2, 3, 5, 7, 8]
