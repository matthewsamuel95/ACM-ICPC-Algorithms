def bubble_sort(array)
    size = array.length
    for i in 0..(size-1)
        for j in 0..(size-2-i)
            if array[j] > array[j+1]
                array[j], array[j+1] = array[j+1], array[j]
            end
        end
    end
end

# Dummy data for testing 
test_array = [7, 6, 5, 4, 3, 2, 1]
# Display unsorted array
puts "Unsorted Array:"
puts test_array.join(' ')
# Call heap sort on the array
bubble_sort(test_array)
# Display the sorted results 
puts "Post Bubble Sort"
puts test_array.join(' ')