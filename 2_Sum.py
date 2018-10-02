#This function takes array and target as input and return index in list form.
#Code will run in python3 environment
def two_sum( arr, target):
    arr1 = {target-arr[i]:i for i in range(len(arr))}
    for i in range(len(arr)):
        if arr[i] in arr1 and i!=arr1[arr[i]]:
            return [i,arr1[arr[i]]]
arr= [2, 7, 11, 15]
target = 9
print(two_sum(arr, target))
