import math
def jump_search(arr,search):

    j_block = len(arr)
    low = 0
    interval = int(math.sqrt(j_block))
    for i in range(0,j_block,interval):
        if arr[i] < search:
            low = i
        elif arr[i] == search:
            return i
        else:
            break # bigger number is found
    c=low
    for j in arr[low:]:
        if j==search:
            return c
        c+=1
    return "Not found"

arr = [ 0, 1, 1, 2, 3, 5, 8, 13, 21,34, 55, 89, 144, 233, 377, 610 ] 

search_block = 55    
res = jump_search(arr, search_block)
print("Number" , search_block, "is at index" ,"%.0f"%res)
