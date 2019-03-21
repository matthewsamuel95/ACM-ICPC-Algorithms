def print_pairs(arr, sum):
  s = set()

  for i in range(0, len(arr)):
    temp = sum - arr[i]
    if temp >= 0 and temp in s:
      print("Pair with the given sum is", arr[i], "and", temp)
    s.add(arr[i])


if __name__ == "__main__":
  arr = [1, 4, 45, 6, 10, 8]
  n = 16
  print_pairs(arr, n)
