class MergeSort
  def divide_and_conquer(nums)
    divide(nums)
  end

  def divide(nums)
    return nums if nums.size <= 1
    size = nums.size
    mid = size / 2 - 1
    left = nums[0..mid]
    right = nums[(mid + 1)..(size - 1)]

    merge(divide(left), divide(right))
  end

  # a, b are array
  def merge(a, b)
    result = []
    while(a.size > 0 && b.size > 0) do
      value_a = a.first
      value_b = b.first

      if value_a < value_b
        result << value_a
        a.shift
      else
        result << value_b
        b.shift
      end
    end

    result + a + b
  end
end

list = [2, 5, 1, 3, 7, 2, 3, 8, 6, 3]
p "Original:  #{list}"
p "Sorted:  #{MergeSort.new.divide(list)}"
