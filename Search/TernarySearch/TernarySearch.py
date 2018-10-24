def ternarySearch (arr, l, r, x):
    if r >= l:
        mid1 = int(l + (r-l)/3)
        mid2 = int(r - (r-l)/3 )
        #print(mid1)

        # If x is present at the mid1 
        if (arr[mid1] == x):  
            return mid1 
  
        # If x is present at the mid2 
        if (arr[mid2] == x):  
            return mid2
  
        # If x is present in left one-third 
        if (arr[mid1] > x): 
            return ternarySearch(arr, l, mid1-1, x)

        # If x is present in right one-third 
        if (arr[mid2] < x): 
            return ternarySearch(arr, mid2+1, r, x) 
  
        # If x is present in middle one-third 
        return ternarySearch(arr, mid1+1, mid2-1, x) 
    # We reach here when element is not present in array 
    return -1 

print("Enter the array")
arr = list(map(int, input().strip().split()))
print("Enter element to be searched")
x = int(input())
result = ternarySearch(arr, 0, len(arr)-1, x)
if result != -1:
    print("Element found at index ", result, end = " ")
else:
    print("Element not found")