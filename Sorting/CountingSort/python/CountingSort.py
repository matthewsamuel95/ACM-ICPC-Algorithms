def countingSort(arr, k):
    m = k + 1
    count = [0] * m

    for a in arr:
    # count occurences
        count[a] += 1
    i = 0
    for a in range(m):
        for c in range(count[a]):
            arr[i] = a
            i += 1
    return arr
testArray = [473, 78, 92, 5, 18, 7, 65, 89]
print("Before: " + str(testArray))
sortedArray = countingSort(testArray, 474)
print("After: " + str(testArray))
