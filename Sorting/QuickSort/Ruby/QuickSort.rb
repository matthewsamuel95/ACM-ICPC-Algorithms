def partition(array, low, high)
    pivot = array[high] # Selecting the last element of the array as the pivot element
    
    idx = low - 1 # Rightful index of the pivot element

    for counter in low..high
        if array[counter] < pivot
            idx = idx + 1
            array[counter], array[idx] = array[idx], array[counter]
        end
    end
    array[idx+1], array[high] = array[high], array[idx+1]
    return idx + 1
end

def quick_sort(array, low, high)
    if low < high
        idx = partition(array, low, high) # The partition index
        quick_sort(array, low, idx-1)
        quick_sort(array, idx+1, high)
    end
end

# Dummy data for testing 
test_array = [7, 6, 5, 4, 3, 2, 1]
# Display unsorted array
puts "Unsorted Array:"
puts test_array.join(' ')
# Perform quick sort
quick_sort(test_array, 0, 6)
# Display the sorted results 
puts "Post QuickSort"
puts test_array.join(' ')
