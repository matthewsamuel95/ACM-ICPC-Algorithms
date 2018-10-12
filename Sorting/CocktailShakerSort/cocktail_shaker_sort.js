function swap(array) { // create a swap function specific to an array
  return function (x, y) {
    var value = array[x];
    array[x] = array[y];
    array[y] = value;
  };
}

function cocktail_shaker_sort(array) {
  var _swap = swap(array); // when given x and y swap elements in this array
  var swapped = false;
  var last = array.length - 1;
  var first = 0;
  do {
    for (var i = first; i < last; i++) {
      if (array[i] > array[i + 1]) { // test whether the two elements are in the wrong order
        _swap(i, i + 1); // let the two elements change places
        swapped = true;
      }
    }
    if (!swapped) break; // we can exit the outer loop here if no swaps occurred.
    swapped = false;
    last--; // the last element is already sorted
    for (var i = last; i > first; i--) {
      if (array[i] < array[i - 1]) { // test whether the two elements are in the wrong order
        _swap(i, i - 1); // let the two elements change places
        swapped = true;
      }
    }
    first++; // the first element is already sorted
  } while (swapped); // if no elements have been swapped, then the list is sorted
}
