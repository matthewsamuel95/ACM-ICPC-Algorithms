# Comb Sort is mainly an improvement over Bubble Sort. Bubble sort always
# compares adjacent values. So all inversions are removed one by one. Comb Sort
# improves on Bubble Sort by using gap of size more than 1. The gap starts with
# a large value and shrinks by a factor of 1.3 in every iteration until it
# reaches the value 1. Thus Comb Sort removes more than one inversion counts
# with one swap and performs better than Bublle Sort.
#
# More on: https://www.geeksforgeeks.org/comb-sort/
# Illustration gif: https://upload.wikimedia.org/wikipedia/commons/4/46/Comb_sort_demo.gif

def combsort(array, shrink = 1.247330950103979)
  sorted = array.dup
  gap = array.size
  swapped = false

  until gap == 1 && !swapped
    gap = (gap / shrink).to_i
    gap = 1 if gap < 1

    swapped = false

    gap.upto(sorted.size - 1) do |i|
      next if sorted[i - gap] <= sorted[i]

      sorted[i - gap], sorted[i] = sorted[i], sorted[i - gap]
      swapped = true
    end
  end

  sorted
end

# Test case
if $PROGRAM_NAME == __FILE__
  unsorted = Array.new(20) { rand(10_000) }
  sorted = combsort(unsorted)
  puts "Sorting: #{unsorted}"
  puts "Sorted:  #{sorted}"
  puts "Correct? #{sorted == unsorted.sort}"
end
