def binarySearch(ls,target):
    start = 0
    end = len(ls)-1     

    while(start<=end):
        mid = int((start+end)/2)
        if target>ls[mid]:
            start = mid+1
        elif target<ls[mid]:
            end = mid - 1
        else:
            return mid
    return None

if __name__ =="__main__":
    data = [1,5,6,9,11,20,50,900,1700]
    index = binarySearch(data,900)
    print(index)
