# get the number of elements in array
number_of_elements = int(input())

# input array
array = list(map(int, input().split()))

# get the maximum number in array
# use that number as maximum possible index
arr = [-1] * (max(array) + 1)

# map the array in secondery array
for e in array:
    arr[e] += 1

# printing the sorted arrey
for index, e in enumerate(arr):
    # print the number only it was found in the array
    if e != -1:

        for _ in range(e + 1):
            print(index, end=' ')
