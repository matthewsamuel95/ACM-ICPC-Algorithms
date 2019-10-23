def binary_search(A,x):
    start = 0        # This variable represents the beginning index that will reference the search
    end = len(A)-1   # This one represents the ending index
    
    while start <= end:
        mdl = (start+end)//2  # This variable represents the index of the middle of the list

        if A[mdl] < x :
            start = mdl + 1
        elif A[mdl] > x:
            end = mdl - 1
        else:
            return mdl
    return None

x = 5110

arr = [2, 14, 19, 21, 99, 210, 512, 1028, 4443, 5110]

binary_search(arr,x)
