#Cocktail Shaker Sort function
def cocktail_shaker_sort(array):
    swapped = True

    #Initialize first element to 0 and last element to n-1
    first = 0
    last = len(array) - 1

    while swapped:
        swapped = False

        #Forward pass
        for i in range(first,last):
            if array[i] > array[i+1]:
                array[i], array[i+1] = array[i+1], array[i]
                swapped = True

        #If there are no swaps, then array is sorted
        if not swapped:
            break

        last -= 1
        swapped = False

        #Backward pass
        for i in range(last,first,-1):
            if array[i] < array[i-1]:
                array[i], array[i-1] = array[i-1], array[i]
                swapped = True

        first += 1

if __name__ == "__main__":
    array = [1,2,9,1,2,10,6,3,6,8,0]
    print(array)
    cocktail_shaker_sort(array)
    print(array)
