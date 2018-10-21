// Function Bubble sort
// Description: It takes an array an returns that array in ascendent order
// Complexity: O(2^n)
function bubbleSort(array) {
  // We make a loop to repeat the ordering process until all the elements are ordered
  let unordered = true;
  while(unordered) {
    unordered = false;
    //We iterate through the whole array, comparing each element with the following
    // We have to stop at the second to last element so we don't have an out of bounds error
    for(let j = 0; j<array.length-1; j++) {
      // We compare each element with the following and if they are unordered we swap them
      if(array[j] > array[j+1]) {
        const aux = array[j+1];
        array[j+1] = array[j];
        array[j] = aux;
        //If we have made changes to the array we set unordered to true so we continue with the loop
        unordered = true
      }
    }
  }
  return array
}

const example = [2,54,12,3,5]
const orderedExample = bubbleSort(example);
console.log(orderedExample); // [2,3,5,12,54]