-- Bubble sort (also known as sinking sort) is a simple sorting algorithm that
-- repeatedly steps through the list to be sorted, compares each pair of
-- adjacent items and swaps them if they are in the wrong order. The pass
-- through the list is repeated until no swaps are needed, which indicates that
-- the list is sorted.

local function bubblesort(t)
  repeat
    local sorted = true
    for i=2, #t do
      if (t[i-1] > t[i]) then
        t[i-1], t[i] = t[i], t[i-1]
        sorted = false
      end
    end
  until sorted
end

local numbers = {5, 1, 4, 2, 8}
bubblesort(numbers)
for _, number in ipairs(numbers) do
  print(number)
end
