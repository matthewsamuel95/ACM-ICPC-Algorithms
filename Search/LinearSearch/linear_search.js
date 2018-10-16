// The function takes an array and the element as input
// Returns the position if the element is found
// Otherwise, returns -1
function linear_search(array, element) {
  const n = array.length;
  for (i = 0; i < n; i++) {
    if (array[i] == element)
      return i;
  }
  return -1;
}


const arr = [4, 12, 7, 90, 88, 14];
const element = 90;
const position = linear_search(arr, element);

if (position == -1)
  console.log("Element not found!");
else
  console.log("Element found at: " + position);
