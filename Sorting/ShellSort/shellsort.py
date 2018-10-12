def shellSort(arr): 
    n = len(arr) 
    gap = n/2
    while gap > 0: 
        for i in range(gap,n): 
            temp = arr[i] 
            j = i 
            while  j >= gap and arr[j-gap] >temp: 
                arr[j] = arr[j-gap] 
                j -= gap 
            arr[j] = temp 
        gap /= 2
  
arr = [ 9,34,1,33,98,12,304,200]   
n = len(arr) 
print ("Array before sorting:") 
for i in range(n): 
    print(arr[i]), 
  
shellSort(arr) 
for i in range(n): 
    print(arr[i]), 
