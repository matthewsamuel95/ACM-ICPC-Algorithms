/*
 * Example
 */
arr = [1,4,3,-0,-9,12];
heapSort(arr);
console.log(arr);

/*
 * Swap array elements
 */
function swap(arr, firstItemIndex, lastItemIndex) {
  var temp = arr[firstItemIndex];
  arr[firstItemIndex] = arr[lastItemIndex];
  arr[lastItemIndex] = temp;
}

/*
 * Sort elements by comparing values
 */
function heapify(arr, i, max) {
  var index, leftChild, rightChild;

  while (i < max) {
    index = i;
    leftChild = 2 * i + 1;
    rightChild = leftChild + 1;

    if (leftChild < max && arr[leftChild] > arr[index]) {
      index = leftChild;
    }

    if (rightChild < max && arr[rightChild] > arr[index]) {
      index = rightChild;
    }

    if (index === i) {
      return;
    }

    swap(arr, i, index);

    i = index;
  }
}

/*
 * convert list in to max heap 
 */
function buildMaxHeap(arr) {
  var i;
  i = arr.length / 2 - 1;
  i = Math.floor(i);

  while (i >= 0) {
    heapify(arr, i, arr.length);
    i -= 1;
  }
}


/*
 * Steps for heap sort
 */
function heapSort(arr) {
  buildMaxHeap(arr);
  lastElement = arr.length - 1;

  while (lastElement > 0) {
    swap(arr, 0, lastElement);
    heapify(arr, 0, lastElement);
    lastElement -= 1;
  }
}
