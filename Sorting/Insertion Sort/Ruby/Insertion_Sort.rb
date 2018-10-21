def insertion_sort(array)
    for i in 1..(array.length-1)
        key = array[i]
        j = i-1
        while j >= 0 and key < array[j]
            array[j+1] = array[j]
            j = j - 1
        end
        array[j+1] = key
    end
end


# Dummy data for testing 
test_array = [7, 6, 5, 4, 3, 2, 1]
# Display unsorted array
puts "Unsorted Array:"
puts test_array.join(' ')
# Perform insertion sorting
insertion_sort(test_array)
# Display the sorted results 
puts "Post Insertion Sort"
puts test_array.join(' ')
