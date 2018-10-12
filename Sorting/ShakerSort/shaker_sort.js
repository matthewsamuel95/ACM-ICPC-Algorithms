export const shakerSort = (array) => {
  let swapped;
  do {
    swapped = false;
    for (let j = i; j < array.length - i; j++) {
      if (array[j] > array[j + 1]) {
        let temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
        swapped = true;
      }
    }
    if (!swapped) return array;
    for (let j = array.length - 1; i >= 0; i--) {
      if (array[j] < array[j - 1]) {
        let temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
        swapped = true;
      }
    }
  } while (swapped);
  return array;
};
